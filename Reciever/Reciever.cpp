#include "Reciever.h"
#include <iostream>
#include <bits/stdc++.h>

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

void findMinAndMaxValueofParameter(float Readings[], int numberOfReadings, string parameterName)
{
	float minValue = 0.0, maxValue = 0.0;

	minValue = findMinimumReadingValue(Readings, numberOfReadings);
	maxValue = findMaximumReadingValue(Readings, numberOfReadings);

	cout << parameterName << " : " << " Mininum Value: " << minValue << " Maximum Value: " << maxValue << endl;

}

void findSimpleMovingAverageofParameter(float Readings[], int numberOfReadings, string parameterName)
{
	float smaValue = 0.0;
	smaValue = ComputeSimpleMovingAvergeOfLastFiveValues(Readings, numberOfReadings);
	cout << parameterName << " : " << "Simple Moing Average: " << smaValue << endl;
}

bool recieveAndCompute(bool(*readDataFunc)(float[], float[], float[], int))
{
	float temperatureReadings[TOTAL_NUMBER_OF_READINGS], stateOfChargeReadings[TOTAL_NUMBER_OF_READINGS], chargingTimeReadings[TOTAL_NUMBER_OF_READINGS];

	bool readStatus = readDataFunc(temperatureReadings, stateOfChargeReadings, chargingTimeReadings, TOTAL_NUMBER_OF_READINGS);

	if (readStatus)
	{
		findMinAndMaxValueofParameter(temperatureReadings, TOTAL_NUMBER_OF_READINGS, "Temperature");
		findMinAndMaxValueofParameter(stateOfChargeReadings, TOTAL_NUMBER_OF_READINGS, "State of Charge");
		findMinAndMaxValueofParameter(chargingTimeReadings, TOTAL_NUMBER_OF_READINGS, "Charging Time");

		findSimpleMovingAverageofParameter(temperatureReadings, TOTAL_NUMBER_OF_READINGS, "Temperature");
		findSimpleMovingAverageofParameter(stateOfChargeReadings, TOTAL_NUMBER_OF_READINGS, "State of Charge");
		findSimpleMovingAverageofParameter(chargingTimeReadings, TOTAL_NUMBER_OF_READINGS, "Charging Time");

	}
	return readStatus;
}
