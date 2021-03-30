#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits LOW") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}

TEST_CASE("infers the breach according to limits HIGH") {
  REQUIRE(inferBreach(32, 20, 30) == TOO_HIGH);
}

TEST_CASE("Test the High limit & also Email Alert") {
  BatteryCharacter batteryChar;
  batteryChar.coolingType = 0;
  batteryChar.brand = "xxxxx";
  REQUIRE(checkAndAlert(1, batteryChar, 40));
}
