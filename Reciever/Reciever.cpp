#include "Reciever.h"
#include <iostream>
using namespace std;

//Function to read data from file in test environment
bool readDataFromFile(float temperatureReadings[], float stateOfChargeReadings[], float chargingTimeReadings[], int numberOfReadings)
{
	FILE *fp;
	fp = fopen("./Reciever/Reciever_Data.txt", "r");
	if (fp)
	{
		float tempValue = 0.0, stateOfChargeValue = 0.0, chargingTimeValue = 0.0;
		for (int i = 0; (fscanf(fp, "Temperature: %f SoC: %f ChargingTime:%f\n", &tempValue, &stateOfChargeValue, &chargingTimeValue) != EOF) && i < numberOfReadings; i++)
		{
			temperatureReadings[i] = tempValue;
			stateOfChargeReadings[i] = stateOfChargeValue;
			chargingTimeReadings[i] = chargingTimeValue;
		}
		fclose(fp);
		return STATUS_OK;
	}
	return STATUS_NOK;
}

bool readDataFromConsole(float temperatureReadings[], float stateOfChargeReadings[], float chargingTimeReadings[], int numberOfReadings)
{
	string input,ignore_text;
	for (int readingIndex = 0; readingIndex < numberOfReadings; readingIndex++)
	{
    	//Format of input : Temperature: 2 SoC : 11 ChargingTime : 1000
		cin >> ignore_text >> temperatureReadings[readingIndex] >> ignore_text >> stateOfChargeReadings[readingIndex] >> ignore_text >> chargingTimeReadings[readingIndex];
	}
	if (temperatureReadings[numberOfReadings - 1] && stateOfChargeReadings[numberOfReadings - 1] && chargingTimeReadings[numberOfReadings - 1])
		return STATUS_OK;
	return STATUS_NOK;
}

float findMaximumReadingValue(float batteryParameterReadings[], int numberOfReadings)
{
	float max = batteryParameterReadings[0];
	for (int i = 1; i < numberOfReadings; i++)
	{
		if (batteryParameterReadings[i] > max)
			max = batteryParameterReadings[i];
	}

	return max;
}

float findMinimumReadingValue(float batteryParameterReadings[], int numberOfReadings)
{
	float min = batteryParameterReadings[0];
	for (int i = 1; i < numberOfReadings; i++)
	{
		if (batteryParameterReadings[i] < min)
			min = batteryParameterReadings[i];
	}

	return min;
}

float ComputeSimpleMovingAvergeOfLastFiveValues(float batteryParameterReadings[], int numberOfReadings)
{
	float sum = 0.0, average = 0.0;
	for (int i = numberOfReadings - 5 ; i < numberOfReadings; i++)
	{
		sum = sum + batteryParameterReadings[i];
	}
	average = sum / 5.0;
	return average;
}

void findTemperatureMinAndMaxValue(float temperatureReadings[], int numberOfReadings)
{
	float maxTemperature = 0.0, minTemperature = 0.0;
	minTemperature = findMinimumReadingValue(temperatureReadings, numberOfReadings);
	maxTemperature = findMaximumReadingValue(temperatureReadings, numberOfReadings);
	cout << " Temperature: " << " Mininum Value: " << minTemperature << "Maximum Value: " << maxTemperature <<  endl;
}

void findStateOfChargeMinAndMaxValue(float stateOfChargeReadings[], int numberOfReadings)
{
	float maxStateOfCharge = 0.0, minStateOfCharge = 0.0;
	minStateOfCharge = findMinimumReadingValue(stateOfChargeReadings, numberOfReadings);
	maxStateOfCharge = findMaximumReadingValue(stateOfChargeReadings, numberOfReadings);
	cout << " State Of Charge: " << " Mininum Value: " << minStateOfCharge << "Maximum Value: " << maxStateOfCharge << endl;
}

void findChargingTimeMinAndMaxValue(float chargingTimeReadings[], int numberOfReadings)
{
	float maxChargingTime = 0.0, minChargingTime = 0.0;
	minChargingTime = findMinimumReadingValue(chargingTimeReadings, numberOfReadings);
	maxChargingTime = findMaximumReadingValue(chargingTimeReadings, numberOfReadings);
	cout << " Charging Time: " << " Mininum Value: " << minChargingTime << "Maximum Value: " << maxChargingTime << endl;
}

void findTemperatureSimpleMovingAverage(float temperatureReadings[], int numberOfReadings)
{
	float smaTemperature = 0.0;
	smaTemperature = ComputeSimpleMovingAvergeOfLastFiveValues(temperatureReadings, numberOfReadings);
	cout << " Temperature: " << "Simple Moing Average: " << smaTemperature << endl;
}

void findStateOfChargeSimpleMovingAverage(float stateOfChargeReadings[], int numberOfReadings)
{
	float smaStateOfCharge = 0.0;
	smaStateOfCharge = ComputeSimpleMovingAvergeOfLastFiveValues(stateOfChargeReadings, numberOfReadings);
	cout << " State Of Charge: " << "Simple Moing Average: " << smaStateOfCharge << endl;
}

void findChargingTimeSimpleMovingAverage(float chargingTimeReadings[], int numberOfReadings)
{
	float smaChargingTime = 0.0;
	smaChargingTime = ComputeSimpleMovingAvergeOfLastFiveValues(chargingTimeReadings, numberOfReadings);
	cout << " Charging Time: " << "Simple Moing Average: " << smaChargingTime << endl;
}

bool recieveAndCompute(bool(*readDataFunc)(float[], float[], float[], int))
{
	float temperatureReadings[TOTAL_NUMBER_OF_READINGS], stateOfChargeReadings[TOTAL_NUMBER_OF_READINGS], chargingTimeReadings[TOTAL_NUMBER_OF_READINGS];

	bool readStatus = readDataFunc(temperatureReadings, stateOfChargeReadings, chargingTimeReadings, TOTAL_NUMBER_OF_READINGS);

	if (readStatus)
	{
		findTemperatureMinAndMaxValue(temperatureReadings, TOTAL_NUMBER_OF_READINGS);
		findStateOfChargeMinAndMaxValue(stateOfChargeReadings, TOTAL_NUMBER_OF_READINGS);
		findChargingTimeMinAndMaxValue(chargingTimeReadings, TOTAL_NUMBER_OF_READINGS);

		findTemperatureSimpleMovingAverage(temperatureReadings, TOTAL_NUMBER_OF_READINGS);
		findStateOfChargeSimpleMovingAverage(stateOfChargeReadings, TOTAL_NUMBER_OF_READINGS);
		findChargingTimeSimpleMovingAverage(chargingTimeReadings, TOTAL_NUMBER_OF_READINGS);
	}
	return readStatus;
}
