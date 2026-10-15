#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Taikhoan{
    string tdn,mk,email;
    int key;
    public:
    int getkey() {return key;}
    void settaikhoan(string tdn1,string mk1,string email1){
        tdn = tdn1;
        mk = mk1;
        email = email1;
        return;
    }
};

class Manager_Taikhoan{
    vector <Taikhoan> tks;
    public:
    bool checkemail(string email){
        int check = email.find("@gmail.com");
        if(check == 0 || check == -1 ){ //string::npos
            cout << "Tai khoan khong hop le" << endl;
            return false;
        }
        return 1;
    }

    bool setupTK(string tdn = "",string mk = "", string email = ""){
        if(tdn == ""){
            cout << "Nhap Ten Dang Nhap:";
            getline(cin,tdn);
        }
        if(mk == ""){
            cout << "Nhap Mat  Khau:";
            getline(cin,mk);
        }
        if(email == ""){
            do{
            cout << "Nhap Emial:";
            getline(cin,email);
            }
            while(!checkemail(email));
        }
    }
};
int main() {

 int a = 10;
 cout << a;
}