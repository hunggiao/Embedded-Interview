#include <iostream>

// Các member trong 1 namespace không được trùng tên với nhau
namespace conOngA{
    int A = 10;
}

namespace conOngB{
    int A = 20;
}
// Chỉ sử dụng using namespace khi chỉ có 1 thư viện để tránh bị trùng
using namespace conOngA;

int main(int argc, char const *argv[])
{
    std::cout<<"A = "<<A<<std::endl;

    std::cout<<"A = "<<conOngB::A<<std::endl;

    //conOngA::toanhoc a;
    return 0;
}
