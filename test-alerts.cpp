#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits LOW") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}

TEST_CASE("infers the breach according to limits HIGH") {
  REQUIRE(inferBreach(32, 20, 30) == TOO_HIGH);
}

TEST_CASE("Test the Send operation - Controller") {
  BatteryCharacter batterychar = {PASSIVE_COOLING, "ABC"};
  REQUIRE( checkAndAlert(TO_CONTROLLER, batterychar, 25)== CONTROLLER_SEND_PASS);
}

TEST_CASE("Test the Send operation - Email") {
  BatteryCharacter batterychar = {HI_ACTIVE_COOLING, "ABC"};
  REQUIRE( checkAndAlert(TO_EMAIL, batterychar, 40)== EMAIL_SEND_PASS);
}


TEST_CASE("Test the Send operation - Email / High") {
  BatteryCharacter batterychar = {HI_ACTIVE_COOLING, "ABC"};
  REQUIRE( checkAndAlert(TO_EMAIL, batterychar, 50)== EMAIL_SEND_PASS);
}

TEST_CASE("Test the Send operation - Email / Low") {
  BatteryCharacter batterychar = {HI_ACTIVE_COOLING, "ABC"};
  REQUIRE( checkAndAlert(TO_EMAIL, batterychar, -1)== EMAIL_SEND_PASS);
}

TEST_CASE("Test the Send operation - Console") {
  BatteryCharacter batterychar = {MED_ACTIVE_COOLING, "ABC"};
  REQUIRE( checkAndAlert(TO_CONSOLE, batterychar, 30)== CONSOLE_SEND_PASS);
}
