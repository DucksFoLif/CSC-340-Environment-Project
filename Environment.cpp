#include <iostream>
#include <string>
#include "Environment.h"
#include "LinkedList.h"
#include "Node.h"


using namespace std; //thank you 

const int HUNGER_TAKEN_PER_DAY = 3;

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
    this -> currentFoodLevel = 50.0;
    this -> naturalCamo = 0;
    this -> tempMin = 0;
    this -> tempMax = 10;

    this -> population = new LinkedList();
}

// Environment::Environment(string templateId){} //write later to take string from a predetermined .txt file and use that 

Environment::Environment(string environmentType, int foodLevel, double tempMin, double tempMax){
    this -> name = environmentType;
    this -> dayOfYear = 15;
    this -> maxFoodLevel = foodLevel;
    this -> currentFoodLevel = (double)foodLevel;
    this -> tempMin = tempMin;
    this -> tempMax = tempMax;

    this -> population = new LinkedList();
}

Environment::~Environment()
{
  delete population;
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
    

    //food replenishes
    if ((getCurrentFoodLevel() * 1.4 + 10) < getMaxFoodLevel()) setCurrentFoodLevel(getCurrentFoodLevel() *1.5 + 20);
    else setCurrentFoodLevel(getMaxFoodLevel()); 
    
    //TEST DELETE LATER
    //Part 1: Organize list based on priority'

    //subtract food from each animal and check if dead
      Node *iterator = ((this -> population) -> getHead());

      while (iterator != nullptr) 
      {
        Animal* animal = iterator->getData();
        animal->setFullness(animal->getFullness() - HUNGER_TAKEN_PER_DAY);

        //DEBUG
        cout <<endl <<  animal -> getFullness() << endl;
        cout << getCurrentFoodLevel() << endl;

        if (animal->getFullness() <= 0) {
            // Prepare to remove the current node
            Node* toDelete = iterator;
            iterator = iterator->getNext();  // Advance the iterator before deletion
            this->population->removeAnimal(toDelete->getData());
        } else {
            iterator = iterator->getNext();  // Move to the next node
        }
    }
    

    //attempt to eat
      iterator = (this -> population) -> getHead();

      while (iterator != nullptr)
      {
        setCurrentFoodLevel((iterator -> getData()) -> eat(getCurrentFoodLevel()));
        iterator = iterator -> getNext();
      }

    
  


    //Part 2: Run Individual grazing checks for each animal?

    //Part 3: Decrement the food supply to reflect
    
    //Phase 3: Hunting Phase
    //Part 1: Organize list based on priority
    //Part 2: Figure out which animals are hungry
    //Part 3: Run hunting checks for said animals

    //Phase 4: Reproduction Phase
    Node* temp;
    temp = population->getHead();
    while(temp){
      if((rand()%10000) + temp->getData()->getAppealSkill() >= 9990){
        cout << "Something has reproduced!!\n";
        population->addAnimal(temp->getData()->reproduce());
      }
      temp = temp->getNext();
    }
    
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
  cout << "\nThe current animals in the environment are: \n";
  cout << (this -> population) -> getSize() << " " << (this -> population)->getSpeciesName() << "(s)" << endl;
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

void Environment::addPopulation(string& speciesName, int numToAdd, int* givenStats){
  /*if (this->population) {
    delete this->population;
  }*/
  this -> population = new LinkedList(speciesName);

  Animal* ani = nullptr;
  for(int i = 0; i < numToAdd; i++){
    ani = new Herbivore(givenStats);
    (this -> population) -> addAnimal(ani);
  }
}