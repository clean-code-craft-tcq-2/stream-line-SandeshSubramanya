#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"
#include "Sensor.h"
#include "Sender.h"

TEST_CASE(" Test the usage of Sender") 
{
  // The sender is designed such a way that the interface needs to be called.
  // The sender internally requets sensor and just displays the various values of battery values to the console directly
  
  vReceiveBatteryParameterValues();
}

TEST_CASE(" Test the Sender to check if it sends required values from Sensor") 
{
  #define MAX_SENSOR_VALUES_TO_BE_READ 50
  vector<stBatteryParams> SensorValues;
  vReadBatteryParamtersFromSensor(SensorValues);
  assert(SensorValues.size() == MAX_SENSOR_VALUES_TO_BE_READ);
}
