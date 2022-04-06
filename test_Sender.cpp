#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"
#include "Sensor.h"
#include "Sender.h"

TEST_CASE(" Test the usage of Sender") 
{
  // The sender is designed such a way that the interface needs to be called.
  // The sender just displays the various values of battery to the console
  vReceiveBatteryParameterValues();
}
