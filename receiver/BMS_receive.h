#define STRING_SIZE 256
#define SENSOR_VALUE_COUNT 50
#define MAX_LENGTH 49
#define START_OF_VOLTAGE_VALUE 10
#define START_OF_CHARGE_VALUE 25
#define FLOAT_SIZE 4

typedef struct
{
    float voltageMin;
    float voltageMax;
    float chargeMin;
    float chargeMax;
    float voltageAverage;
    float chargeAverage;
}bmsMinMaxAvg;

void readFromConsole(char* buff);
void processSensorString(void (*receiver)(char*));
void minMaxSensorValues(float array[],float *minValue,float *maxValue);
void movingAverage(float array[],float *avgValue);
