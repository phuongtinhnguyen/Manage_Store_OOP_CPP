#pragma once
#include <iostream>
#include <string>
#include "QuanLyMatHang.h"
#include "LoaiHoaDon.h"
using namespace std;

// forward declaration
class QuanLyHoaDon;

class HoaDon {
protected:
    string maHD;
    string ngayLap;
    string maHang;
    int soLuong;

public:

    // Chức năng:
    // Khởi tạo đối tượng hóa đơn với các giá trị mặc định.
    //
    // Tham số truyền vào:
    // Không có.
    //
    // Ý nghĩa giá trị trả về:
    // Không có (constructor).
    HoaDon();

    // Chức năng:
    // Giải phóng bộ nhớ và tài nguyên nếu có.
    //
    // Tham số truyền vào:
    // Không có.
    //
    // Ý nghĩa giá trị trả về:
    // Không có (destructor).
    virtual ~HoaDon();

    // Chức năng:
    // Nhập thông tin hóa đơn từ người dùng (ngày lập, mã hàng, số lượng...).
    //
    // Tham số truyền vào:
    // qlMH: Con trỏ đến bộ quản lý mặt hàng để kiểm tra mã hàng tồn tại.
    // qlHD: Con trỏ đến bộ quản lý hóa đơn để kiểm tra trùng mã hóa đơn.
    //
    // Ý nghĩa giá trị trả về:
    // Không có (void).
    virtual void Nhap(QuanLyMatHang* const qlMH, QuanLyHoaDon* const qlHD);

    // Chức năng:
    // Xuất thông tin hóa đơn ra màn hình.
    //
    // Tham số truyền vào:
    // Không có.
    //
    // Ý nghĩa giá trị trả về:
    // Không có (void).
    virtual void Xuat();

    // Chức năng:
    // Trả về mã hóa đơn.
    //
    // Tham số truyền vào:
    // Không có.
    //
    // Ý nghĩa giá trị trả về:
    // Chuỗi chứa mã hóa đơn.
    string GetMaHD() const;

    // Chức năng:
    // Trả về mã hàng của hóa đơn.
    string GetMaHang();

    // Chức năng:
    // Trả về số lượng mặt hàng trong hóa đơn.
    int GetSoLuong();

    // Chức năng:
    // Gán mã hóa đơn.
    //
    // s: Chuỗi mã hóa đơn mới.
    void SetMaHD(const string& s);

    // Chức năng:
    // Gán ngày lập hóa đơn.
    void SetNgayLap(const string& s);

    // Chức năng:
    // Gán mã hàng.
    void SetMaHang(const string& s);

    // Chức năng:
    // Gán số lượng hàng.
    void SetSoLuong(int sl);

    // Chức năng:
    // Trả về loại hóa đơn (Nhập hoặc Bán).
    // Là hàm thuần ảo, buộc lớp dẫn xuất phải định nghĩa (HoaDonBan và HoaDonNhap).
    //
    // Giá trị trả về:
    // LoaiHoaDon (enum class): Nhap hoặc Ban.
    virtual LoaiHoaDon GetLoai() = 0;

    // Chức năng:
    // Chuyển dữ liệu hóa đơn sang một dòng CSV (để lưu file).
    // Hàm thuần ảo.
    //
    // Giá trị trả về:
    // Chuỗi CSV chứa thông tin của hóa đơn.
    virtual string ToCSV() = 0;

    // Chức năng:
    // Đọc dữ liệu hóa đơn từ một dòng CSV.
    // Hàm thuần ảo.
    //
    // line: Chuỗi chứa 1 dòng CSV.
    //
    // Giá trị trả về:
    // Không có (void).
    virtual void FromCSV(const string& line) = 0;
};
