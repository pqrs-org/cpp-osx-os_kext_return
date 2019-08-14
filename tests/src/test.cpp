#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <pqrs/osx/kext_return.hpp>

TEST_CASE("kext_return") {
  {
    pqrs::osx::kext_return r(kOSReturnSuccess);
    REQUIRE(r.to_string() == "kOSReturnSuccess");
    REQUIRE(r == true);
    REQUIRE(r.success() == true);
    REQUIRE(r.system_policy() == false);
  }
  {
    pqrs::osx::kext_return r(kOSKextReturnInternalError);
    REQUIRE(r.to_string() == "kOSKextReturnInternalError");
    REQUIRE(r == false);
    REQUIRE(r.success() == false);
    REQUIRE(r.system_policy() == false);
  }
  {
    pqrs::osx::kext_return r(kOSKextReturnSystemPolicy);
    REQUIRE(r.to_string() == "kOSKextReturnSystemPolicy");
    REQUIRE(r == false);
    REQUIRE(r.success() == false);
    REQUIRE(r.system_policy() == true);
  }
  {
    pqrs::osx::kext_return r(-603946990);
    REQUIRE(r.to_string() == "kOSKextReturnBootLevel");
    REQUIRE(r == false);
    REQUIRE(r.success() == false);
    REQUIRE(r.system_policy() == false);
  }
}
