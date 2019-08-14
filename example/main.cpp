#include <pqrs/osx/os_kext_return.hpp>

int main(void) {
  {
    pqrs::osx::os_kext_return r(kOSKextReturnSystemPolicy);
    std::cout << r << std::endl;
  }

  {
    pqrs::osx::os_kext_return r(54321);
    std::cout << r << std::endl;
  }

  return 0;
}
