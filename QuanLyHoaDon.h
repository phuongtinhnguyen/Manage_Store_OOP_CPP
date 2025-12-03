#pragma once
#include "HoaDonBan.h"
#include "HoaDonNhap.h"

class QuanLyHoaDon {
private:
    HoaDon* ds[500];
    int soLuong;

public:
    QuanLyHoaDon();
    ~QuanLyHoaDon();

    void ThemBan();
    void ThemNhap();
    void Xoa();
    void Sua();
    void TimKiem();
    void HienThi();

    void DocCSV(const string& file, bool laHoaDonBan);
    void GhiCSV(const string& file);
};
