#pragma once

#include "MainPage.g.h"

namespace winrt::BlurBrushTestWinUIUwp::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage();

        void image_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
    };
}

namespace winrt::BlurBrushTestWinUIUwp::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
