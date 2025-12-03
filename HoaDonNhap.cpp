#include "HoaDonNhap.h"
#include <sstream>

HoaDonNhap::HoaDonNhap() : HoaDon() {}
HoaDonNhap::~HoaDonNhap() {}

string HoaDonNhap::ToCSV() {
    stringstream ss;
    ss << maHD << "," << ngayLap << "," << maHang << "," << soLuong;
    return ss.str();
}

void HoaDonNhap::FromCSV(const string& line) {
    stringstream ss(line);
    string tmp;
    getline(ss, maHD, ',');
    getline(ss, ngayLap, ',');
    getline(ss, maHang, ',');
    getline(ss, tmp, ','); soLuong = stoi(tmp);
}
