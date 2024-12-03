#include "Environment.h"
#include <iostream>

using namespace std;

/*std::string name; //"desert" "forest" etc.
        int dayOfYear; //1-120 (30/season)
        int maxFoodLevel; //1-100
        double currentFoodLevel; //1-100
        int naturalCamo; //1-100
        double tempMin; //celsius ish
        double tempMax; //celsius ish*/

Environment::Environment() : name("default environment"), dayOfYear(15), maxFoodLevel(50), currentFoodLevel(maxFoodLevel),
naturalCamo(0), tempMin(0), tempMax(10) {}

Environment::Environment(string templateId){} //write later to take string from a predetermined .txt file and use that 

Environment::Environment(std::string environmentType, int foodLevel, double tempMin, double tempMax){
    name = environmentType;
    dayOfYear = 15;
    maxFoodLevel = foodLevel;
    currentFoodLevel = foodLevel;
    tempMin = tempMin;
    tempMax = tempMax;
}

void Environment::dayPasses(bool print){ //very important function, split into 4 phases
    //Print parameter will print everything about the day, logs of everything that happen. Most useful when only iterating over 1 day
    //When iterating over multiple days at a time, print should be false

    //Phase 1: Environment Changes
    dayOfYear++;
    if(dayOfYear > 60){ dayOfYear = 1; } //Resets year
    if(dayOfYear < 8){ tempMin--; tempMax--; } //7 days, Beginning of winter, temp drops by 1 daily
    if(dayOfYear > 8 && dayOfYear < 16){ tempMin++; tempMax++; } //7 days, Ending of winter, temp rises by 1 daily
    if(dayOfYear > 15 && dayOfYear < 31){ tempMin += 0.5; tempMax += 0.5; } //15 days, Entirety of spring, temp raises by 0.5 daily
    if(dayOfYear > 30 && dayOfYear < 38){ tempMin += 0.5; tempMax++; } //7 days, Beginning of summer, max temp raises by 1, min by 0.5
    if(dayOfYear > 38 && dayOfYear < 46){ tempMin -= 0.5; tempMax--; } //7 days, End of summer, max temp decreases by 1, min by 0.5
    if(dayOfYear > 45){ tempMin-= 0.5; tempMax-=0.5;} //15 days, Entirety of autumn, temp decreases by 0.5 daily
    //god i wish you could do ranges for switch statements it would be so awesome it would be so cool


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

