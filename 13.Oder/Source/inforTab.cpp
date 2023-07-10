/*
* File: inforTab.cpp
* Author: Nguuyen Hung Giao
* Date: 07/07/2023
* Dexcription: This is source file for class inforTab
*/

#include "inforTab.hpp"

/*********************Class inforTab*********************/

inforTab::inforTab(uint8_t TABNUM, bool STATUS){
    tabnum = TABNUM;
    status = STATUS;
}

/*
* Class: inforTab
* Function: setStatus
* Description: This function is use set status of table
* Input:
*   status - STATUS
* Output:
*   return: None
*/  
void inforTab::setStatus(bool STATUS){
    status = STATUS;
}

/*
* Class: inforTab
* Function: getStatus
* Description: This function is use get status of table
* Input:
*   Don't have input parameters
* Output:
*   return: status
*/  
bool inforTab::getStatus(){
    return status;
}

/*
* Class: inforTab
* Function: getTabnum
* Description: This function is use get table number
* Input:
*   Don't have input parameters
* Output:
*   return: None
*/  
uint8_t inforTab::getTabnum(){
    return tabnum;
}

/*
* Class: inforTab
* Function: addDishes
* Description: This function is use add dishes of table
* Input:
*   Don't have input parameters
* Output:
*   return: None
*/  
void inforTab::addDishes(){
    Food dish;
    uint8_t num;

    do
    {
        cout<<"Enter number of dish: ";
        cin>>num;
        cin.ignore();
    } while(num < 0);
    typeDishes FOOD;
    FOOD.dish = dish;
    FOOD.quanlity = num;
    database_dishes.push_back(FOOD);
}

/*
* Class: inforTab
* Function: modifyDishes
* Description: This function is use modify dishes of table
* Input:
*   Don't have input parameters
* Output:
*   return: None
*/  
void inforTab::modifyDishes(){
    uint8_t id;
    uint8_t num;
    bool haveMon = false;
    INFOR("--MODIFY DISHES BY ID CODE--", "Enter id code: ");
    cin>>id;
    for(auto &item : database_dishes){
        if(item.dish.getid() == id){
            do
            {
                cout<<"Enter number of dish: ";
                cin>>num;
                cin.ignore();
            } while (num < 0);
            item.quanlity = num;
            break;
        }
        haveMon = 1;
        break;
    }
    if(haveMon != 1) cout<<"Couldn't find a suitable dish!"<<endl;
}

/*
* Class: inforTab
* Function: eraseDishes
* Description: This function is use erase dishes of table
* Input:
*   Don't have input parameters
* Output:
*   return: None
*/  
void inforTab::eraseDishes(){
    uint8_t id;
    bool haveMon = false;
    auto position = database_dishes.begin();
    INFOR("--ERASE DISHES BY ID CODE--", "Enter id code: ");
    cin>>id;
    for(auto item : database_dishes){
        if(item.dish.getid() == id){
            database_dishes.erase(position);
            cout<<"Successfully deleted!"<<endl;
            haveMon = 1;
            break;
        }
        position++;
    }
    if(haveMon != 1) cout<<"Couldn't find a suitable dish!"<<endl;
}


/*
* Class: inforTab
* Function: dishesList
* Description: This function is used to display the dish of tables
* Input:
*   Don't have input parameters
* Output:
*   return: None
*/  
void inforTab::dishesList(){
    if(database_dishes.empty()){
        cout<<"--EMPTY LIST!--"<<endl;
    }else{
        cout<<"--DISHES LIST--"<<endl;
        for(auto item : database_dishes){
            cout<<"ID: "<<item.dish.getid()<<endl;
            cout<<"NAME: "<<item.dish.getName()<<endl;
            cout<<"COST: "<<item.dish.getCost()<<endl;
            cout<<"QUANLITY: "<<item.quanlity<<endl;
        }
    }
}

/*
* Class: inforTab
* Function: payment
* Description: This function is use payment bill
* Input:
*   Don't have input parameters
* Output:
*   return: None
*/  
void inforTab::payment(){
    float total = 0;
    INFOR("--PAY FOR THE DINING TABLE--", "Total payment: ");
    for(auto item : database_dishes){
        total += item.dish.getCost() * item.quanlity;
    }
}