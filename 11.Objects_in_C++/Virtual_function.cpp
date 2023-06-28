#include <iostream>

// Khi class con gọi phương thức trong class cha, khi có virtual func thì class sẽ lấy phương thức được định nghĩa lại (nếu có) ở class con
class Sinhvien{
    public:
        virtual char *test(){           //overload
            return (char*) "Hello World";
        }
        void display(){
            printf("test: %s\n", test());
        }
};

class Doituong : public Sinhvien{
    public: 
        char *test(){
            return (char*)"This is test\n"; // override
        }
};

int main(int argc, char const *argv[])
{
    Sinhvien sv;
    sv.display();
    Doituong dt;
    dt.display();
    return 0;
}
