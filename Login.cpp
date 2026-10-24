// #include <iostream>
// #include <unordered_map>
// #include <vector>
// using namespace std;
// const int size_hash = 100;
// class Taikhoan
// {
//     string tdn, mk, email;
//     int key;

// public:
//     string gettdn()
//     {
//         return tdn;
//     }
//     string getmk()
//     {
//         return mk;
//     }
//     string getemail()
//     {
//         return email;
//     }
//     int getkey()
//     {
//         return key;
//     }
//     void settaikhoan(string tdn1, string mk1, string email1)
//     {
//         tdn = tdn1;
//         mk = mk1;
//         email = email1;
//     }

//     void setkey(int key1)
//     {
//         key = key1;
//     }
// };

// class Manager_Taikhoan
// {
//     vector<vector<Taikhoan>> hashTable;

//     int hashFunction(string tdn)
//     {
//         unsigned long long key = 0;

//         for (char c : tdn)
//             key = (key * 31 + c) % size_hash;

//         return key;
//     }

// public:
//     Manager_Taikhoan()
//     {
//         hashTable.resize(size_hash);
//     }

//     bool checkemail(string email)
//     {
//         int pos = email.find("@gmail.com");

//         if (pos == string::npos || pos == 0)
//             return false;

//         if (pos + 10 != email.length())
//             return false;

//         return true;
//     }

//     bool checkTK(string tdn)
//     {
//         int index = hashFunction(tdn);

//         for (Taikhoan tk : hashTable[index])
//         {
//             if (tk.gettdn() == tdn)
//                 return true;
//         }

//         return false;
//     }

//     bool addTK(string tdn, string mk, string email)
//     {
//         if (checkTK(tdn))
//         {
//             cout << "Ten dang nhap da ton tai" << endl;
//             return false;
//         }

//         if (!checkemail(email))
//         {
//             cout << "Email khong hop le" << endl;
//             return false;
//         }

//         Taikhoan tk;
//         tk.settaikhoan(tdn, mk, email);
//         tk.setkey(hashFunction(tdn));

//         int index = hashFunction(tdn);
//         hashTable[index].push_back(tk);

//         return true;
//     }

//     bool login(string tdn, string mk)
//     {
//         int index = hashFunction(tdn);

//         for (Taikhoan tk : hashTable[index])
//         {
//             if (tk.gettdn() == tdn)
//             {
//                 return tk.getmk() == mk;
//             }
//         }

//         return false;
//     }

//     bool deleTK(string tdn, string mk, string email){
//         int i = 0; 
//         int index = hashFunction(tdn);
//         for(Taikhoan tk : hashTable[index]){
//             if (tk.gettdn() == tdn && tk.getemail() == email && tk.getmk() == mk){
//                 hashTable[index].erase(hashTable[index].begin + i);
//                 writeFile();
//                 return true;
//             }
//             i++;
//         }
//         return false;
//     }
// };
// int main()
// {
// }

#include <iostream>
#include <fstream>
#include <iomanip>
#include <unordered_map>
#include <vector>
using namespace std;
const int size_hash = 100;
class Taikhoan
{
    string tdn, mk, email;
    int key;

public:
    string gettdn()
    {
        return tdn;
    }
    string getmk()
    {
        return mk;
    }
    string getemail()
    {
        return email;
    }
    int getkey()
    {
        return key;
    }
    void settaikhoan(string tdn1, string mk1, string email1)
    {
        tdn = tdn1;
        mk = mk1;
        email = email1;
    }

    void setkey(int key1)
    {
        key = key1;
    }
};

class Manager_Taikhoan
{
    vector<vector<Taikhoan>> hashTable;
    bool dangDoc = false;   // true khi readFile dang nap du lieu -> addTK khong ghi file

    int hashFunction(string tdn)
    {
        unsigned long long key = 0;

        for (char c : tdn)
            key = (key * 31 + c) % size_hash;

        return key;
    }

public:
    Manager_Taikhoan()
    {
        hashTable.resize(size_hash);
    }

    bool checkemail(string email)
    {
        int pos = email.find("@gmail.com");

        if (pos == string::npos || pos == 0)
            return false;

        if (pos + 10 != email.length())
            return false;

        return true;
    }

    bool checkTK(string tdn)
    {
        int index = hashFunction(tdn);

        for (Taikhoan tk : hashTable[index])
        {
            if (tk.gettdn() == tdn)
                return true;
        }

        return false;
    }

    bool addTK(string tdn, string mk, string email)
    {
        if (checkTK(tdn))
        {
            cout << "Ten dang nhap da ton tai" << endl;
            return false;
        }

        if (!checkemail(email))
        {
            cout << "Email khong hop le" << endl;
            return false;
        }

        Taikhoan tk;
        tk.settaikhoan(tdn, mk, email);
        tk.setkey(hashFunction(tdn));

        int index = hashFunction(tdn);
        hashTable[index].push_back(tk);
        if (!dangDoc)
            writeFile();

        return true;
    }

    bool login(string tdn, string mk)
    {
        int index = hashFunction(tdn);

        for (Taikhoan tk : hashTable[index])
        {
            if (tk.gettdn() == tdn)
            {
                return tk.getmk() == mk;
            }
        }

        return false;
    }

    bool deleTK(string tdn, string mk, string email){
        int i = 0; 
        int index = hashFunction(tdn);
        for(Taikhoan tk : hashTable[index]){
            if (tk.gettdn() == tdn && tk.getemail() == email && tk.getmk() == mk){
                hashTable[index].erase(hashTable[index].begin() + i);
                writeFile();
                return true;
            }
            i++;
        }
        return false;
    }

    // ---------------- Phan viet them (khong dong vao cac ham o tren) ----------------

    // Ghi danh sach ra file: dong 1 tdn, dong 2 mk, dong 3 email, cach 1 dong giua cac tai khoan
    bool writeFile(const string& filename = "taikhoan.txt")
    {
        ofstream out(filename);
        if (!out.is_open())
        {
            cout << "Khong mo duoc file de ghi: " << filename << endl;
            return false;
        }
        int count = 0;
        for (vector<Taikhoan>& bucket : hashTable)
        {
            for (Taikhoan& tk : bucket)
            {
                if (count > 0) out << '\n';   // dong trong giua cac tai khoan
                out << tk.gettdn() << '\n';
                out << tk.getmk() << '\n';
                out << tk.getemail() << '\n';
                count++;
            }
        }
        out.close();
        cout << "Da ghi " << count << " tai khoan vao " << filename << endl;
        return true;
    }

    // Doc danh sach tu file, moi tai khoan di qua addTK nen van bi check trung / email sai
    bool readFile(const string& filename = "taikhoan.txt")
    {
        ifstream in(filename);
        if (!in.is_open())
        {
            cout << "Khong mo duoc file de doc: " << filename << endl;
            return false;
        }
        for (vector<Taikhoan>& bucket : hashTable)
            bucket.clear();

        int count = 0;
        string tdn, mk, email;
        dangDoc = true;
        while (getline(in, tdn))
        {
            if (tdn.empty()) continue;           // bo qua dong trong giua cac tai khoan
            if (!getline(in, mk)) break;         // thieu du lieu -> dung
            if (!getline(in, email)) break;
            if (addTK(tdn, mk, email)) count++;
        }
        dangDoc = false;
        in.close();
        cout << "Da doc " << count << " tai khoan tu " << filename << endl;
        return true;
    }

    // In danh sach thanh bang, moi tai khoan 1 dong: tdn 25, mk 25, email 20 ky tu
    void display()
    {
        bool empty = true;
        for (vector<Taikhoan>& bucket : hashTable)
            if (!bucket.empty()) { empty = false; break; }

        if (empty)
        {
            cout << "Danh sach trong" << endl;
            return;
        }
        cout << left << setw(25) << "Ten dang nhap"
             << setw(25) << "Mat khau"
             << setw(20) << "Email" << endl;
        cout << string(70, '-') << endl;
        for (vector<Taikhoan>& bucket : hashTable)
        {
            for (Taikhoan& tk : bucket)
            {
                cout << left << setw(25) << tk.gettdn()
                     << setw(25) << tk.getmk()
                     << setw(20) << tk.getemail() << endl;
            }
        }
    }
};
int main()
{
    Manager_Taikhoan mgr;
    mgr.readFile();

    int chon;
    string tdn, mk, email;
    do
    {
        cout << "\n1. Them tai khoan\n2. Dang nhap\n3. Xoa tai khoan\n4. Hien thi danh sach\n0. Thoat\nChon: ";
        if (!(cin >> chon)) break;
        cin.ignore(1000, '\n');

        if (chon == 1)
        {
            cout << "Nhap Ten Dang Nhap: ";
            getline(cin, tdn);
            cout << "Nhap Mat Khau: ";
            getline(cin, mk);
            cout << "Nhap Email: ";
            getline(cin, email);
            if (mgr.addTK(tdn, mk, email))
            {
                cout << "Them thanh cong" << endl;
            }
        }
        else if (chon == 2)
        {
            cout << "Nhap Ten Dang Nhap: ";
            getline(cin, tdn);
            cout << "Nhap Mat Khau: ";
            getline(cin, mk);
            cout << (mgr.login(tdn, mk) ? "Dang nhap thanh cong" : "Sai ten dang nhap hoac mat khau") << endl;
        }
        else if (chon == 3)
        {
            cout << "Nhap Ten Dang Nhap: ";
            getline(cin, tdn);
            cout << "Nhap Mat Khau: ";
            getline(cin, mk);
            cout << "Nhap Email: ";
            getline(cin, email);
            cout << (mgr.deleTK(tdn, mk, email) ? "Xoa thanh cong" : "Khong tim thay tai khoan") << endl;
        }
        else if (chon == 4)
        {
            mgr.display();
        }
    } while (chon != 0);

    return 0;
}