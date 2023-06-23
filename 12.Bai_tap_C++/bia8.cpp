#include<iostream>
#include<string.h>
using namespace std;
class TKNH{
    private:
        string TEN;
        int STK;
        int SO_DU;
    public:
        TKNH (string ten, int stk, int so_du);
        int rutTien(int tienrut);
        int nopTien(int tiennop);
        void ktraSodu(int so_du);
};

TKNH::TKNH(string ten, int stk, int so_du){
    TEN = ten;
    STK = stk;
    SO_DU = so_du;
}

int TKNH::rutTien(int tienrut){
    printf("So tien ban dau: %d\n", TKNH::SO_DU);
    if(tienrut > TKNH::SO_DU) printf("Tai khoan ko du so du\n");
    else {
        TKNH::SO_DU -= tienrut;
        printf("Ban da rut thanh cong so tien: %d\nSo tien TKNH sau khi rut la: %d", tienrut, TKNH::SO_DU);
        }
}

int TKNH::nopTien(int tiennop){
    printf("So tien ban dau: %d", TKNH::SO_DU);
    TKNH::SO_DU += tiennop;
    printf("Ban da nop thanh cong so tien %d vao tai khoan \nSo tien TKNH sau khi nop la: %d", tiennop, TKNH::SO_DU);
    return tiennop;
}

void TKNH::ktraSodu(int so_du){
    printf("So du TKNH cua ban la: %d",TKNH::SO_DU);
}

int main(int argc, char const *argv[])
{
    TKNH tk("Nguyen Hung Giao", 0102, 5000000);
    tk.rutTien(2000000);
    return 0;
}

