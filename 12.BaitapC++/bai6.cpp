#include <iostream>
using namespace std;

int UCLN(int a, int b){
    if(a%b == 0) return b;
    else return UCLN(b, a%b);
}
class Phanso
{
private:
    int tu;
    int mau;
public:
    void set_ps(int t, int m);
    void rutgon();
    void in_PS();
    Phanso cong(Phanso);
    Phanso tru(Phanso);
    Phanso nhan(Phanso);
    Phanso chia(Phanso);
};

void Phanso::set_ps(int t, int m){
    tu = t;
    mau = m;
}

void Phanso::rutgon(){
    int uc = UCLN(tu,mau);
    tu = tu/uc;
    mau = mau/uc;
}

void Phanso::in_PS(){
    cout<<tu<<"/"<<mau<<endl;
}

Phanso Phanso::cong(Phanso ps){
    Phanso kq;
    kq.tu = tu*ps.mau + mau*ps.tu;
    kq.mau = mau*ps.mau;
    kq.rutgon();
    return kq;
}

Phanso Phanso::tru(Phanso ps){
    Phanso kq;
    kq.tu = tu*ps.mau - mau*ps.tu;
    kq.mau = mau*ps.mau;
    kq.rutgon();
    return kq;
}

Phanso Phanso::nhan(Phanso ps){
    Phanso kq;
    kq.tu = tu*ps.tu;
    kq.mau = mau*ps.mau;
    kq.rutgon();
    return kq;
}

Phanso Phanso::chia(Phanso ps){
    Phanso kq;
    kq.tu = tu*ps.mau;
    kq.mau = mau*ps.tu;
    kq.rutgon();
    return kq;
}

int main(int argc, char const *argv[])
{
    Phanso psA, psB, psC, psD, ps1, ps2;
    ps1.set_ps(5,6);
    ps2.set_ps(2,3);
    psA = ps1.cong(ps2);
    psB = ps1.tru(ps2);
    psC = ps1.nhan(ps2);
    psD = ps1.chia(ps2);
    psA.in_PS();
    psB.in_PS();
    psC.in_PS();
    psD.in_PS();
    return 0;
}