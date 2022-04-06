#pragma once
#include "Sensor.h"
using namespace std;

void vDisplayBatteryParamters(stBatteryParams oBatteryParam)
{
  cout<<"Temperature: "<<oBatterParameter.internalTemperature<<" SoC: "<<oBatterParameter.stateOfCharge<<" ChargingTime: "<<oBatterParameter.chargingTimeSec<<endl;
}
