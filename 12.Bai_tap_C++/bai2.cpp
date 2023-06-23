#include <iostream>
#include <math.h>

using namespace std;

class HCN{
    private:
            float l,w;
    public:
            void set_l(float dai);
            void set_w(float rong);
            float get_l();
            float get_w();

            float dientich();
            float chuvi();
            float duongcheo();
            void KT_hinhvuong();
};

 void HCN::set_l(float dai){
    l = dai;
}

void HCN::set_w(float rong){
    w = rong;
}

float HCN::get_l(){
    return l;
}

float HCN::get_w(){
    return w;
}

float HCN::dientich(){
    return l*w;
}

float HCN::chuvi(){
    return (l + w)*2;
}

float HCN::duongcheo(){
    return sqrt(l*l + w*w);
}

void HCN::KT_hinhvuong(){
    if(l == w);
    printf("Day la hinh vuong\n");
}

int main()
{
    HCN hcn;
    hcn.set_l(7);
    hcn.set_w(7);
    hcn.get_l();
    hcn.get_w();

    cout<<"Dien tich: "<<hcn.dientich()<<endl;
    cout<<"Chu vi: "<<hcn.chuvi()<<endl;
    cout<<"Do dai duong cheo: "<<hcn.duongcheo()<<endl;
    hcn.KT_hinhvuong();
    return 0;
}
