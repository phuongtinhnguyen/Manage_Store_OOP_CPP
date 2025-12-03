#pragma once
#include <iostream>
#include <string>
using namespace std;

class LoaiHang {
private:
    string maLoai;
    string tenLoai;

public:
    LoaiHang();
    ~LoaiHang();

    void Nhap();
    void Xuat();

    string GetMaLoai();
    string ToCSV();
    void FromCSV(const string& line);
};
