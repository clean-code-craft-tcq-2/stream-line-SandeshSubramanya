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

struct stBatteryParams
{
  int internalTemperature;
  int stateOfCharge;
  int chargingTimeSec;
};

 void GenerateBatteryParamters(stBatteryParams& rfBatteryParameter)
{
  int randomNumber= 1 + (rand() % 50);
  rfBatteryParameter.internalTemperature = randomNumber;
  rfBatteryParameter.stateOfCharge = (randomNumber + 10);
  rfBatteryParameter.chargingTimeSec = (randomNumber * 1000);
}

stBatteryParams getBatteryParamterValuesFromSensor()
{
  stBatteryParams oSingleBatteryParamValue;
  GenerateBatteryParamters(oSingleBatteryParamValue);
  return oSingleBatteryParamValue;
}
