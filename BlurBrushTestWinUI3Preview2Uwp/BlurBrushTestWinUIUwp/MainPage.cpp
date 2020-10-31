#include "pch.h"
#include "MainPage.h"
#include "winrt/Windows.Graphics.Effects.h"
#include "winrt/Microsoft.Graphics.Canvas.Effects.h"
#include "winrt/Microsoft.UI.Xaml.Hosting.h"
#include "MainPage.g.cpp"

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::BlurBrushTestWinUIUwp::implementation
{
    MainPage::MainPage()
    {
        InitializeComponent();
    }

    void MainPage::image_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        auto blur = Microsoft::Graphics::Canvas::Effects::GaussianBlurEffect();
        blur.Source(Microsoft::UI::Composition::CompositionEffectSourceParameter(L"source"));
        blur.BlurAmount(50.0f);
        blur.BorderMode(Microsoft::Graphics::Canvas::Effects::EffectBorderMode::Hard);
        auto imageVisual = Microsoft::UI::Xaml::Hosting::ElementCompositionPreview::GetElementVisual(image());
        auto compositor = imageVisual.Compositor();
        auto blurBrushFactory = compositor.CreateEffectFactory(blur);
        auto blurBrush = blurBrushFactory.CreateBrush();
        blurBrush.SetSourceParameter(L"source", compositor.CreateBackdropBrush());
        auto blurVisual = compositor.CreateSpriteVisual();
        blurVisual.Brush(blurBrush);
        blurVisual.RelativeSizeAdjustment(Windows::Foundation::Numerics::float2(1.0f, 1.0f));
        Microsoft::UI::Xaml::Hosting::ElementCompositionPreview::SetElementChildVisual(image(), blurVisual);
    }
}

