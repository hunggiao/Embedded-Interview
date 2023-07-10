/*
* File: inforTab.hpp
* Author: Nguuyen Hung Giao
* Date: 07/07/2023
* Dexcription: This is header file for class inforTab
*/

#ifndef INFORTAB_H
#define INFORTAB_H

#include <iostream>
#include <list>
#include "Food.hpp"
using namespace std;
#define INFOR(content1, content2)\
    cout<<content1<<endl;\
    cout<<content2;

class inforTab{
    private:
        uint8_t tabnum;
        bool status;
        typedef struct{
            Food dish;
            uint8_t quanlity;
        }typeDishes;
        list <typeDishes> database_dishes;
    public:
        inforTab(uint8_t TABNUM, bool STATUS);
        uint8_t getTabnum();
        void setStatus(bool STATUS);
        bool getStatus();
        
        void addDishes();
        void modifyDishes();
        void eraseDishes();
        void dishesList();
        void payment();
};

#endif // INFORTAB_H