/*
* File: Food.cpp
* Author: Nguuyen Hung Giao
* Date: 07/07/2023
* Dexcription: This is source file for class Food
*/

#include "Food.hpp"

/*********************Class Food*********************/
Food::Food(){
    static int Id = 100;
    Food::id = Id;
    Id ++;
}

/*
* Class: Food
* Function: setName
* Description: This function use for set name of a food
* Input:
*   name - NAME of food
* Output:
*   return: None
*/
void Food::setName(string NAME){
    name = NAME;
}

/*
* Class: Food
* Function: setCost
* Description: This function use for set cost of a food
* Input:
*   cost - COST of food
* Output:
*   return: None
*/
void Food::setCost(double COST){
    cost = COST;
}

/*
* Class: Food
* Function: getName
* Description: This function use for get name of a food
* Input:
*   Dont have input parameters
* Output:
*   return: name
*/
string Food::getName(){
    return name;
}

/*
* Class: Food
* Function: getCost
* Description: This function use for get cost of a food
* Input:
*   Dont have input parameters
* Output:
*   return: cost
*/
double Food::getCost(){
    return cost;
}

/*
* Class: Food
* Function: getid
* Description: This function use for get id of a food
* Input:
*   Dont have input parameters
* Output:
*   return: id
*/
uint8_t Food::getid(){
    return id ;
}