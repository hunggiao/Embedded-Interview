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
            uint8_t num;
            cout<<"--SETTING NUMBER OF TABLE--"<<endl;
            cout<<"Enter number of table: ";
            cin>>num;
            cin.ignore();
            noTable(num);
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
        database.push_back(newFood);
        cout << "ID\t" << "Name\t\t" << "Price" << endl;
        cout << newFood.getid() << "." << "\t" << newFood.getName() << "\t\tVND" << newFood.getCost() << endl;
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
void Manager::screenMenu(){
    cout << "=======Menu=======" << endl;
    cout << "ID\tName\t\tPrice\n";
    for (auto& food : database) {
        cout << food.getid() << "." << "\t" << food.getName() << "\t\tVND" << food.getCost() << endl;
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
            } while (key != 0);
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

/*********************Class inforTab*********************/
class inforTab{
    private:
        uint8_t num;
        bool status;
        typedef struct{
            Food dishes;
            uint8_t quanlity;
        }typeDishes;
        list <typeDishes> Database_dish;
    public:
        inforTab(uint8_t Num, bool Status);
        uint8_t getNumTab();
        bool getStatus();
        void listFood();
        void add(Manager ql, Food dish, uint8_t Quanlity, uint8_t id);
        void edit(uint8_t id, uint8_t Quanlity);
        void erase(uint8_t id);
        void display(typeDishes typefood);
        
};

inforTab::inforTab(uint8_t Num, bool Status){
    num = Num;
    status = Status;
}

uint8_t inforTab::getNumTab(){
    return num;
}

bool inforTab::getStatus(){
    return status;
}

void inforTab::add(Manager ql, Food dish, uint8_t Quanlity, uint8_t id){
    cout<<"--ADD DISH FOR TABLE--"<<endl;
    typeDishes typefood;
    for(Food &item : ql.getdatabase()){
        if(item.getid() == id){
            typefood.dishes.setName(item.getName());
            typefood.dishes.setCost(item.getCost());
            cout<<"Successfully add dishes!"<<endl;
            cout<<"Show list of dishes"<<endl;
            cout<<"ID: "<<id<<endl;
            cout<<"NAME: "<<item.getName()<<endl;
            cout<<"COST: "<<item.getCost()<<endl;
            cout<<"QUANLITY: "<<Quanlity<<endl;
        }
    }
}

class Employee{
    private:
        list <Food> database_food;
        list <inforTab> database_table;
    public:
        Employee(list <Food> database, uint8_t numtab);
        list <inforTab> getDataEmployee();
};

Employee::Employee(list <Food> database, uint8_t numtab){
    database_food.assign(database.begin(), database.end());

    for (int i = 0; i <= numtab; i++)
    {
        inforTab table(i, false);
    }
    
}

list <inforTab> Employee::getDataEmployee(){
    return database_table;
}

int main(int argc, char const *argv[])
{
    uint8_t choose1, choose2_1, choose3_1, choose2_2, choose3_2;
    bool a = false, n = false;
    uint8_t key = 0;
    Food dish;
    Manager ql;
    uint8_t id;
    uint8_t Table_have_customer;
    while(a==false){
        bool b = false;
        cout << "1. Quan Li" <<endl;
        cout << "2. Nhan Vien" <<endl;
        cout <<"Nhap lua chon: ";
        cin >> choose1;
        cin.ignore();
        cout << endl;
        while(b==false){
            bool c1 = false, c2 = false;
            switch (choose1){
                case 1: {
                    cout << "1. Them mon" << endl;
                    cout << "2. Sua mon" << endl;
                    cout << "3. Xoa mon" << endl;
                    cout << "4. Danh sach mon" << endl;
                    cout << "5. Thiet lap so ban " << endl;
                    cout << "0. Quay lai" << endl;
                    cout << endl;
                    cout << "Nhap lua chon: ";
                    cin >> choose2_1;
                    cin.ignore();
                    cout << endl;
                    while(c1==false){
                        switch (choose2_1){
                            case 1:{
                                cout << "Them mon: " << endl;
                                dish.NhapMonAn();
                                QL.ThemMon(MA);
                                break;
                            }
                            case 2:{
                                cout << "Sua mon an: " << endl;
                                cout << "Nhap ID: ";
                                cin >> id;
                                cout <<endl;
                                QL.SuaMon(id);
                                QL.CapNhatID();
                                break;
                            }
                            case 3:{
                                cout << "Xoa mon an: " << endl;
                                cout << "Nhap ID: ";
                                cin >> id;
                                cout << endl;
                                if(n==true){
                                    id=id-1; 
                                    /*Vï¿½ khi xï¿½a 1 d?i tu?ng kh?i danh sï¿½ch (tr? d?i tu?ng cu?i), cï¿½c d?i tu?ng bï¿½n tay ph?i s?
                                    lï¿½i qua bï¿½n trï¿½i d? thay th? v? trï¿½ c?a d?i tu?ng dï¿½ xï¿½a nï¿½n id c?n gi?m 1 don v?*/
                                }
                                QL.XoaMon(id);
                                QL.CapNhatID();
                                break;
                            }

                            case 4:{
                                cout << "Danh sach cac mon an: " << endl;
                                QL.DanhSachMon();
                                QL.CapNhatID();
                                break;
                            }

                            case 5:{
                                QL.ThietLapSoBan();
                                break;
                            }
                        }
                        if(LuaChon2_1 == 0){
                            c1 = true;
                            b = true;
                            continue;
                        }

                        cout << "1. Tiep tuc" <<endl;
                        cout << "0. Quay lai" <<endl;
                        cout <<"Nhap lua chon: ";
                        cin >> LuaChon3_1;
                        cout << endl;
                        if(LuaChon3_1 == 1){
                            c1 = false;
                            n = true;
                        }
                        else if(LuaChon3_1 == 0){
                            c1 = true;
                            n = false;
                        }
                        else{
                            cout<<"Lua chon khong hop le"<<endl;
                            c1 = true;
                        }
                    }
                    break;
                }

                case 2: {
                    NhanVien NV(QL.getData(), QL.getSoBan());
                    //ThongTinBan TTB(QL.getSoBan(), false);
                    cout<<"Chon ten so ban: ";
                    cin>>key;
                    cout<<endl;
                    //ThongTinBan TTB(key, true);
                    for(ThongTinBan& TTB : NV.getData_NV()){
                        if(TTB.getSoBan() == key){
                            cout<<"1. Them mon"<<endl;
                            cout<<"2. Sua mon" << endl;
                            cout<<"3. Xoa mon" << endl;

                            cout<<"Nhap lua chon: ";
                            cin>>LuaChon2_2;
                            cout<<endl;

                            while(c2==false){
                                switch (LuaChon2_2){
                                    case 1:{ //Thi?t l?p s? bï¿½n cï¿½ khï¿½ch
                                        cout<<"Nhap ID can tim";
                                        cin>> id;
                                        cout<<endl;

                                        cout<<"Nhap so luong mon an: ";
                                        cin>> soLuong;
                                        cout<<endl;
                                        TTB.themMon(QL, MA, soLuong, id);
                                        break;
                                    }
                                    case 2:{
                                        //TTB.xoaMon();
                                        break;
                                    }
                                    case 3:{
                                        break;
                                    }
                                    case 4:{
                            
                                        break;
                                    }
                                    case 5:{
                                        break;
                                    }
                                }

                                if(LuaChon2_2 == 0){
                                    c2 = true;
                                    b = true;
                                    continue;
                                }

                                cout << "1. Tiep tuc" <<endl;
                                cout << "0. Quay lai" <<endl;
                                cout <<"Nhap lua chon: ";
                                cin >> LuaChon3_2;
                                cout << endl;
                                if(LuaChon3_2 == 1){
                                    c2 = false;
                                    n = true;
                                }
                                else if(LuaChon3_2 == 0){
                                    c2 = true;
                                    n = false;
                                }
                                else{
                                    cout<<"Lua chon khong hop le"<<endl;
                                    c2 = true;
                                }
                            }
                        }
                    }
                    break;
                }
                default:
                    b == true;
                    break;
            }
        }
    }
    return 0;
}

