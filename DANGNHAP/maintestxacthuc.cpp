// main.cpp - file khac goi thu vien xac_thuc.h
#include <iostream>
#include "xac_thuc.h"

int main() {
    DangNhap dn;   // doc/ghi file tai_khoan.txt
    std::string chon;
    for (;;) {
        std::cout << "\n[1] Dang nhap  [2] Dang ky  [0] Thoat\n";
        if (!xt::hoi("Chon: ", chon) || chon == "0") break;

        if (chon == "1") {
            std::string tdn, mk;
            if (!xt::hoi("Ten dang nhap: ", tdn) || !xt::hoi("Mat khau: ", mk)) break;

            int kq = dn.dangNhap(tdn, mk);          // <-- 1 / 2 / 3 / 0
            if (kq == 1) std::cout << "Ket qua = 1: ADMIN\n";
            else if (kq == 2) std::cout << "Ket qua = 2: USER\n";
            else if (kq == 3) std::cout << "Ket qua = 3: BAC SI\n";
            else std::cout << "Ket qua = 0: khong dang nhap duoc\n";
        } else if (chon == "2") {
            dn.dangKy();
        }
    }
}