#define STATUS_OK true
#define STATUS_NOK false
#define TOTAL_NUMBER_OF_READINGS 50

bool readDataFromConsole(float temperatureReadings[], float stateOfChargeReadings[], float chargingTimeReadings[], int numberOfReadings);
bool readDataFromFile(float temperatureReadings[], float stateOfChargeReadings[], float chargingTimeReadings[], int numberOfReadings);

float findMaximumReadingValue(float batteryParameterReadings[], int numberOfReadings);
float findMinimumReadingValue(float batteryParameterReadings[], int numberOfReadings);

float ComputeSimpleMovingAvergeOfLastFiveValues(float batteryParameterReadings[], int numberOfReadings);

void findTemperatureMinAndMaxValue(float temperatureReadings[], int numberOfReadings);
void findStateOfChargeMinAndMaxValue(float stateOfChargeReadings[], int numberOfReadings);
void findChargingTimeMinAndMaxValue(float chargingTimeReadings[], int numberOfReadings);

void findTemperatureSimpleMovingAverage(float temperatureReadings[], int numberOfReadings);
void findStateOfChargeSimpleMovingAverage(float stateOfChargeReadings[], int numberOfReadings);
void findChargingTimeSimpleMovingAverage(float chargingTimeReadings[], int numberOfReadings);

bool recieveAndCompute(bool(*readDataFunc)(float[],float[],float[],int));
