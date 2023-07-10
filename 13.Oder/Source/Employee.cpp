/*
* File: Employee.cpp
* Author: Nguuyen Hung Giao
* Date: 07/07/2023
* Dexcription: This is source file for class Employee
*/

#include "Employee.hpp"

/*********************Class Employee*********************/

Employee::Employee(list <Food> database, uint8_t notab){
    if(notab == 0 && database.size() == 0){
        cout<<"No information"<<endl;
    }else{
        for (uint8_t i = 0; i <= notab; i++)
        {
            inforTab tab(i, false);
            database_table.push_back(tab);
        }
        database_dishes.assign(database.begin(), database.end());
    }
    chooseTab();
}

/*
* Class: Employee
* Function: chooseTab
* Description: This function is use choose table
* Input:
*   Don't have input parameters
* Output:
*   return: None
*/  
void Employee::chooseTab(){
    EMPLOYEE(notab, "--TABLE SELECTION--", "Enter number of table: ");
    for(auto item : database_table){
        item.getTabnum() == notab;
        uint8_t key;
        do
        {
            cout<<"Enter selection: ";
            cin>>key;
        } while (key > 5 && key <0);
        switch ((employ)key)
        {
        case ADDITION:
            addFood();
            break;
        case MODIFY: 
            modifyFood();
            break;
        case ERASE: 
            eraseFood();
            break;
        case PAY:
            foodList();
            break;
        case LIST: 
            Pay();
            break;
        default:
            break;
        }
    }
}


/*
* Class: Employee
* Function: addFood
* Description: This function is use add dishes at the table
* Input:
*   Don't have input parameters
* Output:
*   return: None
*/  
void Employee::addFood(){
    EMPLOYEE(notab, "--ADD DISHES AT THE TABLE--", "Enter number of table: ");
    FOR_EMPLOY(item.addDishes());
}

/*
* Class: Employee
* Function: modifyFood
* Description: This function is use modify the dishes on the table
* Input:
*   Don't have input parameters
* Output:
*   return: None
*/  
void Employee::modifyFood(){
    EMPLOYEE(notab, "--MODIFY THE DISHES ON THE TABLE--", "Enter number of table: ");
    FOR_EMPLOY(item.modifyDishes());
}

/*
* Class: Employee
* Function: eraseFood
* Description: This function is use erase dishes from the table
* Input:
*   Don't have input parameters
* Output:
*   return: None
*/  
void Employee::eraseFood(){
    EMPLOYEE(notab, "--ERASE DISHES FROM THE TABLE--", "Enter number of table: ");
    FOR_EMPLOY(item.eraseDishes());
}

/*
* Class: Employee
* Function: foodList
* Description: This function is use display dishes list on the table
* Input:
*   Don't have input parameters
* Output:
*   return: None
*/  
void Employee::foodList(){
    EMPLOYEE(notab, "--FOOD LIST ON THE TABLE--", "Enter number of table: ");
    FOR_EMPLOY(item.dishesList());
}

/*
* Class: Employee
* Function: Pay
* Description: This function is use payment dish on the table
* Input:
*   Don't have input parameters
* Output:
*   return: None
*/  
void Employee::Pay(){
    EMPLOYEE(notab, "--PAYMENT--", "Enter number of table: ");
    FOR_EMPLOY(item.payment());
}