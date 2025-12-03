#pragma once
#include <iostream>
#include <string>
using namespace std;

class HoaDon {
protected:
    string maHD;
    string ngayLap;
    string maHang;
    int soLuong;

public:
    HoaDon();
    virtual ~HoaDon();

    virtual void Nhap();
    virtual void Xuat();

    string GetMaHang();
    int GetSoLuong();

    virtual string ToCSV() = 0;
    virtual void FromCSV(const string& line) = 0;
};
