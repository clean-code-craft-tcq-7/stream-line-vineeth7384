#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "BMS_receive.h"

void readFromTest(char* testStringBuffer)
{
	int i = 0;
	static float testVoltage = 1;
        static float testCurrent = 1;
	
	srand(time(NULL));
	testVoltage = testVoltage +((float) rand()/RAND_MAX);
	testCurrent = testCurrent +((float) rand()/RAND_MAX);
	
	sprintf(testStringBuffer,"voltage = %.2f,current = %.2f",testVoltage,testCurrent);
        printf("%s\n",testStringBuffer);
}


TEST_CASE("mock sender sensor data and on reception perform operations on the sensor stream received ") {
	printf("----------sensor reception mocked data for test----------\n");
	processSensorString(&readFromTest);
}
