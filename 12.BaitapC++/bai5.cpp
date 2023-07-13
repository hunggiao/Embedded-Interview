#include <iostream>
#include <string>

using namespace std;
class nguoi{
    private:
        string ten;
        int tuoi;
        string diachi;
    public:
        nguoi(string name, int age, string add);
        void inThongtin();
};


nguoi::nguoi(string name, int age, string add){
    nguoi::ten = name;
    nguoi::tuoi = age;
    nguoi::diachi = add;
}

void nguoi::inThongtin(){
    cout<<"Thong tin: "<<endl;
    cout<<"- Ten: "<<ten<<endl<<"- Tuoi: "<<tuoi<<endl<<"- Dia chi: "<<diachi<<endl;
}


int main(int argc, char const *argv[])
{
    nguoi toi("Giao", 24, "477 Le Duan");
    toi.inThongtin();
    return 0;
}
