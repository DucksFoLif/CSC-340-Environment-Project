#ifndef NODE_H
#define NODE_H

#include <string>

class Environment{
    private:
        //Population[] popArr (i forget the syntax for arrays)
        int dayOfYear; //1-120
        int maxFoodLevel; //1-100
        double currentFoodLevel; //1-100
        int naturalCamo; //1-100
        double tempMin; //celsius ish
        double tempMax; //celsius ish

    public:
        Environment();
        Environment(string templateId);
        Environment(string environmentType, int foodLevel, double tempMin, double tempMax);
        ~Environment();

        int getMaxFoodLevel() const;
        double getCurrentFoodLevel() const;
        void subtractFoodLevel(double amount);
        //not sure which other attributes we will need getters and setters for yet, perhaps add as needed
        
        void dayPasses(); //basic method to iterate a day in the simulation
        void printSummary(); //prints day of year, temp, summary of animal populations
        //void addPopulation(Population pop); //add a new animal population (commented until population is created)
};

#endif