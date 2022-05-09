#include <string>
using namespace std;

#define STATUS_OK true
#define STATUS_NOK false
#define TOTAL_NUMBER_OF_READINGS 50

bool readDataFromConsole(float temperatureReadings[], float stateOfChargeReadings[], float chargingTimeReadings[], int numberOfReadings);
bool readDataFromFile(float temperatureReadings[], float stateOfChargeReadings[], float chargingTimeReadings[], int numberOfReadings);

float findMaximumReadingValue(float batteryParameterReadings[], int numberOfReadings);
float findMinimumReadingValue(float batteryParameterReadings[], int numberOfReadings);

float ComputeSimpleMovingAvergeOfLastFiveValues(float batteryParameterReadings[], int numberOfReadings);

void findMinAndMaxValueofParameter(float Readings[], int numberOfReadings, string parameterName);
void findSimpleMovingAverageofParameter(float Readings[], int numberOfReadings, string parameterName);

bool recieveAndCompute(bool(*readDataFunc)(float[],float[],float[],int));
