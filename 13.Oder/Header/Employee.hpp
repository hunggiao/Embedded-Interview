/*
* File: Employee.hpp
* Author: Nguuyen Hung Giao
* Date: 07/07/2023
* Dexcription: This is header file for class Employee
*/

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <list>
#include "Food.hpp"
#include "inforTab.hpp"
using namespace std;
#define EMPLOYEE(property, content1, content2)\
    uint8_t property;\
    cout<<content1<<endl;\
    cout<<content2;\
    cin>>property;

#define FOR_EMPLOY(content)\
    for(auto item : database_table){\
        if(item.getTabnum() == notab){\
            content;\
        }\
    }

typedef enum{
    ADDITION,
    MODIFY,
    ERASE,
    PAY,
    LIST
}employ;

class Employee{
    private:
        list <Food> database_dishes;
        list <inforTab> database_table;
        void addFood();
        void modifyFood();
        void eraseFood();
        void Pay();
        void chooseTab();
        void foodList();
    public:
        Employee(list<Food> database, uint8_t notab);

};

#endif // EMPLOYEE_H