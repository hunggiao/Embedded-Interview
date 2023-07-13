/*
* File: Oder.cpp
* Author: Nguuyen Hung Giao
* Date: 07/07/2023
* Dexcription: This is header file for restaurant management
*/

#include <iostream>
#include <list>
#include <string>
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

/*********************Class Food*********************/
class Food{
    private:
        uint8_t id;
        string name;
        double cost;
    public:
        Food(string Name, double Cost);
        void setName(string NAME);
        void setCost(double COST);

        string getName();
        double getCost();
        uint8_t getid();
};


Food::Food(string Name, double Cost){
    static uint8_t Id = 100;
    Food::id = Id;
    Id ++;
    this->name = Name;
    this->cost = cost;
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

/*********************Class Manager*********************/
class Manager{
    private:
        list<Food> database;
        uint8_t noTab;
        void addDishes();
        void screenMenu();
        void modifyDishes();
        void eraseDishes();
        void listDishes();
        void noTable(uint8_t numofTable);
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
    } while (key < 0 || key > 5);
    
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
    uint8_t choice;
    string name;
    double cost;
    do{
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
        
        Food newFood(name, cost);
        database.push_back(themmon);
        cout << "ID\t" << "Name\t\t" << "Price" << endl;
        cout << newFood.getId() << "." << "\t" << newFood.getName() << "\t\tVND" << newFood.getPrice() << endl;
        cout << "1. Continue to add food" << endl;
        cout << "0. Turn back" << endl;
        cout << "Enter option: \n";
        cin >> choice;
        cout<<"---------------"<<endl;
    } while(choice != 0);
}

/*
* Class: Manager
* Function: screenMenu
* Description: This function use for display dishes of menu
* Input:
*   Dont have input parameters
* Output:
*   return: None
*/  
void screenMenu(){
    cout << "=======Menu=======" << endl;
    cout << "ID\tName\t\tPrice\n";
    for (auto& food : Menu) {
        cout << food.getId() << "." << "\t" << food.getName() << "\t\tVND" << food.getPrice() << endl;
    }
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
    screenMenu();
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
            cout<<"1. Edit Dist name"<<endl;
            cout<<"2. Edit Cost"<<endl;
            cout<<"0. Turn back"<<endl;
            do
            {
                cout<<"Choose key: ";
                cin>>key;      

                switch (key)
                {
                case 0:
                    break;
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
            } while (key != 0)
        }
        if(haveDishes != 1) cout<<"Can't find dishes with id code: "<<id<<endl;
    }
    cout << "Food with Id: " << id << " has been updated\n";
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
void Manager::noTable(uint8_t numofTable){
    this->noTab = numofTable;
    cout<<"--SETTING NUMBER OF TABLE--"<<endl;
    cout<<"Enter number of table: ";
    cin>>noTab;
    cin.ignore();
}

/*********************Class inforTab*********************/
enum statusTable{Open, Close};


class Table {
    public:
        int id;
        statusTable status;
        list<Food> orders;

        Table(int _id);
        void addFood(Food& food);
        void removeFood(int foodId);
        void Bill();
};

Table::Table(int _id) : id(_id) {status = Open;}

void Table::addFood(Food& food) {
    if (status == Close) {
        cout << "Table " << id << " is closed. Cannot add food." << endl;
    }
    else {
        orders.push_back(food);
        cout << "Added \"" << food.getName() << "\" to table " << id << endl;
        status = Close;
    }
}

void Table::removeFood(int foodId) {
    auto position = orders.begin();
    if (status == Close) {
        cout << "Table " << id << " is closed. Cannot remove food." << endl;
    }
    else {
        bool haveDish = false;
        for (auto it : orders) {
            if (it->getId() == foodId) {
                orders.erase(position);
                cout << "Removed food with ID " << foodId << " from table " << id << endl;
                haveDish = true;
                break;
            }
            position++;
        }
        if (!haveDish) {
            cout << "Food with ID " << foodId << " is not found in table " << id << endl;
        }
    }
}

void Table::Bill() {
    double total = 0;
    cout << "==== Bill for table " << id << " ====" << endl;
    for (Food& food : orders) {
        total += food.getCost();
        cout << food.getName() << ": \t\t$" << food.getCost() << endl;
    }
    cout << "Total: \t\t$" << total << endl;

    orders.clear();
    status = Open;
}
/*********************Class Employee*********************/
class Employee : Manager {
    private:
        bool isTableCreated;
    public:
        Employee() : isTableCreated(false) {}
        list <Table> tables;
        void createTables(int num);
        void displayTableList();
        void displayMenu();
        void addFoodToTable(int tableId, int foodId);
        void removeFoodFromTable(int tableId, int foodId);
        void calculateBillForTable(int tableId);
        void printTableStatus() ;
};

void Employee::createTables(int num) {
    if (!isTableCreated) {
        for (int i = 1; i <= num; i++) {
            Table table(i);
            tables.push_back(table);
        }
        isTableCreated = true;
    }
}

void Employee::displayTableList() {
    if (!tables.empty()) {
        cout << "=== Table list ===" << endl;
        cout << "Table\tStatus" << endl;
        for ( const Table& table : tables) {
            cout << "  " << table.id << "   -   ";
            if (table.status == Open) {
               cout << "O";
            }
            else {
                cout << "X";
            }
            cout << endl;
        }
    } else {
        cout << "Table list is empty." << endl;
    }
}

void Employee::displayMenu() {
    cout << "==== Restaurant Menu ====" << endl;
    for (auto& food : database) {
        cout << "ID: " << food.getid() << " - Name: " << food.getName() << " - Price: $" << food.getPrice() << endl;
    }
}

void Employee::addFoodToTable(int tableId, int foodId) {
    for (Table& table : tables) {
        if (table.id == tableId) {
            for (Food& food : database) {
                if (food.getid() == foodId) {
                    table.addFood(food);
                    return;
                }
            }
            cout << "Food with ID " << foodId << " does not exist in the menu." << endl;
            return;
        }
    }
    cout << "Table " << tableId << " does not exist." << endl;
}

void Employee::removeFoodFromTable(int tableId, int foodId) {
    for (Table& table : tables) {
        if (table.id == tableId) {
            table.removeFood(foodId);
            return;
        }
    }
    cout << "Table " << tableId << " does not exist." << endl;
}

void Employee::calculateBillForTable(int tableId) {
    for (Table& table : tables) {
        if (table.id == tableId) {
            table.Bill();
            return;
        }
    }
    cout << "Table " << tableId << " does not exist." << endl;
}

void Employee::printTableStatus() {
    cout << "Table status:" << endl;
    for (const Table& table : tables) {
        cout << "Table " << table.id << ": ";
        if (table.status == Open) {
            cout << "Open";
        }
        else {
            cout << "Close";
        }
        cout << endl;
    }
}

void displayToConsoleScreen(){
    Manager manager;
    Employee employee;
    int option, choice;

    do {
        cout << "=== Menu ===\n1. MANAGER\n2. EMPLOYEE\n";
        cout << "0.TURN BACK!\n";
        cin >> option;

        switch (option){
            case 1:
                do {
                    cout << "======== MANAGER ========\n1. Add Food to Menu\n2. Edit Food in Menu\n";
                    cout << "3. Delete Menu Food\n4. Show Menu\n5. Set up number of Table\n";
                    cout << "0. Turn back!\n";
                    cin >> choice;

                    switch (choice){
                        case 0:
                            break;
                        case 1:
                            employee.addMenu();
                            break;
                        case 2: 
                            employee.editMenu();
                            break;
                        case 3:
                            employee.eraserMenu();
                            break;
                        case 4: 
                            employee.displayMenu();
                            break;
                        case 5:
                            int num;
                            cout << "Enter number of Table: \n";
                            cin >> num;
                            employee.setTableQuantity(num);
                            break;
                        default:
                            cout << "Invalid choice. Please try again.\n";
                            break;
                    }
                } while (choice != 0);
                break;

            case 2:
                employee.createTables(employee.getTableQuantity());
                employee.displayTableList();

                int tableId;
                cout << "Enter table ID: ";
                cin >> tableId;

                do {
                    cout << "====== EMPLOYEE ======\n1. Add Food to Table\n";
                    cout << "2. Delete Table Food\n3. Show Menu\n4. Paying\n";
                    cout << "0. Turn back!\n";
                    cin >> choice;

                    switch (choice){
                        case 0:
                            break;
                        case 1:
                            int foodId;
                            cout << "Enter food ID: ";
                            cin >> foodId;
                            employee.addFoodToTable(tableId, foodId);
                            break;
                        case 2:
                            cout << "Enter food ID: ";
                            cin >> foodId;
                            employee.removeFoodFromTable(tableId, foodId);
                            break;
                        case 3: 
                            employee.displayMenu();
                            break;
                        case 4:
                            employee.calculateBillForTable(tableId);
                            break;
                        default:
                            cout << "Invalid choice. Please try again.\n";
                            break;
                    }
                } while (choice != 0);
                break;
        }
    } while (option != 0);
}


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
