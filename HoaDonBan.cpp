#include "HoaDonBan.h"
#include <sstream>

HoaDonBan::HoaDonBan() : HoaDon() {}
HoaDonBan::~HoaDonBan() {}

string HoaDonBan::ToCSV() {
    stringstream ss;
    ss << maHD << "," << ngayLap << "," << maHang << "," << soLuong;
    return ss.str();
}

void HoaDonBan::FromCSV(const string& line) {
    stringstream ss(line);
    string tmp;
    getline(ss, maHD, ',');
    getline(ss, ngayLap, ',');
    getline(ss, maHang, ',');
    getline(ss, tmp, ','); soLuong = stoi(tmp);
}
