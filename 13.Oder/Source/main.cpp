/*
* File: main.cpp
* Author: Nguuyen Hung Giao
* Date: 07/07/2023
* Dexcription: This is source file for main program
*/

#include <iostream>
#include <list>
#include "Manager.hpp"
#include "Employee.hpp"

typedef enum{
    MANAGER,
    EMPLOYEE
}menu;

int main(int argc, char const *argv[])
{   
    uint8_t key;
    do
    {
        cout<<"--ORDER PROGRAM--"<<endl;
        cout<<"1. MANAGER"<<endl;
        cout<<"2. EMPLOYEE"<<endl;
        cout<<"Please choose key: ";
        cin>>key;
    } while (key != 1 && key != 2);
    
    switch ((menu)key){
        case MANAGER:
            Manager ql();
            break;
        case EMPLOYEE:
            Employee nv();
            break;
    }
    return 0;
}
