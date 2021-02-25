#include "pch.h"
#include "XamlMetadata.h"
#include "Crc32Str.h"
#include <JSValueWriter.h>

/*************************************************************
THIS FILE WAS AUTOMATICALLY GENERATED, DO NOT MODIFY MANUALLY
**************************************************************/

#include <winrt/Windows.UI.Xaml.h>
#include <winrt/Windows.UI.Xaml.Controls.h>
#include <winrt/Windows.UI.Xaml.Controls.Primitives.h>
#include <winrt/Windows.UI.Xaml.Controls.Maps.h>

/////// Events


#define MAKE_EVENT(evtName, xamlType) \
        { #evtName, [](winrt::Windows::Foundation::IInspectable o, IReactContext reactContext) { \
          if (auto c = o.try_as<xamlType>()) {  \
            c.evtName([reactContext] (auto&& sender, auto&& /*args*/) { \
              if (sender) reactContext.DispatchEvent(sender.as<xaml::FrameworkElement>(), L"top" L#evtName, [](winrt::Microsoft::ReactNative::IJSValueWriter const& /*evtDataWriter*/) noexcept {}); \
            }); \
          } \
        } }

/*static*/ const EventInfo EventInfo::xamlEventMap[] = {
  MAKE_EVENT(LayoutUpdated, winrt::Windows::UI::Xaml::FrameworkElement),
  MAKE_EVENT(Loaded, winrt::Windows::UI::Xaml::FrameworkElement),
  MAKE_EVENT(SizeChanged, winrt::Windows::UI::Xaml::FrameworkElement),
  MAKE_EVENT(Unloaded, winrt::Windows::UI::Xaml::FrameworkElement),
  MAKE_EVENT(DataContextChanged, winrt::Windows::UI::Xaml::FrameworkElement),
  MAKE_EVENT(Loading, winrt::Windows::UI::Xaml::FrameworkElement),
  MAKE_EVENT(ActualThemeChanged, winrt::Windows::UI::Xaml::FrameworkElement),
  MAKE_EVENT(EffectiveViewportChanged, winrt::Windows::UI::Xaml::FrameworkElement),
  MAKE_EVENT(IsEnabledChanged, winrt::Windows::UI::Xaml::Controls::Control),
  MAKE_EVENT(FocusDisengaged, winrt::Windows::UI::Xaml::Controls::Control),
  MAKE_EVENT(FocusEngaged, winrt::Windows::UI::Xaml::Controls::Control),
  MAKE_EVENT(Closed, winrt::Windows::UI::Xaml::Controls::AppBar),
  MAKE_EVENT(Opened, winrt::Windows::UI::Xaml::Controls::AppBar),
  MAKE_EVENT(Closing, winrt::Windows::UI::Xaml::Controls::AppBar),
  MAKE_EVENT(Opening, winrt::Windows::UI::Xaml::Controls::AppBar),
  MAKE_EVENT(Click, winrt::Windows::UI::Xaml::Controls::Primitives::ButtonBase),
  MAKE_EVENT(Checked, winrt::Windows::UI::Xaml::Controls::Primitives::ToggleButton),
  MAKE_EVENT(Indeterminate, winrt::Windows::UI::Xaml::Controls::Primitives::ToggleButton),
  MAKE_EVENT(Unchecked, winrt::Windows::UI::Xaml::Controls::Primitives::ToggleButton),
  MAKE_EVENT(SuggestionChosen, winrt::Windows::UI::Xaml::Controls::AutoSuggestBox),
  MAKE_EVENT(TextChanged, winrt::Windows::UI::Xaml::Controls::AutoSuggestBox),
  MAKE_EVENT(QuerySubmitted, winrt::Windows::UI::Xaml::Controls::AutoSuggestBox),
  MAKE_EVENT(CalendarViewDayItemChanging, winrt::Windows::UI::Xaml::Controls::CalendarDatePicker),
  MAKE_EVENT(Closed, winrt::Windows::UI::Xaml::Controls::CalendarDatePicker),
  MAKE_EVENT(DateChanged, winrt::Windows::UI::Xaml::Controls::CalendarDatePicker),
  MAKE_EVENT(Opened, winrt::Windows::UI::Xaml::Controls::CalendarDatePicker),
  MAKE_EVENT(CalendarViewDayItemChanging, winrt::Windows::UI::Xaml::Controls::CalendarView),
  MAKE_EVENT(SelectedDatesChanged, winrt::Windows::UI::Xaml::Controls::CalendarView),
  MAKE_EVENT(ColorChanged, winrt::Windows::UI::Xaml::Controls::ColorPicker),
  MAKE_EVENT(SelectionChanged, winrt::Windows::UI::Xaml::Controls::Primitives::Selector),
  MAKE_EVENT(DropDownClosed, winrt::Windows::UI::Xaml::Controls::ComboBox),
  MAKE_EVENT(DropDownOpened, winrt::Windows::UI::Xaml::Controls::ComboBox),
  MAKE_EVENT(TextSubmitted, winrt::Windows::UI::Xaml::Controls::ComboBox),
  MAKE_EVENT(DynamicOverflowItemsChanging, winrt::Windows::UI::Xaml::Controls::CommandBar),
  MAKE_EVENT(Closed, winrt::Windows::UI::Xaml::Controls::ContentDialog),
  MAKE_EVENT(Closing, winrt::Windows::UI::Xaml::Controls::ContentDialog),
  MAKE_EVENT(Opened, winrt::Windows::UI::Xaml::Controls::ContentDialog),
  MAKE_EVENT(PrimaryButtonClick, winrt::Windows::UI::Xaml::Controls::ContentDialog),
  MAKE_EVENT(SecondaryButtonClick, winrt::Windows::UI::Xaml::Controls::ContentDialog),
  MAKE_EVENT(CloseButtonClick, winrt::Windows::UI::Xaml::Controls::ContentDialog),
  MAKE_EVENT(DateChanged, winrt::Windows::UI::Xaml::Controls::DatePicker),
  MAKE_EVENT(SelectedDateChanged, winrt::Windows::UI::Xaml::Controls::DatePicker),
  MAKE_EVENT(Navigated, winrt::Windows::UI::Xaml::Controls::Frame),
  MAKE_EVENT(Navigating, winrt::Windows::UI::Xaml::Controls::Frame),
  MAKE_EVENT(NavigationFailed, winrt::Windows::UI::Xaml::Controls::Frame),
  MAKE_EVENT(NavigationStopped, winrt::Windows::UI::Xaml::Controls::Frame),
  MAKE_EVENT(DragItemsStarting, winrt::Windows::UI::Xaml::Controls::ListViewBase),
  MAKE_EVENT(ItemClick, winrt::Windows::UI::Xaml::Controls::ListViewBase),
  MAKE_EVENT(ContainerContentChanging, winrt::Windows::UI::Xaml::Controls::ListViewBase),
  MAKE_EVENT(ChoosingGroupHeaderContainer, winrt::Windows::UI::Xaml::Controls::ListViewBase),
  MAKE_EVENT(ChoosingItemContainer, winrt::Windows::UI::Xaml::Controls::ListViewBase),
  MAKE_EVENT(DragItemsCompleted, winrt::Windows::UI::Xaml::Controls::ListViewBase),
  MAKE_EVENT(Closed, winrt::Windows::UI::Xaml::Controls::HandwritingView),
  MAKE_EVENT(Opened, winrt::Windows::UI::Xaml::Controls::HandwritingView),
  MAKE_EVENT(SectionHeaderClick, winrt::Windows::UI::Xaml::Controls::Hub),
  MAKE_EVENT(SectionsInViewChanged, winrt::Windows::UI::Xaml::Controls::Hub),
  MAKE_EVENT(ImageFailed, winrt::Windows::UI::Xaml::Controls::Image),
  MAKE_EVENT(ImageOpened, winrt::Windows::UI::Xaml::Controls::Image),
  MAKE_EVENT(ActiveToolChanged, winrt::Windows::UI::Xaml::Controls::InkToolbar),
  MAKE_EVENT(EraseAllClicked, winrt::Windows::UI::Xaml::Controls::InkToolbar),
  MAKE_EVENT(InkDrawingAttributesChanged, winrt::Windows::UI::Xaml::Controls::InkToolbar),
  MAKE_EVENT(IsRulerButtonCheckedChanged, winrt::Windows::UI::Xaml::Controls::InkToolbar),
  MAKE_EVENT(IsStencilButtonCheckedChanged, winrt::Windows::UI::Xaml::Controls::InkToolbar),
  MAKE_EVENT(Checked, winrt::Windows::UI::Xaml::Controls::InkToolbarFlyoutItem),
  MAKE_EVENT(Unchecked, winrt::Windows::UI::Xaml::Controls::InkToolbarFlyoutItem),
  MAKE_EVENT(HorizontalSnapPointsChanged, winrt::Windows::UI::Xaml::Controls::ItemsPresenter),
  MAKE_EVENT(VerticalSnapPointsChanged, winrt::Windows::UI::Xaml::Controls::ItemsPresenter),
  MAKE_EVENT(CenterChanged, winrt::Windows::UI::Xaml::Controls::Maps::MapControl),
  MAKE_EVENT(HeadingChanged, winrt::Windows::UI::Xaml::Controls::Maps::MapControl),
  MAKE_EVENT(LoadingStatusChanged, winrt::Windows::UI::Xaml::Controls::Maps::MapControl),
  MAKE_EVENT(MapDoubleTapped, winrt::Windows::UI::Xaml::Controls::Maps::MapControl),
  MAKE_EVENT(MapHolding, winrt::Windows::UI::Xaml::Controls::Maps::MapControl),
  MAKE_EVENT(MapTapped, winrt::Windows::UI::Xaml::Controls::Maps::MapControl),
  MAKE_EVENT(PitchChanged, winrt::Windows::UI::Xaml::Controls::Maps::MapControl),
  MAKE_EVENT(TransformOriginChanged, winrt::Windows::UI::Xaml::Controls::Maps::MapControl),
  MAKE_EVENT(ZoomLevelChanged, winrt::Windows::UI::Xaml::Controls::Maps::MapControl),
  MAKE_EVENT(ActualCameraChanged, winrt::Windows::UI::Xaml::Controls::Maps::MapControl),
  MAKE_EVENT(ActualCameraChanging, winrt::Windows::UI::Xaml::Controls::Maps::MapControl),
  MAKE_EVENT(CustomExperienceChanged, winrt::Windows::UI::Xaml::Controls::Maps::MapControl),
  MAKE_EVENT(MapElementClick, winrt::Windows::UI::Xaml::Controls::Maps::MapControl),
  MAKE_EVENT(MapElementPointerEntered, winrt::Windows::UI::Xaml::Controls::Maps::MapControl),
  MAKE_EVENT(MapElementPointerExited, winrt::Windows::UI::Xaml::Controls::Maps::MapControl),
  MAKE_EVENT(TargetCameraChanged, winrt::Windows::UI::Xaml::Controls::Maps::MapControl),
  MAKE_EVENT(MapRightTapped, winrt::Windows::UI::Xaml::Controls::Maps::MapControl),
  MAKE_EVENT(MapContextRequested, winrt::Windows::UI::Xaml::Controls::Maps::MapControl),
  MAKE_EVENT(BufferingProgressChanged, winrt::Windows::UI::Xaml::Controls::MediaElement),
  MAKE_EVENT(CurrentStateChanged, winrt::Windows::UI::Xaml::Controls::MediaElement),
  MAKE_EVENT(DownloadProgressChanged, winrt::Windows::UI::Xaml::Controls::MediaElement),
  MAKE_EVENT(MarkerReached, winrt::Windows::UI::Xaml::Controls::MediaElement),
  MAKE_EVENT(MediaEnded, winrt::Windows::UI::Xaml::Controls::MediaElement),
  MAKE_EVENT(MediaFailed, winrt::Windows::UI::Xaml::Controls::MediaElement),
  MAKE_EVENT(MediaOpened, winrt::Windows::UI::Xaml::Controls::MediaElement),
  MAKE_EVENT(RateChanged, winrt::Windows::UI::Xaml::Controls::MediaElement),
  MAKE_EVENT(SeekCompleted, winrt::Windows::UI::Xaml::Controls::MediaElement),
  MAKE_EVENT(VolumeChanged, winrt::Windows::UI::Xaml::Controls::MediaElement),
  MAKE_EVENT(PartialMediaFailureDetected, winrt::Windows::UI::Xaml::Controls::MediaElement),
  MAKE_EVENT(ThumbnailRequested, winrt::Windows::UI::Xaml::Controls::MediaTransportControls),
  MAKE_EVENT(Click, winrt::Windows::UI::Xaml::Controls::MenuFlyoutItem),
  MAKE_EVENT(DisplayModeChanged, winrt::Windows::UI::Xaml::Controls::NavigationView),
  MAKE_EVENT(ItemInvoked, winrt::Windows::UI::Xaml::Controls::NavigationView),
  MAKE_EVENT(SelectionChanged, winrt::Windows::UI::Xaml::Controls::NavigationView),
  MAKE_EVENT(BackRequested, winrt::Windows::UI::Xaml::Controls::NavigationView),
  MAKE_EVENT(PaneClosed, winrt::Windows::UI::Xaml::Controls::NavigationView),
  MAKE_EVENT(PaneClosing, winrt::Windows::UI::Xaml::Controls::NavigationView),
  MAKE_EVENT(PaneOpened, winrt::Windows::UI::Xaml::Controls::NavigationView),
  MAKE_EVENT(PaneOpening, winrt::Windows::UI::Xaml::Controls::NavigationView),
  MAKE_EVENT(ContextMenuOpening, winrt::Windows::UI::Xaml::Controls::PasswordBox),
  MAKE_EVENT(PasswordChanged, winrt::Windows::UI::Xaml::Controls::PasswordBox),
  MAKE_EVENT(Paste, winrt::Windows::UI::Xaml::Controls::PasswordBox),
  MAKE_EVENT(PasswordChanging, winrt::Windows::UI::Xaml::Controls::PasswordBox),
  MAKE_EVENT(PivotItemLoaded, winrt::Windows::UI::Xaml::Controls::Pivot),
  MAKE_EVENT(PivotItemLoading, winrt::Windows::UI::Xaml::Controls::Pivot),
  MAKE_EVENT(PivotItemUnloaded, winrt::Windows::UI::Xaml::Controls::Pivot),
  MAKE_EVENT(PivotItemUnloading, winrt::Windows::UI::Xaml::Controls::Pivot),
  MAKE_EVENT(SelectionChanged, winrt::Windows::UI::Xaml::Controls::Pivot),
  MAKE_EVENT(HorizontalSnapPointsChanged, winrt::Windows::UI::Xaml::Controls::Primitives::CarouselPanel),
  MAKE_EVENT(VerticalSnapPointsChanged, winrt::Windows::UI::Xaml::Controls::Primitives::CarouselPanel),
  MAKE_EVENT(ValueChanged, winrt::Windows::UI::Xaml::Controls::Primitives::RangeBase),
  MAKE_EVENT(ColorChanged, winrt::Windows::UI::Xaml::Controls::Primitives::ColorSpectrum),
  MAKE_EVENT(SelectionChanged, winrt::Windows::UI::Xaml::Controls::Primitives::LoopingSelector),
  MAKE_EVENT(HorizontalSnapPointsChanged, winrt::Windows::UI::Xaml::Controls::Primitives::LoopingSelectorPanel),
  MAKE_EVENT(VerticalSnapPointsChanged, winrt::Windows::UI::Xaml::Controls::Primitives::LoopingSelectorPanel),
  MAKE_EVENT(HorizontalSnapPointsChanged, winrt::Windows::UI::Xaml::Controls::Primitives::OrientedVirtualizingPanel),
  MAKE_EVENT(VerticalSnapPointsChanged, winrt::Windows::UI::Xaml::Controls::Primitives::OrientedVirtualizingPanel),
  MAKE_EVENT(HorizontalSnapPointsChanged, winrt::Windows::UI::Xaml::Controls::Primitives::PivotPanel),
  MAKE_EVENT(VerticalSnapPointsChanged, winrt::Windows::UI::Xaml::Controls::Primitives::PivotPanel),
  MAKE_EVENT(Closed, winrt::Windows::UI::Xaml::Controls::Primitives::Popup),
  MAKE_EVENT(Opened, winrt::Windows::UI::Xaml::Controls::Primitives::Popup),
  MAKE_EVENT(Scroll, winrt::Windows::UI::Xaml::Controls::Primitives::ScrollBar),
  MAKE_EVENT(DragCompleted, winrt::Windows::UI::Xaml::Controls::Primitives::Thumb),
  MAKE_EVENT(DragDelta, winrt::Windows::UI::Xaml::Controls::Primitives::Thumb),
  MAKE_EVENT(DragStarted, winrt::Windows::UI::Xaml::Controls::Primitives::Thumb),
  MAKE_EVENT(ValueChanged, winrt::Windows::UI::Xaml::Controls::RatingControl),
  MAKE_EVENT(RefreshRequested, winrt::Windows::UI::Xaml::Controls::RefreshContainer),
  MAKE_EVENT(RefreshRequested, winrt::Windows::UI::Xaml::Controls::RefreshVisualizer),
  MAKE_EVENT(RefreshStateChanged, winrt::Windows::UI::Xaml::Controls::RefreshVisualizer),
  MAKE_EVENT(ContextMenuOpening, winrt::Windows::UI::Xaml::Controls::RichEditBox),
  MAKE_EVENT(SelectionChanged, winrt::Windows::UI::Xaml::Controls::RichEditBox),
  MAKE_EVENT(TextChanged, winrt::Windows::UI::Xaml::Controls::RichEditBox),
  MAKE_EVENT(Paste, winrt::Windows::UI::Xaml::Controls::RichEditBox),
  MAKE_EVENT(CandidateWindowBoundsChanged, winrt::Windows::UI::Xaml::Controls::RichEditBox),
  MAKE_EVENT(TextChanging, winrt::Windows::UI::Xaml::Controls::RichEditBox),
  MAKE_EVENT(TextCompositionChanged, winrt::Windows::UI::Xaml::Controls::RichEditBox),
  MAKE_EVENT(TextCompositionEnded, winrt::Windows::UI::Xaml::Controls::RichEditBox),
  MAKE_EVENT(TextCompositionStarted, winrt::Windows::UI::Xaml::Controls::RichEditBox),
  MAKE_EVENT(CopyingToClipboard, winrt::Windows::UI::Xaml::Controls::RichEditBox),
  MAKE_EVENT(CuttingToClipboard, winrt::Windows::UI::Xaml::Controls::RichEditBox),
  MAKE_EVENT(ContentLinkChanged, winrt::Windows::UI::Xaml::Controls::RichEditBox),
  MAKE_EVENT(ContentLinkInvoked, winrt::Windows::UI::Xaml::Controls::RichEditBox),
  MAKE_EVENT(SelectionChanging, winrt::Windows::UI::Xaml::Controls::RichEditBox),
  MAKE_EVENT(ContextMenuOpening, winrt::Windows::UI::Xaml::Controls::RichTextBlock),
  MAKE_EVENT(SelectionChanged, winrt::Windows::UI::Xaml::Controls::RichTextBlock),
  MAKE_EVENT(IsTextTrimmedChanged, winrt::Windows::UI::Xaml::Controls::RichTextBlock),
  MAKE_EVENT(IsTextTrimmedChanged, winrt::Windows::UI::Xaml::Controls::RichTextBlockOverflow),
  MAKE_EVENT(ViewChanged, winrt::Windows::UI::Xaml::Controls::ScrollViewer),
  MAKE_EVENT(ViewChanging, winrt::Windows::UI::Xaml::Controls::ScrollViewer),
  MAKE_EVENT(DirectManipulationCompleted, winrt::Windows::UI::Xaml::Controls::ScrollViewer),
  MAKE_EVENT(DirectManipulationStarted, winrt::Windows::UI::Xaml::Controls::ScrollViewer),
  MAKE_EVENT(AnchorRequested, winrt::Windows::UI::Xaml::Controls::ScrollViewer),
  MAKE_EVENT(PrepareForFocusOnKeyboardInput, winrt::Windows::UI::Xaml::Controls::SearchBox),
  MAKE_EVENT(QueryChanged, winrt::Windows::UI::Xaml::Controls::SearchBox),
  MAKE_EVENT(QuerySubmitted, winrt::Windows::UI::Xaml::Controls::SearchBox),
  MAKE_EVENT(ResultSuggestionChosen, winrt::Windows::UI::Xaml::Controls::SearchBox),
  MAKE_EVENT(SuggestionsRequested, winrt::Windows::UI::Xaml::Controls::SearchBox),
  MAKE_EVENT(ViewChangeCompleted, winrt::Windows::UI::Xaml::Controls::SemanticZoom),
  MAKE_EVENT(ViewChangeStarted, winrt::Windows::UI::Xaml::Controls::SemanticZoom),
  MAKE_EVENT(BackClick, winrt::Windows::UI::Xaml::Controls::SettingsFlyout),
  MAKE_EVENT(Click, winrt::Windows::UI::Xaml::Controls::SplitButton),
  MAKE_EVENT(PaneClosed, winrt::Windows::UI::Xaml::Controls::SplitView),
  MAKE_EVENT(PaneClosing, winrt::Windows::UI::Xaml::Controls::SplitView),
  MAKE_EVENT(PaneOpened, winrt::Windows::UI::Xaml::Controls::SplitView),
  MAKE_EVENT(PaneOpening, winrt::Windows::UI::Xaml::Controls::SplitView),
  MAKE_EVENT(HorizontalSnapPointsChanged, winrt::Windows::UI::Xaml::Controls::StackPanel),
  MAKE_EVENT(VerticalSnapPointsChanged, winrt::Windows::UI::Xaml::Controls::StackPanel),
  MAKE_EVENT(CompositionScaleChanged, winrt::Windows::UI::Xaml::Controls::SwapChainPanel),
  MAKE_EVENT(ContextMenuOpening, winrt::Windows::UI::Xaml::Controls::TextBlock),
  MAKE_EVENT(SelectionChanged, winrt::Windows::UI::Xaml::Controls::TextBlock),
  MAKE_EVENT(IsTextTrimmedChanged, winrt::Windows::UI::Xaml::Controls::TextBlock),
  MAKE_EVENT(ContextMenuOpening, winrt::Windows::UI::Xaml::Controls::TextBox),
  MAKE_EVENT(SelectionChanged, winrt::Windows::UI::Xaml::Controls::TextBox),
  MAKE_EVENT(TextChanged, winrt::Windows::UI::Xaml::Controls::TextBox),
  MAKE_EVENT(Paste, winrt::Windows::UI::Xaml::Controls::TextBox),
  MAKE_EVENT(CandidateWindowBoundsChanged, winrt::Windows::UI::Xaml::Controls::TextBox),
  MAKE_EVENT(TextChanging, winrt::Windows::UI::Xaml::Controls::TextBox),
  MAKE_EVENT(TextCompositionChanged, winrt::Windows::UI::Xaml::Controls::TextBox),
  MAKE_EVENT(TextCompositionEnded, winrt::Windows::UI::Xaml::Controls::TextBox),
  MAKE_EVENT(TextCompositionStarted, winrt::Windows::UI::Xaml::Controls::TextBox),
  MAKE_EVENT(BeforeTextChanging, winrt::Windows::UI::Xaml::Controls::TextBox),
  MAKE_EVENT(CopyingToClipboard, winrt::Windows::UI::Xaml::Controls::TextBox),
  MAKE_EVENT(CuttingToClipboard, winrt::Windows::UI::Xaml::Controls::TextBox),
  MAKE_EVENT(SelectionChanging, winrt::Windows::UI::Xaml::Controls::TextBox),
  MAKE_EVENT(TimeChanged, winrt::Windows::UI::Xaml::Controls::TimePicker),
  MAKE_EVENT(SelectedTimeChanged, winrt::Windows::UI::Xaml::Controls::TimePicker),
  MAKE_EVENT(IsCheckedChanged, winrt::Windows::UI::Xaml::Controls::ToggleSplitButton),
  MAKE_EVENT(Toggled, winrt::Windows::UI::Xaml::Controls::ToggleSwitch),
  MAKE_EVENT(Closed, winrt::Windows::UI::Xaml::Controls::ToolTip),
  MAKE_EVENT(Opened, winrt::Windows::UI::Xaml::Controls::ToolTip),
  MAKE_EVENT(Collapsed, winrt::Windows::UI::Xaml::Controls::TreeView),
  MAKE_EVENT(Expanding, winrt::Windows::UI::Xaml::Controls::TreeView),
  MAKE_EVENT(ItemInvoked, winrt::Windows::UI::Xaml::Controls::TreeView),
  MAKE_EVENT(DragItemsCompleted, winrt::Windows::UI::Xaml::Controls::TreeView),
  MAKE_EVENT(DragItemsStarting, winrt::Windows::UI::Xaml::Controls::TreeView),
  MAKE_EVENT(ModeChanged, winrt::Windows::UI::Xaml::Controls::TwoPaneView),
  MAKE_EVENT(CleanUpVirtualizedItemEvent, winrt::Windows::UI::Xaml::Controls::VirtualizingStackPanel),
  MAKE_EVENT(LoadCompleted, winrt::Windows::UI::Xaml::Controls::WebView),
  MAKE_EVENT(NavigationFailed, winrt::Windows::UI::Xaml::Controls::WebView),
  MAKE_EVENT(ScriptNotify, winrt::Windows::UI::Xaml::Controls::WebView),
  MAKE_EVENT(ContentLoading, winrt::Windows::UI::Xaml::Controls::WebView),
  MAKE_EVENT(DOMContentLoaded, winrt::Windows::UI::Xaml::Controls::WebView),
  MAKE_EVENT(FrameContentLoading, winrt::Windows::UI::Xaml::Controls::WebView),
  MAKE_EVENT(FrameDOMContentLoaded, winrt::Windows::UI::Xaml::Controls::WebView),
  MAKE_EVENT(FrameNavigationCompleted, winrt::Windows::UI::Xaml::Controls::WebView),
  MAKE_EVENT(FrameNavigationStarting, winrt::Windows::UI::Xaml::Controls::WebView),
  MAKE_EVENT(LongRunningScriptDetected, winrt::Windows::UI::Xaml::Controls::WebView),
  MAKE_EVENT(NavigationCompleted, winrt::Windows::UI::Xaml::Controls::WebView),
  MAKE_EVENT(NavigationStarting, winrt::Windows::UI::Xaml::Controls::WebView),
  MAKE_EVENT(UnsafeContentWarningDisplaying, winrt::Windows::UI::Xaml::Controls::WebView),
  MAKE_EVENT(UnviewableContentIdentified, winrt::Windows::UI::Xaml::Controls::WebView),
  MAKE_EVENT(ContainsFullScreenElementChanged, winrt::Windows::UI::Xaml::Controls::WebView),
  MAKE_EVENT(NewWindowRequested, winrt::Windows::UI::Xaml::Controls::WebView),
  MAKE_EVENT(PermissionRequested, winrt::Windows::UI::Xaml::Controls::WebView),
  MAKE_EVENT(UnsupportedUriSchemeIdentified, winrt::Windows::UI::Xaml::Controls::WebView),
  MAKE_EVENT(SeparateProcessLost, winrt::Windows::UI::Xaml::Controls::WebView),
  MAKE_EVENT(WebResourceRequested, winrt::Windows::UI::Xaml::Controls::WebView),

};

void JsEvent(winrt::Microsoft::ReactNative::IJSValueWriter const& constantWriter, std::wstring topName, std::wstring onName) {
    constantWriter.WritePropertyName(topName);
    constantWriter.WriteObjectBegin();
    WriteProperty(constantWriter, L"registrationName", onName);
    constantWriter.WriteObjectEnd();
  }

#define JS_EVENT(evtName) JsEvent(constantWriter, L"top" L#evtName, L"on" L#evtName)

ConstantProviderDelegate GetEvents = 
    [](winrt::Microsoft::ReactNative::IJSValueWriter const& constantWriter) {
    for (auto const& e : EventInfo::xamlEventMap) {
        auto wideName = std::wstring(winrt::to_hstring(e.name));
        JsEvent(constantWriter, L"top" + wideName, L"on" + wideName);
    }
};
