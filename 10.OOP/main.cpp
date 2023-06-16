#include <iostream>

class phepToan{
    public:
        void tong(int a, int b);
        void tong(int a, int b, int c);
    private:
        int A;
        int B;
        int C;
};

// Tính đa hình
void phepToan::tong(int a, int b){
    A = a;
    B = b;
    std::cout<<"Tong a va b: "<<a+b<<std::endl;
}

void phepToan::tong(int a, int b, int c){
    A = a;
    B = b;
    C = c;
    std::cout<<"Tong a,b,c la: "<<a+b+c<<std::endl;
}
// Sử dụng khi code các hàm tương tự nhau
template<typename var, typename varB>

var tong(var a, varB b){
    return (var)(a+b);
}

/* Tính trừu tượng: các chương trình phức tạp nằm ở private,
người dùng chỉ quan tâm đến các hàm để nhập và xuất thông tin ở public*/

// Tính đóng gói: các property nằm trong private, gán hay lấy giá trị phải thông qua method

class ptbac2{
    public:
        void nhapABC();
        void getX1X2();
    private:
        int A; // property
        int B;
        int C;
        int X1;
        int X2;
        int delta;
        void Delta();
};



int main(int argc, char const *argv[])
{   
    phepToan pt;
    pt.tong(7,9);
    pt.tong(6,5,8);
    std::cout<<"Tong a va b: "<< tong(7.5,5);
    return 0;
}


