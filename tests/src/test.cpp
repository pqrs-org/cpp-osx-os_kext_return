#include <boost/ut.hpp>
#include <pqrs/osx/os_kext_return.hpp>

int main(void) {
  using namespace boost::ut;
  using namespace boost::ut::literals;

  "os_kext_return"_test = [] {
    {
      pqrs::osx::os_kext_return r(kOSReturnSuccess);
      expect(r.to_string() == "kOSReturnSuccess");
      expect(r == true);
      expect(r.success() == true);
      expect(r.system_policy() == false);
    }
    {
      pqrs::osx::os_kext_return r(kOSKextReturnInternalError);
      expect(r.to_string() == "kOSKextReturnInternalError");
      expect(r == false);
      expect(r.success() == false);
      expect(r.system_policy() == false);
    }
    {
      pqrs::osx::os_kext_return r(kOSKextReturnSystemPolicy);
      expect(r.to_string() == "kOSKextReturnSystemPolicy");
      expect(r == false);
      expect(r.success() == false);
      expect(r.system_policy() == true);
    }
    {
      pqrs::osx::os_kext_return r(-603946990);
      expect(r.to_string() == "kOSKextReturnBootLevel");
      expect(r == false);
      expect(r.success() == false);
      expect(r.system_policy() == false);
    }
  };

  return 0;
}
