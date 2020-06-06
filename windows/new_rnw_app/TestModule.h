#pragma once
#include "pch.h"

#include <functional>

#include "NativeModules.h"
#include <winrt/Microsoft.ReactNative.h>
#include <winrt/Windows.UI.Xaml.h>
#include <winrt/Windows.UI.Xaml.Media.h>

namespace new_rnw_app
{
    REACT_MODULE(TestModule);
    struct TestModule
    {
        REACT_INIT(Init);
        void Init(winrt::Microsoft::ReactNative::ReactContext const& reactContext) noexcept
        {
            m_reactContext = reactContext;
        }

        REACT_METHOD(Add, L"add");
        double Add(double a, double b) noexcept
        {
            double result = a + b;
            AddEvent(result);
            return result;
        }

        REACT_METHOD(SetColor, L"setColor");
        void SetColor(int64_t tag) noexcept
        {
            auto depObject = m_reactContext.XamlElementFromTag(tag);

            auto fe = depObject.as<winrt::Windows::UI::Xaml::Controls::Panel>();
            fe.Background(winrt::Windows::UI::Xaml::Media::SolidColorBrush(winrt::Windows::UI::Colors::CornflowerBlue()));
        }

        REACT_EVENT(AddEvent);
        std::function<void(double)> AddEvent;

    private:
        winrt::Microsoft::ReactNative::ReactContext m_reactContext{ nullptr };
    };
}