#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include "Environment.h"
#include "Driver.h"

using namespace std;

enum Options {QUIT = 0, NEW_ENVIRO, SIMULATE, YEAR, STATS, ADD_ANIMAL, TESTER};

class Environment;

class Driver
{
  //string 2ints 2 doubles

  public:
    static void initiateMenu(Environment* Enviro);
    static void parseMenuInput(Environment* Enviro, int inp);
    static void startTester();
    static Environment* chooseEnvironment();
    static void initiateAddNewSpecies(Environment* Enviro);
    static void initiateSimulater(Environment* Enviro);
  
};




#endif // DRIVER_H