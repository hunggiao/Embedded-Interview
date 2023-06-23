#include <iostream>
#include <math.h>
class Diem{
    private:
        int8_t toaDoX;
        int8_t toadoY;
    public:
        Diem(int8_t x = 0, int8_t y = 0);
        int8_t getX();
        int8_t getY();

};

Diem::Diem(int8_t x, int8_t y){
    toaDoX = x;
    toadoY = y;
}

int8_t Diem::getX(){
    return toaDoX;
}


int8_t Diem::getY(){
    return toadoY;
}

class phepToanOXY{
    private:
        Diem a;
        Diem b;
        Diem c;
        typedef enum{
            KHOANG_CACH,
            S_TAM_GIAC
        }TypePhepToan;
        TypePhepToan phepToan;
    public:
        phepToanOXY(Diem A, Diem B);
        phepToanOXY(Diem A, Diem B, Diem C);
        float get_kc();
        float get_dientich();
};

phepToanOXY::phepToanOXY(Diem A, Diem B){
    phepToan = KHOANG_CACH;
    a = A;
    b = B;
}

phepToanOXY::phepToanOXY(Diem A, Diem B, Diem C){
    phepToan = S_TAM_GIAC;
    a = A;
    b = B;
    c = C;
}

float phepToanOXY::get_kc(){
    if(phepToan == KHOANG_CACH){
        float kc = (float)sqrt((a.getX() - b.getX())*(a.getX() - b.getX()) + (a.getY() - b.getY())*(a.getY() - b.getY()));
        printf("Khoang cach 2 diem la: %.2lf\n",kc); 
    }else{
        printf("Khong goi duoc ham tinh khoang cach\n");
    }
}

float phepToanOXY::get_dientich(){
    if(phepToan == S_TAM_GIAC){
        float dt = (float)(abs((b.getX() - a.getX())*(c.getY() - a.getY()) - (c.getX() - a.getX())*(b.getY() - a.getY())))/2;
        printf("Dien tich tam giac la: %.2lf\n", dt);
    }else{
        printf("Khong goi duoc ham tinh dien tich tam giac\n");
    }
}

int main(int argc, char const *argv[])
{
    Diem A(2,3), B(4,5), C(7,9);
    phepToanOXY kc(A, B);
    kc.get_kc();
    phepToanOXY dt(A, B, C);
    dt.get_dientich();

    return 0;
}


