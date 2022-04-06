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

typdef struct
{
  int internalTemperature,
  int stateOfCharge,
  int chargingTimeSec,
}stBatteryParams;

stBatteryParams stGenerateBatteryParamters()
{
  int randomNumber= 1 + (rand() % 50);
  stBatteryParams oBatteryParamter;
  oBatterParameter.internalTemperature = randomNumber;
  oBatterParameter.stateOfCharge = (randomNumber + 10);
  oBatterParameter.stateOfCharge = (randomNumber * 1000);
  return oBatteryParamter;
}