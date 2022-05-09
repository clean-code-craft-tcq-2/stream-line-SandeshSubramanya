/*
This is a simple sensor file, that generates combination of 3 values 

1: Internal Temp of the battery
2: SoC (state of charge)
3: Charging time in seconds to charge to full battery capacity at this internal temperature

The logic of generating numbers is simple. It initialises a static variable and then adds/multiplies a fixed value
to generate combination of 3 values.
It is upto the sender to request as many as sensor values from this sensor.
*/

#pragma once
#include <vector>
#include <cstdlib>
using namespace std;

struct stBatteryParams
{
  int internalTemperature;
  int stateOfCharge;
  int chargingTimeSec;
};

void GenerateBatteryParamters(stBatteryParams& rfBatteryParameter);
stBatteryParams getBatteryParamterValuesFromSensor();
