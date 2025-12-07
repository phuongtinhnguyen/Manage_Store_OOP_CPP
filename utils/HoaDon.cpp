#include <sstream>
#include "HoaDon.h"
#include "QuanLyHoaDon.h"
#include "Module.h"
#include <iomanip>

HoaDon::HoaDon() {
    maHD = "";
    ngayLap = "";
    maHang = "";
    soLuong = 0;
}

HoaDon::~HoaDon() {}

void HoaDon::Nhap(QuanLyMatHang* const qlMH, QuanLyHoaDon* const qlHD) {
    ngayLap = InputValidDate("Nhap ngay lap (DD-MM-YYYY): ");

    if (maHD == "")
    {
        cout << "Nhap ma hoa don: ";
        cin >> maHD;
        cin.ignore();
    }
}

void HoaDon::Xuat() {
    cout << left
         << "Ma Hoa Don: " << setw(10) << maHD
         << " | Ngay Lap: " << setw(12) << ngayLap
         << " | Ma Hang: " << setw(12) << maHang
         << " | So Luong: " << setw(10) << soLuong
         << endl;
}

string HoaDon::GetMaHD() const {
    return maHD;
}

string HoaDon::GetMaHang() {
    return maHang;
}

int HoaDon::GetSoLuong() {
    return soLuong;
}

void HoaDon::SetMaHD(const string& s) {
    maHD = s;
}

void HoaDon::SetNgayLap(const string& s) {
    ngayLap = s;
}

void HoaDon::SetMaHang(const string& s) {
    maHang = s;
}

void HoaDon::SetSoLuong(int sl) {
    if (sl > 0) 
        soLuong = sl;
}
