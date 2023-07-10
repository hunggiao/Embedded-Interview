/*
* File: Manager.hpp
* Author: Nguuyen Hung Giao
* Date: 07/07/2023
* Dexcription: This is header file for class Manager
*/

#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <list>
#include "Food.hpp"
using namespace std;

class Manager{
    private:
        list<Food> database;
        uint8_t noTab;
        void addDishes();
        void modifyDishes();
        void eraseDishes();
        void listDishes();
        void noTable();
    public:
        Manager();
        list <Food> getdatabase();
        uint8_t getNotab();
};

typedef enum{
    ADD_DISHES,
    MODIFY_DISHES,
    ERASE_DISHES,
    LIST_DISHES,
    TAB_NUMBER,
    OUT
}manager;

#endif // MANAGER_H