#pragma once
#include <iostream>
#include <string>
using namespace std;

class MatHang {
private:
    string maHang;
    string tenHang;
    string hanDung;
    string congTy;
    int namSX;
    string maLoai;
    int soLuong;

public:
    MatHang();
    ~MatHang();

    void Nhap();
    void Xuat();

    string GetMaHang();
    string GetHanDung();
    int GetSoLuong();
    void SetSoLuong(int sl);

    string ToCSV();
    void FromCSV(const string& line);
};
