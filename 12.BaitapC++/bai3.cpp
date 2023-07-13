#include <iostream>
#define PI 3.14159
using namespace std;

class hinhtron
{
private:
    float r;
public:
    hinhtron(int bankinh);
    float chuvi();
    float dientich();
    
};

hinhtron::hinhtron(int bankinh)
{
    hinhtron::r = bankinh;
}

float hinhtron::chuvi(){
    return 2*PI*r;
}

float hinhtron::dientich(){
    return PI*r*r;
}


int main(int argc, char const *argv[])
{
    hinhtron h1(5);
    cout<<"Chu vi hinh tron: "<<h1.chuvi()<<endl;
    cout<<"Dien tich hinh tron: "<<h1.dientich()<<endl;
    return 0;
}
