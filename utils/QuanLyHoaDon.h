#pragma once
#include "HoaDonBan.h"
#include "HoaDonNhap.h"
#include "QuanLyMatHang.h"
#include <string>
using namespace std;

class QuanLyHoaDon {
private:
    HoaDon* ds[500];
    int soLuong;
    QuanLyMatHang* qlMH;

public:
    QuanLyHoaDon();
    ~QuanLyHoaDon();

    void MenuHoaDon();

    void Them();
    void Xoa();
    void Sua();
    void TimKiem();
    void HienThi();

    void SetQLMH(QuanLyMatHang* p);
    HoaDon* TimTheoMa(const string& ma, LoaiHoaDon loai);
    
    int GetSoLuong() const {
        return soLuong;
    }

    void DocCSV(const string& file, LoaiHoaDon loai);
    void GhiCSV(const string& file, LoaiHoaDon loai);
};
