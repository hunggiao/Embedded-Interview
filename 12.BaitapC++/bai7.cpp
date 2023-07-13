#include <iostream>
using namespace std;

class TIME{
    private:
        int day, month, year;
    public:
        void set_day(int d, int m, int y);
        int age(TIME timenow);
        void check_holiday();
};

void TIME::set_day(int d, int m, int y){
    day = d;
    month = m;
    year = y;
}

int TIME::age(TIME timenow){
    int tuoi;
    tuoi = timenow.year - TIME::year;
    return tuoi;
}

void TIME::check_holiday(){
    if((TIME::day == 1 && TIME::month == 1)
        || (TIME::day == 30 && TIME::month == 4)
        || (TIME::day == 1 && TIME::month == 5)
        || (TIME::day == 2 && TIME::month == 9))
        printf("Ngay %d thang %d la ngay le trong nam",TIME::day,TIME::month);
    else printf("Ngay %d thang %d khong phai la ngay le trong nam",TIME::day,TIME::month);
} 


int main(int argc, char const *argv[])
{
    TIME t1, t2, t3;
    t1.set_day(27,03,1999);
    t2.set_day(22,06,2023);
    t3.set_day(2,9,2023);
    cout<<"Tuoi cua nguoi do la: "<<t1.age(t2)<<endl;
    t3.check_holiday();
    return 0;
}
