#include <sstream>
#include <regex>
#include "HoaDon.h"
#include "QuanLyHoaDon.h"

HoaDon::HoaDon() {
    maHD = "";
    ngayLap = "";
    maHang = "";
    soLuong = 0;
}

HoaDon::~HoaDon() {}

void HoaDon::Nhap(QuanLyMatHang* const qlMH, QuanLyHoaDon* const qlHD) {
    regex re_date(R"(^\d{2}-\d{2}-\d{4}$)");
    while (true)
    {
        cout << "Nhap ngay lap (DD-MM-YYYY): ";
        cin >> ngayLap;
        cin.ignore();

        if (!regex_match(ngayLap, re_date)) {
            cout << "Sai dinh dang! Vui long nhap theo dang DD-MM-YYYY.\n";
            continue;
        }

        int d = stoi(ngayLap.substr(0, 2));
        int m = stoi(ngayLap.substr(3, 2));
        int y = stoi(ngayLap.substr(6, 4));

        bool valid = true;

        if (m < 1 || m > 12) valid = false;
        else {
            int daysInMonth;
            switch (m) {
                case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                    daysInMonth = 31; break;
                case 4: case 6: case 9: case 11:
                    daysInMonth = 30; break;
                case 2:
                    // Năm nhuận
                    if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
                        daysInMonth = 29;
                    else
                        daysInMonth = 28;
                    break;
            }

            if (d < 1 || d > daysInMonth) valid = false;
        }

        if (!valid) {
            cout << "Ngay khong hop le! Vui long nhap lai.\n";
            continue;
        }

        break; // Ngày hợp lệ
    }

    if (maHD == "")
    {
        cout << "Nhap ma hoa don: ";
        cin >> maHD;
        cin.ignore();
    }
}

void HoaDon::Xuat() {
    cout << "MaHD: " << maHD
         << " | Ngay: " << ngayLap
         << " | MaHang: " << maHang
         << " | SoLuong: " << soLuong << endl;
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
