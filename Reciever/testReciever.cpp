#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "../test/catch.hpp"
#include "Reciever.h"
#include <iostream>
using namespace std;

TEST_CASE("Test the recieve And Compute"){
	bool readStatus = STATUS_NOK;
	readStatus = recieveAndCompute(&readDataFromConsole);
	REQUIRE(readStatus == STATUS_OK);
}

TEST_CASE("Test the Maximum Value in a array"){
	float testArray[10] = { 100, 50, 150, 200, 5, 10, 35, 60, 89, 70 };
	float expectedMaxValue = 200;
	REQUIRE(findMaximumReadingValue(testArray, 10) == expectedMaxValue);
}

TEST_CASE("Test the Minimum Value in a array"){
	float testArray[10] = { 10, 50, 150, 20, 5, 90, 35, 60, 89, 70 };
	float expectedMinValue = 5;
	REQUIRE(findMinimumReadingValue(testArray, 10) == expectedMinValue);
}

TEST_CASE("Test the Minimum Value in a array with negative value"){
	float testArray[10] = { -10, 0, -5, 20, 5, 90, 35, -6, 89, 70 };
	float expectedMinValue = -10;
	REQUIRE(findMinimumReadingValue(testArray, 10) == expectedMinValue);
}
TEST_CASE("Test the Simple moving average"){
	float testArray[10] = { 100, 50, 150, 200, 5, 10, 35, 60, 89, 70 };
	float expectedSMAValue = (10+35+60+89+70)/5.0;
	float epsilon = 0.001;
	REQUIRE(abs(ComputeSimpleMovingAvergeOfLastFiveValues(testArray, 10) - expectedSMAValue) < epsilon);
}
