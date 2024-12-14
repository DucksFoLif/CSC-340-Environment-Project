#include <iostream>
#include "Driver.h"
#include "Environment.h"
#include "Animal.h"
#include "Tester.h"
#include "Node.h"
#include "LinkedList.h"
using namespace std;

//cl Main.cpp LinkedList.cpp Environment.cpp Tester.cpp Node.cpp Animal.cpp Driver.cpp Herbivore.cpp

int main()
{
  cout << "Hello! This is a program that simulates animals living, fighting for survival, and evolving in different environments!\n" << 
          "To get Started, let's choose what type of environment you want your first animals to live in:" << endl;
  
  Environment* chosen_environment = Driver::chooseEnvironment();

  int defaultStats[] = {0, 128, 128, 128, 128};

  //change later to let the user choose from a list
  //crashes before this
  string animalName = "Deer";
  chosen_environment -> addPopulation(animalName, 3, defaultStats);

  //at this point environment has a population, and animals inside it
  Driver::initiateMenu(chosen_environment);
}