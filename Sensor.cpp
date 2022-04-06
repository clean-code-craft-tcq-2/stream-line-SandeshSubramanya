#include "Sensor.h"

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
