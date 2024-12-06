#include <iostream>
#include <string>
#include "Driver.h"
#include "Environment.h"

using namespace std;

enum Options {QUIT, NEW_ENVIRO, SIMULATE, STATS};

void Driver::initiateMenu(Environment* Enviro){
    int input;
    cout << "Choose an option:\n" << 
            "(" << QUIT << "): Quit the program.\n" <<
            "(" << NEW_ENVIRO << "): Load a new Environment.\n"
            "(" << SIMULATE << "): Simulate one or more days of the program.\n"
            "(" << STATS << "): View Statistics about your simulation.\n" << endl;
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
            //Show statistics about the environment (# of animals in each population, day of year, temperatures)
            cout << "Coming soon!" << endl;
            break;
    }
    if(inp != QUIT){
        Driver::initiateMenu(Enviro);
    }
}
