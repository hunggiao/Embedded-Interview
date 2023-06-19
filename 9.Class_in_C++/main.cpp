#include<iostream>
#include<string>
using namespace std;

class Doituong{
    public:
        //Doituong(int tuoi, int lop); //contructor
        void themThongtin(int tuoi, int lop);
        void hienthi(); //method
    protected:
        int TUOI; //property
        int LOP;
};

void Doituong::hienthi(){
    cout << "Tuoi: "<< TUOI << endl;
    cout << "Lop: "<< LOP << endl;
};

/*Doituong::Doituong(int tuoi, int lop){
    Doituong::TUOI = tuoi;
    Doituong::LOP = lop;
};*/

void Doituong::themThongtin(int tuoi, int lop){
    TUOI = tuoi;
    LOP = lop;
};

// Kế thừa
class Sinhvien : public Doituong{
    public:
        void themThongtin(int tuoi, int lop, int mssv);
        void hienthi();
    private: 
        int MSSV;
};

void Sinhvien::themThongtin(int tuoi, int lop, int mssv){
    TUOI = tuoi;
    LOP =  lop;
    MSSV = mssv;
};

void Sinhvien::hienthi(){
    cout << "Tuoi: "<< TUOI << endl;
    cout << "Lop: "<< LOP << endl;
    cout << "Mssv: "<< MSSV << endl;
};

int main(int argc, char const *argv[])
{
    //Doituong dt(17,5); //object
    //dt.hienthi();
    Doituong dt;
    dt.themThongtin(27,3);
    dt.hienthi();
    Sinhvien sv;
    sv.themThongtin(7,15,2703);
    sv.hienthi();
    return 0;
}
