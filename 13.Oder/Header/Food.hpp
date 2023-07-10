/*
* File: Food.hpp
* Author: Nguuyen Hung Giao
* Date: 07/07/2023
* Dexcription: This is header file for class Food
*/

#ifndef FOOD_H
#define FOOD_H

#include<iostream>
using namespace std;

class Food{
    private:
        uint8_t id;
        string name;
        double cost;
    public:
        Food();
        void setName(string NAME);
        void setCost(double COST);

        string getName();
        double getCost();
        uint8_t getid();
};

#endif // FOOD_H