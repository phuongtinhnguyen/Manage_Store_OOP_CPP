#pragma once
#include "HoaDon.h"
#include "LoaiHoaDon.h"

class HoaDonBan : public HoaDon {
private:
    LoaiHoaDon loai;
public:
    HoaDonBan();
    ~HoaDonBan();

    void Nhap(QuanLyMatHang* const qlMH, QuanLyHoaDon* const qlHD) override;
    void Xuat() override;

    LoaiHoaDon GetLoai() override;

    string ToCSV() override;
    void FromCSV(const string& line) override;
};
