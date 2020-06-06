#include "pch.h"
#include "ReactPackageProvider.h"
#include "NativeModules.h"
#include "TestModule.h"


using namespace winrt::Microsoft::ReactNative;

namespace winrt::new_rnw_app::implementation
{

void ReactPackageProvider::CreatePackage(IReactPackageBuilder const &packageBuilder) noexcept
{
    AddAttributedModules(packageBuilder);
}

} // namespace winrt::new_rnw_app::implementation


