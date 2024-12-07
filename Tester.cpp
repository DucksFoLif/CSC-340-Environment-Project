#include <iostream>
#include <string>
#include "Tester.h"
#include "Environment.h"
using namespace std;

void Tester::initiateTester()
{
    //programmer input for default
    string environmentType = "desert";
    int foodLevel = 15;
    double tempMin = 0.0;
    double tempMax = 35.0;

    // Display the initialization details to the user
    cout << "Initiating Environment with:\n";
    cout << "Environment Type: " << environmentType << "\n";
    cout << "Food Level: " << foodLevel << "\n";
    cout << "Temperature Range: " << tempMin << " to " << tempMax << " degrees Celsius\n";

    //creating the environment to test
     Environment* test_environment = new Environment(environmentType, foodLevel, tempMin, tempMax);

 //basically main
    //any functions in here should return here when finished and eventually complete this function ending the test

    //display correctly copied values!
    cout << "\nInitial State of Environment:\n";
    cout << "Expected: Day 15, Min Temp 0, Max Temp 35" << endl;
    test_environment->printSummary();

    //test getMaxFoodLevel()
    cout << "\nTesting getMaxFoodLevel():\n";
    cout << "Expected: 15\n";
    cout << "Max Food Level: " << test_environment->getMaxFoodLevel() << "\n";

    //test getCurrentFoodLevel()
    cout << "\nTesting getCurrentFoodLevel():\n";
    cout << "Expected: 15\n";
    cout << "Current Food Level: " << test_environment->getCurrentFoodLevel() << "\n";

    //test subtractFoodLevel()
    cout << "\nTesting subtractFoodLevel():\n";
    cout << "Subtracting 5.0 units of food...\n";
    test_environment->subtractFoodLevel(5.0);
    cout << "Expected: 10\n";
    cout << "Current Food Level: " << test_environment->getCurrentFoodLevel() << "\n";

    //test dayPasses() with print enabled
    cout << "\nTesting dayPasses() with detailed output:\n";
    cout << "Expected: Day 16, Min 0.5, Max 35.5\n";
    test_environment->dayPasses(true);
    
    //test parseSeason()
    cout << "\nTesting parseSeason():\n";
    int testDay = 10;
    cout << "Expected: Late Winter\n";
    cout << "Season on day " << testDay << ": " << Environment::parseSeason(testDay) << "\n";

    //test advancing multiple days
    cout << "\nTesting multiple days passing:\n";
    for (int i = 0; i < 5; i++) {
        test_environment->dayPasses(false); // Advance a day without printing
    }
    cout << "State after advancing 5 days:\n";
    cout << "Expected: Day 21, Min 3, Max 38\n";
    test_environment->printSummary();

    //test advancing one year
    cout << "\nTesting advancing one year:\n";
    cout << "Expected: Day 21, Min 3, Max 38\n";
    for(int i = 0; i < 60; i++){
        test_environment->dayPasses(false);
    }
    test_environment->printSummary();

    //everything after this should be after test functions have finished, execution can leave this function but should return back 

    //clean up memory
    delete test_environment;

    cout << "Test has completed!\n";
}