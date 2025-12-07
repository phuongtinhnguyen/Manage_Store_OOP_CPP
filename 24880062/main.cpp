#include <iostream>
#include "utils/QuanLyLoaiHang.h"
#include "utils/QuanLyMatHang.h"
#include "utils/QuanLyHoaDon.h"
using namespace std;

int main() {
    QuanLyLoaiHang qlLoai;
    QuanLyMatHang qlHang;
    QuanLyHoaDon qlHD;

    qlLoai.DocCSV("data/loaihang.csv");
    qlHang.DocCSV("data/mathang.csv");

    qlHD.SetQLMH(&qlHang);
    qlHD.DocCSV("data/hoadonban.csv", LoaiHoaDon::Ban);
    qlHD.DocCSV("data/hoadonnhap.csv", LoaiHoaDon::Nhap);

    int chon;
    do {
        cout << "\n===== MENU QUAN LY CUA HANG =====\n";
        cout << "1. Quan ly LOAI HANG\n";
        cout << "2. Quan ly MAT HANG\n";
        cout << "3. Quan ly HOA DON\n";
        cout << "4. Thong ke ton kho\n";
        cout << "5. Thong ke het han\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> chon;
        cin.ignore();

        switch (chon) {
        case 1: qlLoai.MenuLoaiHang(); break;
        case 2: qlHang.MenuMatHang(); break;
        case 3: qlHD.MenuHoaDon(); break;
        case 4: qlHang.ThongKeTonKho(); break;
        case 5: qlHang.ThongKeHetHan(); break;
        }
    } while (chon != 0);

    qlLoai.GhiCSV("data/loaihang.csv");
    qlHang.GhiCSV("data/mathang.csv");
    qlHD.GhiCSV("data/hoadonban.csv", LoaiHoaDon::Ban);
    qlHD.GhiCSV("data/hoadonnhap.csv", LoaiHoaDon::Nhap);

    return 0;
}
