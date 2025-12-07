#pragma once
#include <iostream>
#include "HoaDon.h"
#include "MatHang.h"
#include "LoaiHoaDon.h"
using namespace std;

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
