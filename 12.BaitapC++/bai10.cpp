#include <iostream>
#include <string.h>
using namespace std;

class BOOK{
    private:
        string name;
        string author;
        int16_t pub_year;
        int16_t num;
    public:
        BOOK(string NAME, string AUTHOR, int16_t PUB_YEAR, int16_t NUM);
        void inforBook();
        int bookRenter(BOOK book, int16_t quantum);
        int giveback(BOOK book, int16_t quantum);

};

BOOK::BOOK(string NAME, string AUTHOR, int16_t PUB_YEAR, int16_t NUM){
    name = NAME;
    author = AUTHOR; 
    pub_year = PUB_YEAR;
    num = NUM;
}

void BOOK::inforBook(){
    cout<<"Ten sach: "<<name<<endl;
    cout<<"Tac gia: "<<author<<endl;
    cout<<"Nam xuat ban: "<<pub_year<<endl;
    cout<<"So luong: "<<num<<" cuon"<<endl;
}

int BOOK::bookRenter(BOOK book, int16_t quantum){
    if(quantum > num) cout<<"Sach "<<book.name<<" khong du so luong de muon"<<endl;
    else {
        cout<<"Ban da muon thanh cong "<<quantum<<" cuon sach "<<book.name<<endl;
        num = num - quantum;
    }
    return num;
}

int BOOK::giveback(BOOK book, int16_t quantum){
    cout << "Ban da tra thanh cong "<<quantum<<" cuon sach "<<book.name<<endl;
    num = num + quantum;
    return num;
}

int main(int argc, char const *argv[])
{
    BOOK b1("DORAEMON", "Fujiko Fujio", 1970, 100);
    b1.inforBook();
    b1.bookRenter(b1, 100);
    b1.giveback(b1, 50);
    b1.bookRenter(b1, 100);
    return 0;
}
