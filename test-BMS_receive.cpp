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
	float testVoltage = 1;
        float testCurrent = 1;
	
	srand(time(NULL));
	
	for(i=0;i<SENSOR_VALUE_COUNT;i++)
	{
		sprintf(testStringBuffer,"voltage = %.2f,current = %.2f\n",(testVoltage +((float) rand()/RAND_MAX)),(testCurrent+((float) rand()/RAND_MAX)));
	}
}


/*TEST_CASE("mock sender sensor data and on reception perform operations on the sensor stream received ") {
	int result = 0;
	processSensorString(&readFromTest);
	REQUIRE(result == 1 );
}*/
