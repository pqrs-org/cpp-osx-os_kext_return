#include <pqrs/osx/kext_return.hpp>

int main(void) {
  {
    pqrs::osx::kext_return r(kOSKextReturnSystemPolicy);
    std::cout << r << std::endl;
  }

  {
    pqrs::osx::kext_return r(54321);
    std::cout << r << std::endl;
  }

  return 0;
}
