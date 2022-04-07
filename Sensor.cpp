#include "Sensor.h"

static int RandomNumber= 1;
void GenerateBatteryParamters(stBatteryParams& rfBatteryParameter)
{
  rfBatteryParameter.internalTemperature = RandomNumber * 2;
  rfBatteryParameter.stateOfCharge = (RandomNumber + 10);
  rfBatteryParameter.chargingTimeSec = (RandomNumber * 1000);
  ++RandomNumber
}

stBatteryParams getBatteryParamterValuesFromSensor()
{
  stBatteryParams oSingleBatteryParamValue;
  GenerateBatteryParamters(oSingleBatteryParamValue);
  return oSingleBatteryParamValue;
}
