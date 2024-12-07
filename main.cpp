#include <iostream>
#include "Driver.h"
#include "Environment.h"
#include "Animal.h"
#include "Tester.h"
using namespace std;

int main()
{
  cout << "Hello! This is a program that simulates animals living, fighting for survival, and evolving in different environments!\n" << 
          "To get Started, let's choose what type of environment you want your first animals to live in:" << endl;
  
  Environment* chosen_environment =  Driver::chooseEnvironment();
  //Function here to give them a list of options in the default environment .txt file, and then have them choose and load that one

  Driver::initiateMenu(chosen_environment);
}