#include <iostream>
#include "QuanLyLoaiHang.h"
#include "QuanLyMatHang.h"
#include "QuanLyHoaDon.h"
using namespace std;

void MenuLoaiHang(QuanLyLoaiHang &ql) {
    int chon;
    do {
        cout << "\n=== QUAN LY LOAI HANG ===\n";
        cout << "1. Them loai hang\n";
        cout << "2. Xoa loai hang\n";
        cout << "3. Sua loai hang\n";
        cout << "4. Tim kiem loai hang\n";
        cout << "5. Hien thi danh sach\n";
        cout << "0. Quay lai\n";
        cout << "Chon: ";
        cin >> chon;
        cin.ignore();

        switch (chon) {
        case 1: ql.Them(); break;
        case 2: ql.Xoa(); break;
        case 3: ql.Sua(); break;
        case 4: ql.TimKiem(); break;
        case 5: ql.HienThi(); break;
        }
    } while (chon != 0);
}

void MenuMatHang(QuanLyMatHang &ql) {
    int chon;
    do {
        cout << "\n=== QUAN LY MAT HANG ===\n";
        cout << "1. Them mat hang\n";
        cout << "2. Xoa mat hang\n";
        cout << "3. Sua mat hang\n";
        cout << "4. Tim kiem mat hang\n";
        cout << "5. Hien thi danh sach\n";
        cout << "0. Quay lai\n";
        cout << "Chon: ";
        cin >> chon;
        cin.ignore();

        switch (chon) {
        case 1: ql.Them(); break;
        case 2: ql.Xoa(); break;
        case 3: ql.Sua(); break;
        case 4: ql.TimKiem(); break;
        case 5: ql.HienThi(); break;
        }
    } while (chon != 0);
}

void MenuHoaDon(QuanLyHoaDon &ql) {
    int chonChucNang;
    do {
        cout << "\n=== QUAN LY HOA DON ===\n";
        cout << "1. Them hoa don\n";
        cout << "2. Xoa hoa don\n";
        cout << "3. Sua hoa don\n";
        cout << "4. Tim kiem hoa don\n";
        cout << "5. Hien thi danh sach\n";
        cout << "0. Quay lai\n";
        cout << "Chon: ";
        cin >> chonChucNang;
        cin.ignore();

        switch (chonChucNang) {
        case 1:
            ql.Them();
            break;
        case 2:
            ql.Xoa();
            break;
        case 3:
            ql.Sua();
            break;
        case 4:
            ql.TimKiem();
            break;
        case 5:
            ql.HienThi();
            break;
        }
    } while (chonChucNang != 0);
}

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
        case 1: MenuLoaiHang(qlLoai); break;
        case 2: MenuMatHang(qlHang); break;
        case 3: MenuHoaDon(qlHD); break;
        case 4: qlHang.ThongKeTonKho(); break;
        case 5: qlHang.ThongKeHetHan(); break;
        }
    } while (chon != 0);

    // ghi lại file theo loại hóa đơn
    qlLoai.GhiCSV("data/loaihang.csv");
    qlHang.GhiCSV("data/mathang.csv");
    qlHD.GhiCSV("data/hoadonban.csv", LoaiHoaDon::Ban);   // chỉ ghi hóa đơn bán
    qlHD.GhiCSV("data/hoadonnhap.csv", LoaiHoaDon::Nhap); // chỉ ghi hóa đơn nhập

    return 0;
}

