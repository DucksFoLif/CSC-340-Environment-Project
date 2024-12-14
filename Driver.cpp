#include <iostream>
#include <string>
#include "Driver.h"
#include "Environment.h"
#include "Tester.h"

using namespace std;

enum Options {QUIT = 0, NEW_ENVIRO, SIMULATE, YEAR, STATS, ADD_ANIMAL, TESTER};

void Driver::initiateMenu(Environment* Enviro){
    int input;
    cout << "Choose an option:\n" << 
            "(" << QUIT << "): Quit the program.\n" <<
            "(" << NEW_ENVIRO << "): Load a new Environment.\n"
            "(" << SIMULATE << "): Simulate days of the program.\n"
            "(" << YEAR << "): Simulate one year (60 days) of the program.\n"
            "(" << STATS << "): View Statistics about your simulation.\n"
            "(" << ADD_ANIMAL << "): Add An Animal Species to the environment.\n"
            "(" << TESTER << "): Test Simulation behavior.\n" << endl;

    cin >> input;
    //print menu option and gather output
    Driver::parseMenuInput(Enviro, input);
    //parse menu output, call appropriate functions (when they exist), and then call initiateMenu again
    //im not sure if this will cause issues because you keep essentially recursively calling this function
    //if it is we can just put a loop in main to forever call this function but then this function needs to return the Environment

}

void Driver::parseMenuInput(Environment* Enviro, int inp){
    switch(inp){
        case QUIT:
            cout << "Thank you, bye!" << endl;
            //The check at the bottom of this function will check & terminate program if QUIT is entered
            break;
        case NEW_ENVIRO:
            //Driver::loadNewEnviro;
            cout << "Coming soon!" << endl;
            break;
        case SIMULATE:
            // function that starts a certain amount of days
            Driver::initiateSimulater(Enviro);
            break;
        case YEAR:
            for(int i = 0; i < 60; i++){
                Enviro->dayPasses(false);
            }
            break;
        case STATS:
            //Show statistics about the environment (# of animals in each LinkedList, day of year, temperatures)
            cout << "Coming soon!" << endl;
            break;
        case ADD_ANIMAL:
            //need to make the .csv, and add the function to read in from it
            cout << "Coming soon!" << endl;
            Driver::initiateAddNewSpecies(Enviro);
            break;
        case TESTER:
            startTester();
            break;

    }
    if(inp != QUIT){
        Driver::initiateMenu(Enviro);
    }
	//if it reaches this point it should quit, so we gotta make sure we delete any dynamically allocated objects
}

void Driver::startTester()
{
    //initiate tester program
    Tester *tester = new Tester;

    cout << "Starting tester!\n";
    tester -> initiateTester();

    delete tester;
    cout << "Ended Testing!\n";
}


Environment* Driver::chooseEnvironment()
{    
    // finish this as an option
    cout << "Choosing Environments is in the works. We will give you a desert environment to start." << endl;
    Environment* returnEnvironment = new Environment("desert", 150, 0.0, 35.0);

    return returnEnvironment;


}


void Driver::initiateAddNewSpecies(Environment* Enviro)
{
    //Enviro -> addPopulation();
}

void Driver::initiateSimulater(Environment* Enviro)
{
    cout << "How many days would you like to Simulate: ";

    int daysChosen = 0;
    cin >> daysChosen;

    for(int i = 0; i < daysChosen; i++)
    {
        Enviro -> dayPasses(true);
        cout << "Press enter to go to next day:";
        cin.get();
    }

}