#include <iostream>
#include <string>

class DONG_VAT
{
private:
    char name;
    int age;
    float weight;
public:
    DONG_VAT(char ten, int tuoi, float can_nang);
    int tinhBMI();
    void sosanh_Age();
    void sosanh_W();

    
};

DONG_VAT::DONG_VAT(char ten, int tuoi, float can_nang)
{   
    DONG_VAT::name = ten;
    DONG_VAT::age = tuoi;
    DONG_VAT::weight = can_nang;
}

int DONG_VAT::tinhBMI(){
    
}



