#pragma once
#include "HoaDon.h"
#include "MatHang.h"
#include <iostream>
using namespace std;
#include "LoaiHoaDon.h"
class HoaDonNhap : public HoaDon {
private:
    LoaiHoaDon loai;
public:
    HoaDonNhap();
    ~HoaDonNhap();

    void Nhap(QuanLyMatHang* const qlMH, QuanLyHoaDon* const qlHD) override;
    void Xuat() override;
    LoaiHoaDon GetLoai() override;

    string ToCSV() override;
    void FromCSV(const string& line) override;
};
