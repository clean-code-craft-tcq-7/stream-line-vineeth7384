#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "BMS_receive.h"

int main(void)
{
    char string [STRING_SIZE];
    char subString[STRING_SIZE];
    float voltageArray[SENSOR_VALUE_COUNT];
    float chargeArray[SENSOR_VALUE_COUNT];
    float minValue,maxValue,averageValue;
    bmsMinMaxAvg bmsParameter;
    
    for(int i = 0; i < SENSOR_VALUE_COUNT; i++)
    {
        fgets(string, STRING_SIZE , stdin);
        strncpy(subString, string + START_OF_VOLTAGE_VALUE, FLOAT_SIZE);
        voltageArray[i] = strtod(subString,NULL);
        strncpy(subString, string + START_OF_CHARGE_VALUE, FLOAT_SIZE);
        chargeArray[i] = strtod(subString,NULL);
    }

    minMaxSensorValues(voltageArray,&minValue,&maxValue);
    bmsParameter.voltageMin = minValue;
    bmsParameter.voltageMin = maxValue;
    printf("voltagemin is %f and voltagemax is %f\n",bmsParameter.voltageMin,bmsParameter.voltageMin);

    minMaxSensorValues(chargeArray,&minValue,&maxValue);
    bmsParameter.chargeMin = minValue;
    bmsParameter.chargeMax = minValue;
    printf("currentmin is %f and currentmax is %f\n",bmsParameter.chargeMin,bmsParameter.chargeMax);

    movingAverage(voltageArray,&averageValue);
    bmsParameter.voltageAverage = averageValue;
    printf("voltageAverage is %f\n",bmsParameter.voltageAverage);

    movingAverage(chargeArray,&averageValue);
    bmsParameter.chargeAverage = averageValue;
    printf("chargeAverage is %f\n",bmsParameter.chargeAverage);

    return 0;
}

void minMaxSensorValues(float array[],float *minValue,float *maxValue)
{
    int i, size;

    size = SENSOR_VALUE_COUNT;

    /* Assume first element as maximum and minimum */
    *minValue = array[0];
    *maxValue = array[0];

    for(i=1; i<size; i++)
    {
        /* If current element is greater than max */
        if(array[i] > *maxValue)
        {
            *maxValue = array[i];
        }

        /* If current element is smaller than min */
        if(array[i] < *minValue)
        {
            *minValue = array[i];
        }
    }
}

void movingAverage(float array[],float *avgValue)
{
  // the size of this array represents how many numbers will be used to calculate the average
  float arrNumbers[5] = {0};
  int pos = 0;
  long sum = 0;
  int len = 5;

  for(int i = 0; i < SENSOR_VALUE_COUNT; i++)
  {
    sum = sum - arrNumbers[pos] + array[i];
    arrNumbers[pos] = array[i];
    *avgValue = sum / len ; 
    pos++;
    if (pos >= len)
    {
      pos = 0;
    }
  }
}

