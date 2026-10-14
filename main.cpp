#include <iostream>
#include <fstream>
#include <limits>
#include <string>

#include "Input_util.h"
#include "Manager_doctor.h"
#include "Manager_patient.h"
#include "Manager_Medicine.h"
#include "Manager_DonThuoc.h"

using namespace std;

// string FILE_PATIENT = "C:\\C++\\PBL2\\1.patient.txt";
string FILE_PATIENT = "C:\\C++\\PBL2\\1.patient.txt";
string FILE_DOCTOR  = "C:\\C++\\PBL2\\2.Danhsachbacsi.txt";
string FILE_THUOC   = "C:\\C++\\PBL2\\3.Thuoc.txt";
string FILE_DON     = "C:\\C++\\PBL2\\4.Donthuoc.txt";

int docLuaChon(const string &thongbao)
{
    int x;
    if (!docSoNguyen(thongbao, x))
        return 0;
    return x;
}

void tamDung()
{
    cout << "\nNhan Enter de tiep tuc...";
    string s;
    getline(cin, s);
}

// MENU BAC SI
void menuBacSi(Manager_Doctor &ds)
{
    int chon;
    do
    {
        cout << "\n========== QUAN LY BAC SI ==========\n";
        cout << "1. Xem danh sach bac si\n";
        cout << "2. Them bac si moi\n";
        cout << "3. Tim bac si theo ten\n";
        cout << "4. Tim bac si theo chuyen nganh\n";
        cout << "5. Sua thong tin bac si\n";
        cout << "6. Xoa bac si theo CCCD\n";
        cout << "0. Quay lai\n";
        cout << "====================================\n";
        chon = docLuaChon("Lua chon cua ban: ");

        switch (chon)
        {
        case 1:
            ds.display();
            break;
        case 2:
            ds.input();
            ds.saveToFile(FILE_DOCTOR);
            cin.ignore(1000, '\n'); // bo '\n' con sot sau cin >> soca
            break;
        case 3:
            ds.search_namedoctor();
            break;
        case 4:
            ds.search_chuyennganhdoctor();
            break;
        case 5:
            ds.change_doctor(FILE_DOCTOR);
            break;
        case 6:
        {
            cout << "Nhap CCCD bac si can xoa: ";
            string cccd;
            getline(cin, cccd);
            ds.delete_cccddoctor(cccd, FILE_DOCTOR);
            break;
        }
        case 0:
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }
        if (chon != 0)
            tamDung();
    } while (chon != 0);
}

// ====================== MENU BENH NHAN ======================
void menuBenhNhan(manager_patient &ds)
{
    int chon;
    do
    {
        cout << "\n========== QUAN LY BENH NHAN ==========\n";
        cout << "1. Xem danh sach benh nhan\n";
        cout << "2. Them benh nhan moi\n";
        cout << "3. Tim benh nhan theo ten\n";
        cout << "4. Tim benh nhan theo CCCD\n";
        cout << "5. Sua thong tin benh nhan\n";
        cout << "6. Xoa benh nhan (chua cai dat)\n";
        cout << "0. Quay lai\n";
        cout << "=======================================\n";
        chon = docLuaChon("Lua chon cua ban: ");

        switch (chon)
        {
        case 1:
            ds.display();
            break;
        case 2:
            ds.addPatient(FILE_PATIENT);
            cin.ignore(1000, '\n'); // bo '\n' con sot sau date.nhap()
            break;
        case 3:
            ds.search_name();
            break;
        case 4:
            ds.search_cccd();
            break;
        case 5:
            ds.editPatient(FILE_PATIENT);
            break;
        case 6:
            cout << "Chuc nang dang phat trien (can them ham xoa vao Manager_patient).\n";
            break;
        case 0:
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }
        if (chon != 0)
            tamDung();
    } while (chon != 0);
}

// ====================== MENU THUOC ======================
void menuThuoc(Manager_Thuoc &kho)
{
    int chon;
    do
    {
        cout << "\n========== QUAN LY THUOC ==========\n";
        cout << "1. Xem danh sach thuoc\n";
        cout << "2. Them thuoc moi\n";
        cout << "3. Tim thuoc theo ten / ma\n";
        cout << "4. Cap nhat don gia / so luong ton\n";
        cout << "5. Xoa thuoc\n";
        cout << "6. Thuoc sap het hang\n";
        cout << "0. Quay lai\n";
        cout << "===================================\n";
        chon = docLuaChon("Lua chon cua ban: ");

        switch (chon)
        {
        case 1:
            kho.display();
            break;
        case 2:
            kho.addThuoc(FILE_THUOC);
            break;
        case 3:
            kho.searchThuoc();
            break;
        // case 4:
        //     kho.updateMedicine(FILE_THUOC);
        //     break;
        case 5:
            kho.deleteThuoc(FILE_THUOC);
            break;
        case 0:
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }
        if (chon != 0)
            tamDung();
    } while (chon != 0);
}

// ====================== MENU DON THUOC ======================
void menuDonThuoc(Manager_DonThuoc &don, Manager_Doctor &bacsi,
                  manager_patient &benhnhan, Manager_Thuoc &kho)
{
    int chon;
    do
    {
        cout << "\n========== KE DON THUOC ==========\n";
        cout << "1. Ke don thuoc moi\n";
        cout << "2. Xem tat ca don thuoc da ke\n";
        cout << "3. Xem don thuoc theo CCCD benh nhan\n";
        cout << "4. Xem don thuoc theo CCCD bac si\n";
        cout << "0. Quay lai\n";
        cout << "==================================\n";
        chon = docLuaChon("Lua chon cua ban: ");

        switch (chon)
        {
        case 1:
            don.keDon(bacsi, benhnhan, kho, FILE_DON, FILE_THUOC);
            break;
        case 2:
            don.displayAll();
            break;
        case 3:
            don.displayByPatient();
            break;
        case 4:
            don.displayByDoctor();
            break;
        case 0:
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }
        if (chon != 0)
            tamDung();
    } while (chon != 0);
}

// ====================== MAIN ======================
int main()
{
    Manager_Doctor doctors;
    manager_patient patients;
    Manager_Thuoc kho;
    Manager_DonThuoc donthuoc;

    ifstream fd(FILE_DOCTOR);
    doctors.readFile(fd);
    fd.close();

    ifstream fp(FILE_PATIENT);

if (!fp.is_open())
{
    cout << "Khong mo duoc file benh nhan: "
         << FILE_PATIENT << endl;
}
else
{
    cout << "Mo file benh nhan thanh cong!\n";
    patients.readFile(fp);
}

fp.close();

    ifstream fthuoc(FILE_THUOC);
    kho.readFile(fthuoc);
    fthuoc.close();

    ifstream fdon(FILE_DON);
    donthuoc.readFile(fdon);
    fdon.close();

    int chon;
    do
    {
        cout << "\n################################################\n";
        cout << "#          QUAN LY BENH VIEN - PBL2            #\n";
        cout << "################################################\n";
        cout << "  1. Quan ly bac si\n";
        cout << "  2. Quan ly benh nhan\n";
        cout << "  3. Quan ly thuoc\n";
        cout << "  4. Ke don thuoc\n";
        cout << "  0. Thoat chuong trinh\n";
        cout << "################################################\n";
        chon = docLuaChon("Lua chon cua ban: ");

        switch (chon)
        {
        case 1:
            menuBacSi(doctors);
            break;
        case 2:
            menuBenhNhan(patients);
            break;
        case 3:
            menuThuoc(kho);
            break;
        case 4:
            menuDonThuoc(donthuoc, doctors, patients, kho);
            break;
        case 0:
            cout << "Tam biet!\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }
    } while (chon != 0);

    return 0;
}
