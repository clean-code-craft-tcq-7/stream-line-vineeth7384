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
	
	sprintf(testStringBuffer,"voltage = %.2f,current = %.2f",(testVoltage +((float) rand()/RAND_MAX)),(testCurrent+((float) rand()/RAND_MAX)));
        printf("%s\n",testStringBuffer);
}


TEST_CASE("mock sender sensor data and on reception perform operations on the sensor stream received ") {
	int result = 0;
	processSensorString(&readFromTest);
	REQUIRE(result == 1 );
}
