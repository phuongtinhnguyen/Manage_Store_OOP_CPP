#pragma once
#include <iostream>
#include <string>
#include "QuanLyMatHang.h"
#include "LoaiHoaDon.h"

class QuanLyHoaDon; // <-- forward declaration
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

    virtual void Nhap(QuanLyMatHang* const qlMH, QuanLyHoaDon* const qlHD);
    virtual void Xuat();

    string GetMaHD() const;
    string GetMaHang();
    int GetSoLuong();

    void SetMaHD(const string& s);
    void SetNgayLap(const string& s);
    void SetMaHang(const string& s);
    void SetSoLuong(int sl);


    virtual LoaiHoaDon GetLoai() = 0;
    virtual string ToCSV() = 0;
    virtual void FromCSV(const string& line) = 0;
};
