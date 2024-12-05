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

Environment::Environment(std::string environmentType, int foodLevel, double tempMin, double tempMax){
    this -> name = environmentType;
    this -> dayOfYear = 15;
    this -> maxFoodLevel = foodLevel;
    this -> currentFoodLevel = foodLevel;
    this -> tempMin = tempMin;
    this -> tempMax = tempMax;
}

void Environment::dayPasses(bool print){ //very important function, split into 4 phases
    //Print parameter will print everything about the day, logs of everything that happen. Most useful when only iterating over 1 day
    //When iterating over multiple days at a time, print should be false

    //Phase 1: Environment Changes
    dayOfYear++;
    
    if(dayOfYear > 60){ dayOfYear = 1; } //Resets year
    
    if(dayOfYear < 8){ tempMin--; tempMax--; } //7 days, Beginning of winter, temp drops by 1 daily
    else if(dayOfYear > 8 && dayOfYear < 16){ tempMin++; tempMax++; } //7 days, Ending of winter, temp rises by 1 daily
    else if(dayOfYear > 15 && dayOfYear < 31){ tempMin += 0.5; tempMax += 0.5; } //15 days, Entirety of spring, temp raises by 0.5 daily
    else if(dayOfYear > 30 && dayOfYear < 38){ tempMin += 0.5; tempMax++; } //7 days, Beginning of summer, max temp raises by 1, min by 0.5
    else if(dayOfYear > 38 && dayOfYear < 46){ tempMin -= 0.5; tempMax--; } //7 days, End of summer, max temp decreases by 1, min by 0.5
    else if(dayOfYear > 45){ tempMin-= 0.5; tempMax-=0.5;} //15 days, Entirety of autumn, temp decreases by 0.5 daily
    //god i wish you could do ranges for switch statements it would be so awesome it would be so cool
    //you can if you hate time! or you could use inline assembly (I think)


    //Phase 2: Grazing Phase
    
    
    

    //Phase 3: Hunting Phase

    //Phase 4: Breeding Phase
}


int Environment::getMaxFoodLevel() const{
    return maxFoodLevel;
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
  
  //FIX ME
}

