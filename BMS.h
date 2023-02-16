
#define DEFAULT_OFFSET_VALUE_VOLTAGE 1
#define DEFAULT_OFFSET_VALUE_CURRENT 1
typedef struct
{
    float voltage ;
    float current ;
    
}BMSParameter;
void formatOutputtoConsole( float voltage,float current);
void ParameterGenerationandProcessing(int*status);
