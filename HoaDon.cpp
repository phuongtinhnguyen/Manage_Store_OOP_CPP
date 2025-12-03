#include "HoaDon.h"
#include <sstream>

HoaDon::HoaDon() {
    maHD = "";
    ngayLap = "";
    maHang = "";
    soLuong = 0;
}

HoaDon::~HoaDon() {}

void HoaDon::Nhap() {
    cout << "Nhap ma hoa don: ";
    cin >> maHD;
    cout << "Nhap ngay lap (YYYY-MM-DD): ";
    cin >> ngayLap;
    cout << "Nhap ma hang: ";
    cin >> maHang;
    cout << "Nhap so luong: ";
    cin >> soLuong;
}

void HoaDon::Xuat() {
    cout << "MaHD: " << maHD << " | Ngay: " << ngayLap << " | MaHang: " << maHang << " | SoLuong: " << soLuong << endl;
}

string HoaDon::GetMaHang() {
    return maHang;
}

int HoaDon::GetSoLuong() {
    return soLuong;
}
