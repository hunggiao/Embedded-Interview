#include <iostream>
#include <map>
#include<string>

using namespace std;

int main(int argc, char const *argv[])
{
    map<string,int> Sinhvien;
    Sinhvien["ID"] = 10;
    Sinhvien["LOP"] = 7;
    Sinhvien["TUOI"] = 12;


    for(auto item : Sinhvien){
        cout<<"Key: "<<item.first<<", "<<"value: "<<item.second<<endl;
    }
    
    return 0;
}
