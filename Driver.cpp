#include <iostream>
#include <string>
#include "Driver.h"
#include "Environment.h"
#include "Tester.h"

using namespace std;

enum Options {QUIT = 0, NEW_ENVIRO, SIMULATE, STATS, TESTER, ADD_NEW_SPECIES};

void Driver::initiateMenu(Environment* Enviro){
    int input;
    cout << "Choose an option:\n" << 
            "(" << QUIT << "): Quit the program.\n" <<
            "(" << NEW_ENVIRO << "): Load a new Environment.\n"
            "(" << SIMULATE << "): Simulate one or more days of the program.\n"
            "(" << STATS << "): View Statistics about your simulation.\n"
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
            Enviro->dayPasses(true);
            //Eventually add a function that asks the user how many days to run, and then runs that many days
            break;
        case STATS:
            //Show statistics about the environment (# of animals in each LinkedList, day of year, temperatures)
            cout << "Coming soon!" << endl;
            break;
        case TESTER:
            startTester();
            break;

        case ADD_NEW_SPECIES:
            Driver::initiateAddNewSpecies(Enviro);
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
    Environment* returnEnvironment = new Environment("desert", 15, 0.0, 35.0);

    return returnEnvironment;


}


void Driver::initiateAddNewSpecies(Environment* Enviro)
{
    //Enviro -> addNewSpecies();
}