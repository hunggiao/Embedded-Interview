#include <iostream>
#include <string>
using namespace std;

class DONG_VAT
{
private:
    string name;
    int age;
    float weight;
    float height;
public:
    DONG_VAT(string ten, int tuoi, float can_nang, float chieu_cao);
    int tinhBMI();
    DONG_VAT sosanh_Age(DONG_VAT);
    DONG_VAT sosanh_W(DONG_VAT);
};

DONG_VAT::DONG_VAT(string ten, int tuoi, float can_nang, float chieu_cao)
{   
    DONG_VAT::name = ten;
    DONG_VAT::age = tuoi;
    DONG_VAT::weight = can_nang;
    DONG_VAT::height = chieu_cao;
}

int DONG_VAT::tinhBMI(){
    float bmi = DONG_VAT::weight/(DONG_VAT::height*2);
    cout<<"Chi so BMI cua "<<DONG_VAT::name<<" la: "<<bmi<<endl;
    return bmi;
}

DONG_VAT DONG_VAT::sosanh_Age(DONG_VAT d1){
    if(age > d1.age) cout<<name<<" lon tuoi hon "<<d1.name<<endl;
    else cout<<d1.name<<" lon tuoi hon "<<name<<endl;
}

DONG_VAT DONG_VAT::sosanh_W(DONG_VAT d1){
    if(weight > d1.weight) cout<<name<<" nang hon "<<d1.name<<endl;
    else cout<<d1.name<<" nang hon "<<name<<endl;
}

int main(int argc, char const *argv[])
{
    DONG_VAT d1("SU TU", 10, 80, 100), d2("CHO", 7, 50, 120);
    d1.tinhBMI();
    d2.tinhBMI();
    d1.sosanh_Age(d2);
    d1.sosanh_W(d2);
    return 0;
}





