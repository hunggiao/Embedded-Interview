#include <iostream>
#include <string>

class Sinhvien{
    public:
        std::string ten;
        static int tuoi;
};

int Sinhvien::tuoi = 10; // khởi tạo lần đầu, địa chỉ cố định

// Giống struct, địa chỉ member đầu tiên giống với object, member thứ 2 thì khác

int main(int argc, char const *argv[])
{
    Sinhvien sv1,sv2;
    std::cout<<"Dia chi sv1: "<<&sv1<<std::endl;
    std::cout<<"Dia chi sv1.ten: "<<&(sv1.ten)<<std::endl;
    std::cout<<"Dia chi sv1.tuoi: "<<&(sv1.tuoi)<<std::endl;
    sv1.tuoi = 10;

    std::cout<<"Dia chi sv2: "<<&sv2<<std::endl;
    std::cout<<"Dia chi sv2.ten: "<<&(sv2.ten)<<std::endl;
    std::cout<<"Dia chi sv2.tuoi: "<<&(sv2.tuoi)<<std::endl;
    sv2.tuoi = 20;

    // Các sv1,sv2 dùng chung 1 địa chỉ được khởi tạo lần đầu
    // Giá trị của nó chính bằng giá trị được gán tại lần gần nhất
    std::cout<<sv1.tuoi<<std::endl;

    return 0;
}
