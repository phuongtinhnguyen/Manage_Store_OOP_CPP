#pragma once
#include "LoaiHang.h"

class QuanLyLoaiHang {
private:
    LoaiHang* ds[200];
    int soLuong;

public:
    QuanLyLoaiHang();
    ~QuanLyLoaiHang();

    void Them();
    void Xoa();
    void Sua();
    void TimKiem();
    void HienThi();

    void DocCSV(const string& file);
    void GhiCSV(const string& file);
};
