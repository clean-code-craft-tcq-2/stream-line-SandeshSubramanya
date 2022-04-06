#pragma once
#include "Sensor.h"
#include <iostream>
using namespace std;

void vDisplayBatteryParamters(stBatteryParams oBatteryParam)
{
  cout<<"Temperature: "<<oBatteryParam.internalTemperature<<" SoC: "<<oBatteryParam.stateOfCharge<<" ChargingTime: "<<oBatteryParam.chargingTimeSec<<endl;
}
