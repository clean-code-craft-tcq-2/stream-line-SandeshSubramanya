#pragma once
#include "Sensor.h"
#include <iostream>
#include <vector>
using namespace std;
#define MAX_VALUE_TO_READ 50

// Helper method to display readings on console.
void vDisplayBatteryParamters(vector<stBatteryParams> rfSesorReadings);

// Gets the readings from the sensor.
void vReadBatteryParamtersFromSensor(vector<stBatteryParams> rfSesorReadings);

// method reads the values from the sensor and dsiplays the entire values on the console.
void vGetBatteryParameterValues();

