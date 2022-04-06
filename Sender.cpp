#pragma once
#include "Sensor.h"
#include <iostream>
#include <vector>
using namespace std;
#define MAX_VALUE_TO_READ 50

void vDisplayBatteryParamters(vector<int> rfSesorReadings)
{
  for(int Index =0; Index<= (int)rfSesorReadings.size(); ++Index)
  {
    cout<<"Temperature: "<<rfSesorReadings[Index].internalTemperature<<" SoC: "<<rfSesorReadings[Index].stateOfCharge<<" ChargingTime: "<<rfSesorReadings[Index].chargingTimeSec<<endl;
  }
}

void vReadBatteryParamtersFromSensor(vector<int> rfSesorReadings)
{
  rfSesorReadings.clear();
  for(int ReadNumber =1; ReadNumber<= (int)MAX_VALUE_TO_READ; ++ReadNumber)
  {
    stBatteryParams oBatteryParamterValue = getBatteryParamterValuesFromSensor();
    rfSesorReadings.push_back(oBatteryParamterValue);
  }
}

void vGetBatteryParameterValues()
{
  vector<int> oSesorReadings;
  vReadBatteryParamtersFromSensor(oSesorReadings);
  vDisplayBatteryParamters(oSesorReadings);
}


