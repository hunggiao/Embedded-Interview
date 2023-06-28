#include <iostream>
#include <string>
using namespace std;

typedef enum{
    RED,
    BLUE,
    BLACK
}typeColor;

class CAR{
    private:
        typeColor color;
        string typemotor;
        int km;
    public:
        CAR(typeColor COLOR, string TYPEMOTOR, int KM);
        void inforCar();
        int8_t check_km(int km_now);

};

CAR::CAR(typeColor COLOR, string TYPEMOTOR, int KM){
    color = COLOR;
    typemotor = TYPEMOTOR;
    km = KM;
}

void CAR::inforCar(){
    if(color == 0) cout<<"Mau sac: Red"<<endl;
    else if(color == 1) cout<<"Mau sac: Blue"<<endl;
    else if(color == 2) cout<<"Mau sac: Black"<<endl;
    else cout<<"Khong co loai xe co mau nay"<<endl;
    cout<<"Loai dong co: "<<typemotor<<endl;
    cout<<"So km da di: "<<km<<endl;
}

int8_t CAR::check_km(int km_now){
    cout<<"Quang duong di duoc: "<< (int)(km_now - km) <<" km"<<endl;
}


int main(int argc, char const *argv[])
{
    CAR vinfast(RED, "Dong co N20", 1500);
    vinfast.inforCar();
    vinfast.check_km(3000);
    return 0;
}




