#include <iostream>
#include <list>
#include <string>

using namespace std;
class Monan{
    private:
        uint8_t id;
        string ten_mon;
        double gia;
    public:
        Monan();
        void setTen(string TEN);
        void setGia(double GIA);

        string getTen();
        double getGia();
        uint8_t getid();
};

Monan::Monan(){
    static int Id = 100;
    Monan::id = Id;
    Id ++;
}

void Monan::setTen(string TEN){
    ten_mon = TEN;
}

void Monan::setGia(double GIA){
    gia = GIA;
}

string Monan::getTen(){
    return ten_mon;
}

double Monan::getGia(){
    return gia;
}

uint8_t Monan::getid(){
    return id ;
}

class Quanly{
    private:
        list<Monan> Database;
        uint8_t soban;
        void themmon();
        void suamon();
        void xoamon();
        void dsMon();
        void soBan();
    public:
        Quanly();
        list <Monan> getDatabase();
        uint8_t getSoban();
};

typedef enum{
    THEM_MON,
    SUA_MON,
    XOA_MON,
    DANH_SACH_MON,
    SO_BAN,
    OUT
}quanly;

Quanly::Quanly(){
    uint8_t key;
    do
    {
        cout<<"--QUAN LY MON AN--"<<endl;
        cout<<"1. THEM MON"<<endl;
        cout<<"2. SUA MON"<<endl;
        cout<<"3. XOA MON"<<endl;
        cout<<"4. DANH SACH MON AN"<<endl;
        cout<<"5. THIET LAP SO BAN"<<endl;
        cout<<"6. THOAT"<<endl;
        cout<<"-------------------"<<endl;
        do
        {
            cout<<"Nhan phim: ";
            cin>>key;
            cin.ignore();
        } while (key < 1 || key > 6);
    
        switch ((quanly)key)
        {
            case THEM_MON:
                themmon();
                break;
            case SUA_MON:
                suamon();
                break;
            case XOA_MON: 
                xoamon();
                break;
            case DANH_SACH_MON: 
                dsMon();
                break;
            case SO_BAN:
                soBan();
                break;
            case OUT:
                exit(0);
            default:
                break;
        }
    }while (key);
}
    

list <Monan> Quanly::getDatabase(){
    return this->Database;
}

uint8_t Quanly::getSoban(){
    return this->soban;
}

void Quanly::themmon(){
    cout<<"--THEM MON--"<<endl;
    string name;
    double cost;

    do{
        cin.ignore();
        cout<<"Nhap ten mon: ";
        getline(cin, name);
    } while (name.empty());
    
    do
    {
        cout<<"Nhap gia tien: ";
        cin>>cost;
        cin.ignore();
    } while (cost < 0);
    
    Monan themmon;
    themmon.setTen(name);
    themmon.setGia(cost);
    Database.push_back(themmon);
    cout<<themmon.getid()<<endl;
    cout<<"Them thanh cong"<<endl;
    cout<<"---------------"<<endl; 
}

void Quanly::suamon(){
    uint8_t id;
    string name;
    double cost;
    bool haveMon = false;
    uint8_t chonphim;
    cout<<"--SUA MON THEO MA ID--"<<endl;
    cout<<"Nhap ma ID: ";
    cin>>id;
    for (auto &item : Database)
    {
        if (item.getid() == id)     
        {
            cout<<"Chon thong tin muon sua"<<endl;
            cout<<"1. Ten mon"<<endl;
            cout<<"2. Gia tien"<<endl;

            do
            {
                cout<<"Chon phim";
                cin>>chonphim;      
            } while (0);

            switch (chonphim)
            {
            case 1:
                do{
                    cin.ignore();
                    cout<<"Nhap ten mon: ";
                    getline(cin, name);
                } while (name.empty());
                item.setTen(name);
                break;
            case 2:
                do
                {
                    cout<<"Nhap gia tien: ";
                    cin>>cost;
                    cin.ignore();
                } while (cost < 0);
                item.setGia(cost);
                break;
            default:
                cout<<"Khong co lua chon phu hop!"<<endl;
                break;
            }
            haveMon = 1;
            break;
        }
        if(haveMon != 1) cout<<"Khong tim thay mon co ma ID: "<<id<<endl;
    }
}

void Quanly::xoamon(){
    uint8_t id;
    bool haveMon = false;
    auto position = Database.begin();
    cout<<"--XOA MON THEO MA ID--"<<endl;
    cout<<"Nhap ma ID: ";
    cin>>id;
    for (auto temp : Database)
    {
        if(temp.getid() == id){
            Database.erase(position);
            haveMon = 1;
            cout<<"Da xoa mon thanh cong!"<<endl;
            break;
        }
        position++;
    }
    if(haveMon != 1) cout<<"Khong tim thay mon co ma ID"<<id<<endl;   
}

void Quanly::dsMon(){
    if(Database.empty()){
        cout<<"--DANH SACH MON AN TRONG--"<<endl;
    }else{
        cout<<"--DANH SACH MON AN--"<<endl;
        for (Monan temp : Database)
        {
            cout<<"ID: "<<temp.getid()<<endl;
            cout<<"TEN MON: "<<temp.getTen()<<endl;
            cout<<"GIA TIEN: "<<temp.getGia()<<endl;
            cout<<"_______________________"<<endl;
        }
    }
}

void Quanly::soBan(){
    cout<<"--THIET LAP SO BAN--"<<endl;
    cout<<"Nhap so ban: ";
    cin>>soban;
    cin.ignore();
}

class Thongtinban{
    private:
        uint8_t SOBAN;
        bool TRANG_THAI;
        typedef struct{
            Monan Mon;
            uint8_t SO_LUONG;
        }TypeMon;
        list <TypeMon> DATABASE_MON_AN;
    public:
        Thongtinban(uint8_t soban, bool trangthai);
        uint8_t getSoban();
        void setTrangthai(bool trangthai);
        bool getTrangthai();
        
        void themMon();
        void suaMon();
        void xoaMon();
        void dsMon();
        void thanhtoan();
};

Thongtinban::Thongtinban(uint8_t soban, bool trangthai){
    SOBAN = soban;
    TRANG_THAI = trangthai;
}

void Thongtinban::setTrangthai(bool trangthai){
    TRANG_THAI = trangthai;
}

bool Thongtinban::getTrangthai(){
    return TRANG_THAI;
}

uint8_t Thongtinban::getSoban(){
    return SOBAN;
}


void Thongtinban::themMon(){
    Monan mon;
    uint8_t soluong;

    do
    {
        cout<<"Nhap so luong: ";
        cin>>soluong;
    } while(soluong < 0);
    TypeMon MON;
    MON.Mon = mon;
    MON.SO_LUONG = soluong;
    DATABASE_MON_AN.push_back(MON);
}

void Thongtinban::suaMon(){
    uint8_t id;
    uint8_t soluong;
    bool haveMon = false;
    cout<<"--SUA MON--"<<endl;
    cout<<"Nhap ID mon an: ";
    cin>>id;
    for(auto &item : DATABASE_MON_AN){
        if(item.Mon.getid() == id){
            do
            {
                cout<<"Nhap so luong: ";
                cin>>soluong;
                cin.ignore();
            } while (soluong < 0);
            item.SO_LUONG = soluong;
            break;
        }
        haveMon = 1;
        break;
    }
    if(haveMon != 1) cout<<"Khong tim thay mon an phu hop!"<<endl;
}

void Thongtinban::xoaMon(){
    uint8_t id;
    bool haveMon = false;
    auto position = DATABASE_MON_AN.begin();
    cout<<"--XOA MON THEO MA ID--"<<endl;
    cout<<"Nhap ma ID: ";
    cin>>id;
    for(auto item : DATABASE_MON_AN){
        if(item.Mon.getid() == id){
            DATABASE_MON_AN.erase(position);
            cout<<"Da xoa thanh cong!"<<endl;
            haveMon = 1;
            break;
        }
        position++;
    }
    if(haveMon != 1) cout<<"Khong tim thay mon an phu hop!"<<endl;
}

void Thongtinban::dsMon(){
    if(DATABASE_MON_AN.empty()){
        cout<<"--DANH SACH TRONG!--"<<endl;
    }else{
        cout<<"--DANH SACH MON AN--"<<endl;
        for(auto item : DATABASE_MON_AN){
            cout<<"ID: "<<item.Mon.getid()<<endl;
            cout<<"TEN MON: "<<item.Mon.getTen()<<endl;
            cout<<"GIA TIEN: "<<item.Mon.getGia()<<endl;
            cout<<"SO LUONG: "<<item.SO_LUONG<<endl;
        }
    }
}

void Thongtinban::thanhtoan(){
    float tongtien = 0;
    cout<<"--THANH TOAN BAN--"<<endl;
    cout<<"Tong tien la: ";
    for(auto item : DATABASE_MON_AN){
        tongtien += item.Mon.getGia() * item.SO_LUONG;
    }
}

class Nhanvien{
    private:
        list <Monan> Database_mon_an;
        list <Thongtinban> Database_ban;
        void themmon();
        void suamon();
        void xoamon();
        void thanhtoan();
        void luachonBan();
        void dsMon();
    public:
        Nhanvien(list<Monan> database, uint8_t soban);

};

Nhanvien::Nhanvien(list <Monan> database, uint8_t soban){
    if(soban == 0 && database.size() == 0){
        cout<<"Chua co thong tin"<<endl;
    }else{
        for (uint8_t i = 0; i <= soban; i++)
        {
            Thongtinban ban(i, false);
            Database_ban.push_back(ban);
        }
        Database_mon_an.assign(database.begin(), database.end());
    }
    luachonBan();
}

typedef enum{
    THEMMON,
    SUAMON,
    XOAMON,
    THANHTOAN,
    DANHSACHMON
}nhanvien;

void Nhanvien::luachonBan(){
    uint8_t soban;
    cout<<"--LUA CHON BAN--"<<endl;
    cout<<"Nhap so ban: ";
    cin>>soban;
    for(auto item : Database_ban){
        item.getSoban() == soban;
        uint8_t key;
        do
        {
            cout<<"Nhap lua chon: ";
            cin>>key;
        } while (key > 5 && key <0);
        switch ((nhanvien)key)
        {
        case THEMMON:
            themmon();
            break;
        case SUAMON: 
            suamon();
            break;
        case XOAMON: 
            xoamon();
            break;
        case THANHTOAN:
            dsMon();
            break;
        case DANHSACHMON: 
            thanhtoan();
            break;
        default:
            break;
        }
    }
}

void Nhanvien::themmon(){
    uint8_t soban;
    cout<<"--THEM MON--"<<endl;
    cout<<"Nhap so ban: ";
    cin>>soban;
    for(auto item : Database_ban){
        if(item.getSoban() == soban){
            item.themMon();
        }
    }
}

void Nhanvien::suamon(){
    uint8_t soban;
    cout<<"--SUA MON--"<<endl;
    cout<<"Nhap so ban: ";
    cin>>soban;
    for(auto item : Database_ban){
        if(item.getSoban() == soban){
            item.suaMon();
        }
    }
}

void Nhanvien::xoamon(){
    uint8_t soban;
    cout<<"--XOA MON--"<<endl;
    cout<<"Nhap so ban: ";
    cin>>soban;
    for(auto item : Database_ban){
        if(item.getSoban() == soban){
            item.xoaMon();
        }
    }
}

void Nhanvien::dsMon(){
    uint8_t soban;
    cout<<"--DANH SACH MON--"<<endl;
    cout<<"Nhap so ban: ";
    cin>>soban;
    for(auto item : Database_ban){
        if(item.getSoban() == soban){
            item.dsMon();
        }
    }
}

void Nhanvien::thanhtoan(){
    uint8_t soban;
    cout<<"--THANH TOAN--"<<endl;
    cout<<"Nhap so ban: ";
    cin>>soban;
    for(auto item : Database_ban){
        if(item.getSoban() == soban){
            item.thanhtoan();
        }
    }
}

typedef enum{
    QUAN_LY,
    NHAN_VIEN
}menu;

int main(int argc, char const *argv[])
{   
    int phim;
    do
    {
        cout<<"--CHUONG TRINH GOI MON--"<<endl;
        cout<<"1. QUAN LY"<<endl;
        cout<<"2. NHAN VIEN"<<endl;
        cout<<"Vui long nhan phim: ";
        cin>>phim;
    } while (phim != 1 && phim != 2);
    
    switch ((menu)phim){
        case QUAN_LY:
            Quanly ql();
            break;
        case NHAN_VIEN:
            Nhanvien nv();
            break;
    }
    return 0;
}
