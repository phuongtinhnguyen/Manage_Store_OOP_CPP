#pragma once
#include "MatHang.h"

class QuanLyMatHang {
private:
    MatHang* ds[500];
    int soLuong;

public:
    QuanLyMatHang();
    ~QuanLyMatHang();

    void Them();
    void Xoa();
    void Sua();
    void TimKiem();
    void HienThi();

    MatHang* TimTheoMa(const string& ma);
    void ThemMatHangMoi(MatHang* p);

    // void CapNhatNhapKho(string maHang, int sl);
    // void CapNhatBanHang(string maHang, int sl);

    void ThongKeTonKho();
    void ThongKeHetHan();

    void DocCSV(const string& file);
    void GhiCSV(const string& file);
};
