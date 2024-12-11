#include <iostream>
#include "Environment.h"

using namespace std; //thank you 

/*std::string name; //"desert" "forest" etc.
        int dayOfYear; //1-120 (30/season)
        int maxFoodLevel; //1-100
        double currentFoodLevel; //1-100
        int naturalCamo; //1-100
        double tempMin; //celsius ish
        double tempMax; //celsius ish*/

Environment::Environment() {
    this -> name = "default environment";
    this -> dayOfYear = 15;
    this -> maxFoodLevel = 50;
    this -> currentFoodLevel = maxFoodLevel;
    this -> naturalCamo = 0;
    this -> tempMin = 0;
    this -> tempMax = 10;
}

// Environment::Environment(string templateId){} //write later to take string from a predetermined .txt file and use that 

Environment::Environment(string environmentType, int foodLevel, double tempMin, double tempMax){
    this -> name = environmentType;
    this -> dayOfYear = 15;
    this -> maxFoodLevel = foodLevel;
    this -> currentFoodLevel = foodLevel;
    this -> tempMin = tempMin;
    this -> tempMax = tempMax;

    //TEST DELETE LATER
    {
        int stats[4] = {0,128, 128, 128};
        this -> one =  new Herbivore(stats);
        this -> two = new Herbivore(stats);
    }
    //TEST DELETE LATER

}

Environment::~Environment()
{
  //eventually loop through and delete all animals

}

void Environment::dayPasses(bool print){ //very important function, split into 4 phases
    //Print parameter will print everything about the day, logs of everything that happen. Most useful when only iterating over 1 day
    //When iterating over multiple days at a time, print should be false

    //Phase 1: Environment Changes
    dayOfYear++;
    
    if(dayOfYear > 60){ dayOfYear = 1; } //Resets year

    string season = parseSeason(dayOfYear);

    if(season == "Early Winter"){tempMin--; tempMax--;} //early winter decreases both by 1 per day
    //Mid Winter does not incriment temperature
    if(season == "Late Winter"){tempMin++; tempMax++;} //late winter increases both by 1 per day
    if(season == "Spring"){tempMin+=0.5; tempMax+=0.5;} //spring increases both by 0.5 per day
    if(season == "Early Summer"){tempMax++; tempMin+=0.5;} //early summer increases max by 1 and min by 0.5 per day
    //Mid Summer does not incriment temperature
    if(season == "Late Summer"){tempMax--; tempMin-=0.5;} //late summer decreases max by 1 and min by 0.5 per day
    if(season == "Autumn"){tempMax-=0.5; tempMin-=0.5;} //autumn decreases both by 0.5 per day

    //Phase 2: Grazing Phase

    //TEST DELETE LATER
    //animals eat
    setCurrentFoodLevel(one -> eat(getCurrentFoodLevel()));
    setCurrentFoodLevel(two -> eat(getCurrentFoodLevel()));

    //food replenishes
    if ((getCurrentFoodLevel() * 1.4 + 10) < getMaxFoodLevel()) setCurrentFoodLevel(getCurrentFoodLevel() *1.5 + 20);
    else setCurrentFoodLevel(getMaxFoodLevel()); 
    
    //TEST DELETE LATER


    //Part 1: Organize list based on priority
    //Part 2: Run Individual grazing checks for each animal?
    //Part 3: Decrement the food supply to reflect
    
    //Phase 3: Hunting Phase
    //Part 1: Organize list based on priority
    //Part 2: Figure out which animals are hungry
    //Part 3: Run hunting checks for said animals

    //Phase 4: Breeding Phase
    
    if (print == true)
    {
      this -> printSummary();
    }
}


int Environment::getMaxFoodLevel() const{
    return maxFoodLevel;
}

void Environment::setCurrentFoodLevel(double newLevel)
{
  this -> currentFoodLevel = newLevel;
}

double Environment::getCurrentFoodLevel() const{
    return currentFoodLevel;
}

void Environment::subtractFoodLevel(double amount){
    this->currentFoodLevel = this->currentFoodLevel - amount;
}

int Environment::getCurrentDayOfYear() const
{
  return dayOfYear;
}

void Environment::printSummary()
{
  for (int i = 0; i < 20; i++) cout <<"-";
  cout <<"\nThe current day is: " << this -> getCurrentDayOfYear() << "\n";
  cout << "The current min temperature is: " << tempMin << "\n";
  cout << "The current max temperature is: " << tempMax << "\n";
  //Eventually will add the LinkedList of certain animals
  for (int i = 0; i < 20; i++) cout <<"-";
  cout << endl;
  //FIX ME
}

string Environment::parseSeason(int dayOfYear){
  if(dayOfYear < 7){return "Early Winter";} //Days 1-6
    else if(dayOfYear > 6 && dayOfYear < 10){return "Mid Winter";} //Days 7-9
    else if(dayOfYear > 9 && dayOfYear < 16){return "Late Winter";} //Days 10-15
    else if(dayOfYear > 15 && dayOfYear < 31){return "Spring";} //Days 16-30
    else if(dayOfYear > 30 && dayOfYear < 37){return "Early Summer";} //Days 31-36
    else if(dayOfYear > 36 && dayOfYear < 40){return "Mid Summer";} //Days 37-39
    else if(dayOfYear > 39 && dayOfYear < 46){return "Late Summer";} //Days 40-45
    else if(dayOfYear > 45){return "Autumn";} //Days 46-60
    return "You should never get this value";

}