#pragma once

#include "MainPage.g.h"

namespace winrt::BlurBrushTestUwp::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage();
        void Grid_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
    };
}

namespace winrt::BlurBrushTestUwp::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
