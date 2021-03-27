#include "pch.h"
#include "XamlViewManager.h"

#include "JSValueReader.h"
#include "NativeModules.h"
#include "XamlMetadata.h"
#include <winrt/Windows.UI.Xaml.Core.Direct.h>
#include <UI.Xaml.Input.h>
#include <UI.Xaml.Documents.h>
#include "JSI/JsiApiContext.h"

#include "Styling.h"

using namespace winrt;
using namespace Microsoft::ReactNative;
using namespace xaml;
using namespace xaml::Controls;
namespace jsi = facebook::jsi;

namespace winrt::ReactNativeXaml {

  struct XamlObject : std::enable_shared_from_this<XamlObject>, facebook::jsi::HostObject {

    jsi::Value get(jsi::Runtime&rt, const jsi::PropNameID& nameId) override {
      auto name = nameId.utf8(rt);
      if (name == "prop1") {
        return jsi::Value(42);
      }
      return jsi::HostObject::get(rt, nameId);
    }
    void set(jsi::Runtime& rt, const jsi::PropNameID& name, const jsi::Value& value) override {

    }
    std::vector<jsi::PropNameID> getPropertyNames(jsi::Runtime& rt) override {
      //auto prop1 = jsi::PropNameID::forAscii(rt, "prop1");
      return jsi::PropNameID::names({ jsi::PropNameID::forAscii(rt, "prop1") });
    }
  };


  void XamlViewManager::EnsureJsi() {
    bool init = false;

    ExecuteJsi(m_reactContext, [](facebook::jsi::Runtime& rt) {
      auto obj = rt.global().createFromHostObject(rt, std::make_shared<XamlObject>());
      rt.global().setProperty(rt, jsi::PropNameID::forAscii(rt, "xaml"), obj);
      //auto xamlObjectName2 = m_jsi.CreatePropertyId(L"xaml2");
      ////auto xamlObject =  m_jsi.CreateStringFromAscii("hello from jsi");
      //auto foo = m_jsi.CreateValueFromJson(LR"({"value":42})");
      //m_jsi.SetProperty(m_jsi.Global(), xamlObjectName2, { JsiValueKind::Object, foo.Data });
      });
  }

  void JsiDispatchEvent(jsi::Runtime& rt, int64_t viewTag, std::string&& eventName, std::shared_ptr<XamlObject>& eventData) noexcept {
    auto params = jsi::Array(rt, 3);
    params.setValueAtIndex(rt, 0, static_cast<int>(viewTag));
    params.setValueAtIndex(rt, 1, eventName);
    auto obj = rt.global().createFromHostObject(rt, eventData);
    params.setValueAtIndex(rt, 2, obj);

    auto batchedBridge = rt.global().getPropertyAsObject(rt, "__fbBatchedBridge");
    
    auto callFunctionReturnFlushedQueue_ = batchedBridge.getPropertyAsFunction(
      rt, "callFunctionReturnFlushedQueue"); 

    callFunctionReturnFlushedQueue_.call(rt, "RCTEventEmitter", "receiveEvent", params);
    /*.getPropertyNames(rt);
    auto len = v.length(rt);
    for (auto i = 0; i < len; i++) {
      auto name = v.getValueAtIndex(rt, i).asString(rt).utf8(rt);
      OutputDebugStringA(name.c_str());
      OutputDebugStringA("\n");
    }*/
    /*
    auto react = rt.global().getPropertyAsObject(rt, "React");
    auto emitter = react.getPropertyAsObject(rt, "RCTEventEmitter");
    auto receiveEvent = emitter.getPropertyAsFunction(rt, "receiveEvent");
    receiveEvent.call(rt, params);
    */
  }

  // IViewManager
  hstring XamlViewManager::Name() noexcept {
    return L"XamlControl";
  }

  xaml::FrameworkElement XamlViewManager::CreateView() noexcept {
    assert(false);
    return nullptr;
  }

  winrt::IInspectable XamlViewManager::CreateViewWithProperties(winrt::Microsoft::ReactNative::IJSValueReader const& propertyMapReader) noexcept {
    EnsureJsi();
    const JSValueObject& propertyMap = JSValue::ReadObjectFrom(propertyMapReader);
    auto typeName = propertyMap["type"].AsString();
    auto e = xamlMetadata.Create(typeName, m_reactContext);


    if (typeName == "Windows.UI.Xaml.Controls.Button") {
      auto b = e.as<xaml::Controls::Button>();
      b.PointerEntered([ctx = m_reactContext](auto&& sender, auto&&) {
        auto _b = sender.as<xaml::Controls::Button>();
        auto tag = winrt::unbox_value<int64_t>(_b.Tag());

        ExecuteJsi(ctx, [tag](jsi::Runtime& rt) {
          auto obj = std::make_shared<XamlObject>();
          JsiDispatchEvent(rt, tag, "topClick", obj);
          });
        });
    }
    return e;
  }

  void SetResources(const xaml::FrameworkElement& fe, const JSValueObject& dict) {
    ResourceDictionary rd;

    for (auto const& entry : dict) {
      const auto& name = entry.first;
      const auto& value = entry.second;
      auto brush = ColorUtils::BrushFrom(value);
      auto nameII = winrt::box_value(winrt::to_hstring(name));
      rd.Insert(nameII, brush);
      if (auto v = rd.TryLookup(nameII)) {
        if (auto scb = v.try_as<xaml::Media::SolidColorBrush>()) {
          if (auto newScb = brush.try_as<xaml::Media::SolidColorBrush>()) {
            scb.Color(newScb.Color());
            continue;
          }
          else {
            assert(false && "changing from a color to a non-color brush");
          }
        }
        else {
          assert(false && "changing from a non-color brush");
        }
      }
    }
    fe.Resources(rd);
  }

  // IViewManagerWithNativeProperties
  IMapView<hstring, ViewManagerPropertyType> XamlViewManager::NativeProps() noexcept {
    auto nativeProps = winrt::single_threaded_map<hstring, ViewManagerPropertyType>();
    nativeProps.Insert(L"type", ViewManagerPropertyType::String);
    nativeProps.Insert(L"resources", ViewManagerPropertyType::Map);
    xamlMetadata.PopulateNativeProps(nativeProps);
    xamlMetadata.PopulateNativeEvents(nativeProps);
    return nativeProps.GetView();
  }

  void XamlViewManager::UpdateProperties(
    FrameworkElement const& view,
    IJSValueReader const& propertyMapReader) noexcept {

    EnsureJsi();
    const JSValueObject& propertyMap = JSValue::ReadObjectFrom(propertyMapReader);

    auto e = view;
    if (auto control = e.try_as<DependencyObject>()) {
      for (auto const& pair : propertyMap) {
        bool handled = false;
        auto const& propertyName = pair.first;
        auto const& propertyValue = pair.second;

        auto cn = get_class_name(e);
        if (auto prop = xamlMetadata.GetProp(propertyName, control)) {
          auto realObject = prop->asType(control).as<DependencyObject>();
          auto rcn = get_class_name(realObject);
          prop->SetValue(realObject, propertyValue);
          handled = true;
        }
        else if (auto eventAttacher = xamlMetadata.AttachEvent(m_reactContext, propertyName, control, propertyValue.AsBoolean())) {
        }
        else if (propertyName == "type") {}
        else if (propertyName == "resources" && propertyValue.Type() == JSValueType::Object && control.try_as<xaml::FrameworkElement>()) {
          SetResources(control.as<xaml::FrameworkElement>(), propertyValue.AsObject());
        }
        else {
          auto className = winrt::get_class_name(e);
          assert(false && "unknown property");
        }
      }
    }
  }

  // IViewManagerWithExportedEventTypeConstants
  ConstantProviderDelegate XamlViewManager::ExportedCustomBubblingEventTypeConstants() noexcept {
    return nullptr;
  }

  ConstantProviderDelegate XamlViewManager::ExportedCustomDirectEventTypeConstants() noexcept {
    return GetEvents;
  }

  // IViewManagerWithCommands
  IVectorView<hstring> XamlViewManager::Commands() noexcept {
    auto commands = winrt::single_threaded_vector<hstring>();
    commands.Append(L"CustomCommand");
    return commands.GetView();
  }

  void XamlViewManager::DispatchCommand(
    FrameworkElement const& view,
    winrt::hstring const& commandId,
    winrt::Microsoft::ReactNative::IJSValueReader const& /*commandArgsReader*/) noexcept {
    if (auto control = view.try_as<winrt::Windows::UI::Xaml::Controls::HyperlinkButton>()) {
      if (commandId == L"CustomCommand") {
        // const JSValueArray& commandArgs = JSValue::ReadArrayFrom(commandArgsReader);
        // Execute command
      }
    }
  }

  // IViewManagerWithReactContext
  IReactContext XamlViewManager::ReactContext() noexcept {
    return m_reactContext;
  }

  void XamlViewManager::ReactContext(IReactContext reactContext) noexcept {
    m_reactContext = reactContext;
  }

  void XamlViewManager::AddView(xaml::FrameworkElement parent, xaml::UIElement child, int64_t _index) {
    auto index = static_cast<uint32_t>(_index);

    auto e = parent;
    auto parentType = winrt::get_class_name(e);
    auto childType = winrt::get_class_name(child);
    if (child.try_as<xaml::Controls::Primitives::SelectorItem>() ||
      child.try_as<NavigationView>()) { 
      // these are ContentControls too, but we shouldn't try to unwrap, so skip this 
    } else if (auto childAsCC = child.try_as<Wrapper>()) {
      auto childContent = childAsCC.Content();
      childType = winrt::get_class_name(childContent);
      auto tag = childAsCC.Tag();
      if (auto depObj = childContent.try_as<DependencyObject>()) {
        // tranfer the Tag from the wrapping ContentControl
        // This is used for dispatching events and TouchEventHandler
        depObj.SetValue(FrameworkElement::TagProperty(), tag);
      }

      if (auto childFlyout = childContent.try_as<Controls::Primitives::FlyoutBase>()) {
        Primitives::FlyoutBase::SetAttachedFlyout(e, childFlyout);
        childAsCC.DataContext(e);
        if (auto button = e.try_as<Button>()) {
          return button.Flyout(childFlyout);
        }
        else {
          if (auto uiParent = e.try_as<UIElement>()) {
            return uiParent.ContextFlyout(childFlyout);
          }
        }
      }
      else if (auto RTBparent = parent.try_as<RichTextBlock>()) {
        if (auto childBlock = childContent.try_as<Documents::Block>()) {
          return RTBparent.Blocks().InsertAt(index, childBlock);
        }
      }
      else if (auto TBparent = parent.try_as<TextBlock>()) {
        if (auto childInline = childContent.try_as<Documents::Inline>()) {
          return TBparent.Inlines().InsertAt(index, childInline);
        }
      }
      else if (auto paragraphParent = Unwrap<Documents::Paragraph>(parent)) {
        if (auto childInline = childContent.try_as<Documents::Inline>()) {
          return paragraphParent.Inlines().InsertAt(index, childInline);
        }
      }
      else if (auto spanParent = Unwrap<Documents::Span>(parent)) {
        if (auto childInline = childContent.try_as<Documents::Inline>()) {
          return spanParent.Inlines().InsertAt(index, childInline);
        }
      }
    }


    if (auto panel = e.try_as<Panel>()) {
      return panel.Children().InsertAt(index, child);
    }
    else if (auto navView = e.try_as<NavigationView>()) {
      auto childCN = winrt::get_class_name(child);
      return navView.MenuItems().InsertAt(index, child);
    }
    else if (auto contentCtrl = e.try_as<Wrapper>()) {
      auto parentContent = contentCtrl.Content();
      if (auto menuFlyout = parentContent.try_as<MenuFlyout>()) {
        if (auto mfi = child.try_as<MenuFlyoutItemBase>()) {
          return menuFlyout.Items().InsertAt(index, mfi);
        }
      }
      else if (auto flyout = parentContent.try_as<Flyout>()) {
        if (index == 0) {
          return flyout.Content(child);
        }
      }

      if (index == 0) {
        return contentCtrl.Content(child);
      }
    }
    else if (auto border = e.try_as<Border>()) {
      if (index == 0) {
        return border.Child(child);
      }
    }
    else if (auto itemsControl = e.try_as<ItemsControl>()) {
      return itemsControl.Items().InsertAt(index, child);
    }
    //else 
    {
      auto cn = winrt::get_class_name(e);
      assert(false && "this element cannot have children");
    }
  }

  void XamlViewManager::RemoveAllChildren(xaml::FrameworkElement parent) {
    auto e = parent;
    if (auto panel = e.try_as<Panel>()) {
      return panel.Children().Clear();
    }
    else if (auto contentCtrl = e.try_as<Wrapper>()) {
      return contentCtrl.Content(nullptr);
    }
    else if (auto border = e.try_as<Border>()) {
      return border.Child(nullptr);
    }
    else if (auto itemsControl = e.try_as<ItemsControl>()) {
      return itemsControl.Items().Clear();
    }
  }

  void XamlViewManager::RemoveChildAt(xaml::FrameworkElement parent, int64_t index) {
    auto e = parent;
    if (auto panel = e.try_as<Panel>()) {
      return panel.Children().RemoveAt(static_cast<uint32_t>(index));
    }
    else if (auto itemsControl = e.try_as<ItemsControl>()) {
      return itemsControl.Items().RemoveAt(static_cast<uint32_t>(index));
    }
    else if (index == 0) {
      if (auto contentCtrl = e.try_as<Wrapper>()) {
        return contentCtrl.Content(nullptr);
      }
      else if (auto border = e.try_as<Border>()) {
        return border.Child(nullptr);
      }
    }
  }

  void XamlViewManager::ReplaceChild(xaml::FrameworkElement parent, xaml::UIElement oldChild, xaml::UIElement newChild) {
    assert(false && "nyi");
  }
}
