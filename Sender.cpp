#include "Sender.h"

// Helper method to display readings on console.
void vDisplayBatteryParamters(vector<stBatteryParams>& rfSesorReadings)
{
  for(int Index =0; Index< (int)rfSesorReadings.size(); ++Index)
  {
    cout<<"Temperature: "<<rfSesorReadings[Index].internalTemperature<<" SoC: "<<rfSesorReadings[Index].stateOfCharge<<" ChargingTime: "<<rfSesorReadings[Index].chargingTimeSec<<endl;
  }
}

// Gets the readings from the sensor.
void vReadBatteryParamtersFromSensor(vector<stBatteryParams>& rfSesorReadings)
{
  rfSesorReadings.clear();
  for(int ReadNumber =1; ReadNumber<= (int)MAX_VALUE_TO_READ; ++ReadNumber)
  {
    stBatteryParams oBatteryParamterValue = getBatteryParamterValuesFromSensor();
    rfSesorReadings.push_back(oBatteryParamterValue);
  }
}

// method reads the values from the sensor and dsiplays the entire values on the console.
void vGetBatteryParameterValues()
{
  vector<stBatteryParams> oSesorReadings;
  vReadBatteryParamtersFromSensor(oSesorReadings);
  vDisplayBatteryParamters(oSesorReadings);
}
