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

        // Chức năng:
        // Khởi tạo hóa đơn nhập với các giá trị mặc định.
        // Thiết lập loại hóa đơn = LoaiHoaDon::Nhap.
        //
        // Tham số truyền vào:
        // Không có.
        //
        // Ý nghĩa giá trị trả về:
        // Không có (constructor).
        HoaDonNhap();

        // Chức năng:
        // Hủy đối tượng hóa đơn nhập.
        //
        // Tham số truyền vào:
        // Không có.
        //
        // Ý nghĩa giá trị trả về:
        // Không có (destructor).
        ~HoaDonNhap();

        // Chức năng:
        // Nhập thông tin hóa đơn nhập (ngày lập, mã hàng, số lượng...).
        // Kiểm tra mã hàng, kiểm tra trùng mã hóa đơn thông qua qlMH và qlHD.
        // Khi nhập hàng, số lượng tồn kho sẽ được tăng thêm.
        //
        // Tham số truyền vào:
        // qlMH: Con trỏ tới đối tượng quản lý mặt hàng.
        // qlHD: Con trỏ tới đối tượng quản lý hóa đơn.
        //
        // Ý nghĩa giá trị trả về:
        // Không có (void).
        void Nhap(QuanLyMatHang* const qlMH, QuanLyHoaDon* const qlHD) override;

        // Chức năng:
        // Xuất thông tin hóa đơn nhập ra màn hình.
        //
        // Tham số truyền vào:
        // Không có.
        //
        // Ý nghĩa giá trị trả về:
        // Không có (void).
        void Xuat() override;

        // Chức năng:
        // Trả về loại hóa đơn.
        //
        // Tham số truyền vào:
        // Không có.
        //
        // Ý nghĩa giá trị trả về:
        // LoaiHoaDon::Nhap.
        LoaiHoaDon GetLoai() override;

        // Chức năng:
        // Chuyển toàn bộ thông tin hóa đơn nhập sang chuỗi CSV.
        //
        // Tham số truyền vào:
        // Không có.
        //
        // Ý nghĩa giá trị trả về:
        // Chuỗi CSV biểu diễn hóa đơn nhập.
        string ToCSV() override;

        // Chức năng:
        // Đọc một dòng CSV và gán dữ liệu vào các thuộc tính của hóa đơn nhập.
        //
        // Tham số truyền vào:
        // line: Chuỗi CSV chứa thông tin hóa đơn.
        //
        // Ý nghĩa giá trị trả về:
        // Không có (void).
        void FromCSV(const string& line) override;
};
