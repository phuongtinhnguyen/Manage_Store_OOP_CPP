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
    int chon;
    do {
        cout << "\n=== QUAN LY HOA DON ===\n";
        cout << "1. Quan ly HOA DON BAN\n";
        cout << "2. Quan ly HOA DON NHAP\n";
        cout << "0. Quay lai\n";
        cout << "Chon: ";
        cin >> chon;

        if (chon == 1 || chon == 2) {
            bool laBan = (chon == 1);
            int c2;
            do {
                cout << "\n=== ";
                if (laBan) cout << "HOA DON BAN ===\n";
                else cout << "HOA DON NHAP ===\n";

                cout << "1. Them hoa don\n";
                cout << "2. Xoa hoa don\n";
                cout << "3. Sua hoa don\n";
                cout << "4. Tim kiem hoa don\n";
                cout << "5. Hien thi danh sach\n";
                cout << "0. Quay lai\n";
                cout << "Chon: ";
                cin >> c2;

                switch (c2) {
                case 1:
                    if (laBan) ql.ThemBan();
                    else ql.ThemNhap();
                    break;

                case 2: ql.Xoa(); break;
                case 3: ql.Sua(); break;
                case 4: ql.TimKiem(); break;
                case 5: ql.HienThi(); break;
                }
            } while (c2 != 0);
        }

    } while (chon != 0);
}


int main() {
    QuanLyLoaiHang qlLoai;
    QuanLyMatHang qlHang;
    QuanLyHoaDon qlHD;

    qlLoai.DocCSV("data/loaihang.csv");
    qlHang.DocCSV("data/mathang.csv");
    qlHD.DocCSV("data/hoadonban.csv", true);
    qlHD.DocCSV("data/hoadonnhap.csv", false);

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

        switch (chon) {
        case 1: MenuLoaiHang(qlLoai); break;
        case 2: MenuMatHang(qlHang); break;
        case 3: MenuHoaDon(qlHD); break;
        case 4: qlHang.ThongKeTonKho(); break;
        case 5: qlHang.ThongKeHetHan(); break;
        }
    } while (chon != 0);

    qlLoai.GhiCSV("data/loaihang.csv");
    qlHang.GhiCSV("data/mathang.csv");
    qlHD.GhiCSV("data/hoadonban.csv");
    qlHD.GhiCSV("data/hoadonnhap.csv");

    return 0;
}
