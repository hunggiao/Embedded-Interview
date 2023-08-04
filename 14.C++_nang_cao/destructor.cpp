#include <iostream>
using namespace std;


class SV{
    private:
        int id;
        int *ptr;
        string name;
    public:
        SV(string NAME){
            static int ID = 100;
            ptr = &ID;
            id = ID;
            ID++;
            name = NAME;
        }
        ~SV(){
            *ptr = 100;
            cout<<name<<endl;
        }
        int getid(){
            return id;
        }
};


// sv1 khởi tạo đầu tiên, sv2 khởi tạo sau đè lên sv1 (như cái hộp sv1 bỏ vào trước, sv2 vào sau đè lên sv1)
// sau khi thoát ra khỏi hàm, sẽ lấy cái ở trên trước là sv2, sau đó lấy sv1
void test1(){
    SV sv1("SV1"), sv2("SV2"); 
                               
    cout<<sv1.getid()<<endl;
    cout<<sv2.getid()<<endl;
}

void test2(){
    SV sv1("SV3"), sv2("SV4");
    cout<<sv1.getid()<<endl;
    cout<<sv2.getid()<<endl;
}


int main(int argc, char const *argv[])
{
    test1();
    test2();
    return 0;
}
