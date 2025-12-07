#pragma once
#include "HoaDon.h"
#include "LoaiHoaDon.h"

class HoaDonBan : public HoaDon {
private:
    LoaiHoaDon loai;
public:
    // Chức năng:
    // Khởi tạo hóa đơn bán với giá trị mặc định.
    // Thiết lập loại hóa đơn = LoaiHoaDon::Ban.
    //
    // Tham số truyền vào:
    // Không có.
    //
    // Ý nghĩa giá trị trả về:
    // Không có (constructor).
    HoaDonBan();

    // Chức năng:
    // Hủy đối tượng hóa đơn bán.
    //
    // Tham số truyền vào:
    // Không có.
    //
    // Ý nghĩa giá trị trả về:
    // Không có (destructor).
    ~HoaDonBan();

    // Chức năng:
    // Nhập thông tin hóa đơn bán (ngày lập, mã hàng, số lượng...).
    // Kiểm tra mã hàng và kiểm tra trùng mã hóa đơn thông qua qlMH và qlHD.
    //
    // Tham số truyền vào:
    // qlMH: Con trỏ tới bộ quản lý mặt hàng.
    // qlHD: Con trỏ tới bộ quản lý hóa đơn.
    //
    // Ý nghĩa giá trị trả về:
    // Không có (void).
    void Nhap(QuanLyMatHang* const qlMH, QuanLyHoaDon* const qlHD) override;

    // Chức năng:
    // Xuất thông tin hóa đơn bán ra màn hình.
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
    // LoaiHoaDon::Ban.
    LoaiHoaDon GetLoai() override;

    // Chức năng:
    // Chuyển toàn bộ thông tin hóa đơn bán sang dạng chuỗi CSV để lưu file.
    // Ví dụ: "BAN,HD01,20-12-2025,SP01,5"
    //
    // Tham số truyền vào:
    // Không có.
    //
    // Ý nghĩa giá trị trả về:
    // Chuỗi CSV.
    string ToCSV() override;

    // Chức năng:
    // Đọc và phân tích một dòng CSV, khôi phục dữ liệu cho hóa đơn bán.
    //
    // Tham số truyền vào:
    // line: Chuỗi CSV chứa thông tin hóa đơn.
    //
    // Ý nghĩa giá trị trả về:
    // Không có (void).
    void FromCSV(const string& line) override;
};
