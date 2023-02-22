#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "BMS.h"

void formatOutputtoConsole( float voltage,float current)
{
    printf("voltage = %.2f,current = %.2f\n",voltage,current);
    
}

void ParameterGenerationandProcessing(int*status)
{
   
   BMSParameter BatteryParameter;
   BatteryParameter.voltage = DEFAULT_OFFSET_VALUE_VOLTAGE;
   BatteryParameter.current = DEFAULT_OFFSET_VALUE_CURRENT;
   *status = 0;
   
   int index;
   
   srand(time(NULL));
   
   for(index = 0; index<=50;index++)
   {
       BatteryParameter.voltage +=((float) rand()/RAND_MAX)  ;
       BatteryParameter.current +=((float) rand()/RAND_MAX)  ;
       formatOutputtoConsole(BatteryParameter.voltage,BatteryParameter.current);
       *status = 1;
   } 
    
}