/*
This is a simple sensor, that generates combination of 3 values 
1: Internal Temp of the battery
2: SoC (state of charge)
3: Charging time in seconds to charge to full battery capacity at this internal temperatur
*/

#pragma once
#include <vector>
#include <cstdlib>
using namespace std;

typedef struct
{
  int internalTemperature,
  int stateOfCharge,
  int chargingTimeSec,
}stBatteryParams;

stBatteryParams stGenerateBatteryParamters()
{
  int randomNumber= 1 + (rand() % 50);
  stBatteryParams oBatteryParameter;
  oBatteryParameter.internalTemperature = randomNumber;
  oBatteryParameter.stateOfCharge = (randomNumber + 10);
  oBatteryParameter.chargingTimeSec = (randomNumber * 1000);
  return oBatteryParameter;
}
