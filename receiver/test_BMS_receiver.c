#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "test_BMS_receiver.h"

void readFromTest(char* testStringBuffer)
{
    static float testVoltage = 5;
    static float testCurrent = 5;
	
    srand(time(NULL));
    testVoltage = testVoltage +((float) rand()/RAND_MAX);
    testCurrent = testCurrent +((float) rand()/RAND_MAX);

    sprintf(testStringBuffer,"voltage = %.2f,current = %.2f",testVoltage,testCurrent);
}
