/*
* File: Manager.cpp
* Author: Nguuyen Hung Giao
* Date: 07/07/2023
* Dexcription: This is source file for class Manager
*/

#include "Manager.hpp"
#include <string>
using namespace std;

/*********************Class Manager*********************/
Manager::Manager(){
    uint8_t key;
    
    cout<<"--FOOD MANAGEMENT--"<<endl;
    cout<<"1. ADD DISHES"<<endl;
    cout<<"2. MODIFY DISHES"<<endl;
    cout<<"3. ERASE DISHES"<<endl;
    cout<<"4. FOOD LIST"<<endl;
    cout<<"5. SET TABLE NUMBERS"<<endl;
    cout<<"6. OUT"<<endl;
    cout<<"-------------------"<<endl;
    do
    {
        cout<<"Please choose key: ";
        cin>>key;
        cin.ignore();
    } while (key < 1 || key > 6);
    
    switch ((manager)key)
    {
        case ADD_DISHES:
            addDishes();
            break;
        case MODIFY_DISHES:
            modifyDishes();
            break;
        case ERASE_DISHES: 
            eraseDishes();
            break;
        case LIST_DISHES: 
            listDishes();
            break;
        case TAB_NUMBER:
            noTable();
            break;
        case OUT:
            exit(0);
        default:
            break;
        }
}

 /*
* Class: Manager
* Function: getdatabase
* Description: This function use for get database of a class Food
* Input:
*   class Food
* Output:
*   return: database
*/   
list <Food> Manager::getdatabase(){
    return this->database;
}

 /*
* Class: Manager
* Function: getNotab
* Description: This function use for get number of tables
* Input:
*   Dont have input parameters
* Output:
*   return: database
*/   
uint8_t Manager::getNotab(){
    return this->noTab;
}

/*
* Class: Manager
* Function: addDishes
* Description: This function use for add dishes of menu
* Input:
*   Dont have input parameters
* Output:
*   return: None
*/   
void Manager::addDishes(){
    cout<<"--ADD DISHES--"<<endl;
    string name;
    double cost;

    do{
        cin.ignore();
        cout<<"Enter name of dish: ";
        getline(cin, name);
    } while (name.empty());
    
    do
    {
        cout<<"Enter cost of dish: ";
        cin>>cost;
        cin.ignore();
    } while (cost < 0);
    
    Food themmon;
    themmon.setName(name);
    themmon.setCost(cost);
    database.push_back(themmon);
    cout<<themmon.getid()<<endl;
    cout<<"Add success!"<<endl;
    cout<<"---------------"<<endl; 
}


/*
* Class: Manager
* Function: modifyDishes
* Description: This function use for modify dishes of menu
* Input:
*   Dont have input parameters
* Output:
*   return: None
*/   
void Manager::modifyDishes(){
    uint8_t id;
    string name;
    double cost;
    bool haveDishes = false;
    uint8_t key;
    cout<<"--MODIFY DISHES BY ID CODE--"<<endl;
    cout<<"Enter ID code: ";
    cin>>id;
    for (auto &item : database)
    {
        if (item.getid() == id)     
        {
            cout<<"Select the information you want to edit"<<endl;
            cout<<"1. Dist name"<<endl;
            cout<<"2. Cost"<<endl;

            do
            {
                cout<<"Choose key: ";
                cin>>key;      
            } while (0);

            switch (key)
            {
            case 1:
                do{
                    cin.ignore();
                    cout<<"Enter name of dishes: ";
                    getline(cin, name);
                } while (name.empty());
                item.setName(name);
                break;
            case 2:
                do
                {
                    cout<<"Enter cost of dishes: ";
                    cin>>cost;
                    cin.ignore();
                } while (cost < 0);
                item.setCost(cost);
                break;
            default:
                cout<<"There is no suitable option!"<<endl;
                break;
            }
            haveDishes = 1;
            break;
        }
        if(haveDishes != 1) cout<<"Can't find dishes with id code: "<<id<<endl;
    }
}


/*
* Class: Manager
* Function: eraseDishes
* Description: This function use for erase dishes of menu
* Input:
*   Dont have input parameters
* Output:
*   return: None
*/   
void Manager::eraseDishes(){
    uint8_t id;
    bool haveDishes = false;
    auto position = database.begin();
    cout<<"--ERASE DISHES BY ID CODE--"<<endl;
    cout<<"Enter id code: ";
    cin>>id;
    for (auto temp : database)
    {
        if(temp.getid() == id){
            database.erase(position);
            haveDishes = 1;
            cout<<"Successfully deleted item!"<<endl;
            break;
        }
        position++;
    }
    if(haveDishes != 1) cout<<"Can't find dishes with id code: "<<id<<endl;   
}


/*
* Class: Manager
* Function: listDishes
* Description: This function is used to display the list of dishes
* Input:
*   Dont have input parameters
* Output:
*   return: None
*/   
void Manager::listDishes(){
    if(database.empty()){
        cout<<"--EMPTY DISHES LIST--"<<endl;
    }else{
        cout<<"--DISHES LIST--"<<endl;
        for (Food temp : database)
        {
            cout<<"ID: "<<temp.getid()<<endl;
            cout<<"NAME: "<<temp.getName()<<endl;
            cout<<"COST: "<<temp.getCost()<<endl;
            cout<<"_______________________"<<endl;
        }
    }
}

/*
* Class: Manager
* Function: noTab
* Description: This function is use set number of tables of menu
* Input:
*   Dont have input parameters
* Output:
*   return: None
*/   
void Manager::noTable(){
    cout<<"--SETTING NUMBER OF TABLE--"<<endl;
    cout<<"Enter number of table: ";
    cin>>noTab;
    cin.ignore();
}