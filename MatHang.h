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

    void Nhap(bool nhapMa = true);
    void Xuat();

    string GetMaHang();
    string GetHanDung();
    int GetSoLuong();
    string GetTenHang();
    string GetCongTy();
    int GetNamSX();
    string GetMaLoai();

    void SetSoLuong(int sl);
    void SetMaHang(const string &ma);

    string ToCSV();
    void FromCSV(const string& line);
};
