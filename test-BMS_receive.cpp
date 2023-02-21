#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include <string.h>
#include "BMS_receive.h"

void readFromTest(char* testStringBuffer)
{

}


TEST_CASE("mock sender sensor data and on reception perform operations on the sensor stream received ") {
	int result = 0;
  int i=0;
	processSensorString(&readFromTest);
	REQUIRE(result == 1 );
}
