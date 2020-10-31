#include "pch.h"
#include "MainPage.h"
#include "winrt/Windows.Graphics.Effects.h"
#include "winrt/Microsoft.Graphics.Canvas.Effects.h"
#include "winrt/Windows.UI.Xaml.Hosting.h"
#include "MainPage.g.cpp"

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::BlurBrushTestUwp::implementation
{
    MainPage::MainPage()
    {
        InitializeComponent();
    }
    void MainPage::Grid_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
    {
        auto blur = Microsoft::Graphics::Canvas::Effects::GaussianBlurEffect();
        blur.Source(Windows::UI::Composition::CompositionEffectSourceParameter(L"source"));
        blur.BlurAmount(50.0f);
        blur.BorderMode(Microsoft::Graphics::Canvas::Effects::EffectBorderMode::Hard);
        auto imageVisual = Windows::UI::Xaml::Hosting::ElementCompositionPreview::GetElementVisual(image());
        auto compositor = imageVisual.Compositor();
        auto blurBrushFactory = compositor.CreateEffectFactory(blur);
        auto blurBrush = blurBrushFactory.CreateBrush();
        blurBrush.SetSourceParameter(L"source", compositor.CreateBackdropBrush());
        auto blurVisual = compositor.CreateSpriteVisual();
        blurVisual.Brush(blurBrush);
        blurVisual.RelativeSizeAdjustment(Windows::Foundation::Numerics::float2(1.0f, 1.0f));
        Windows::UI::Xaml::Hosting::ElementCompositionPreview::SetElementChildVisual(image(), blurVisual);
    }
}
