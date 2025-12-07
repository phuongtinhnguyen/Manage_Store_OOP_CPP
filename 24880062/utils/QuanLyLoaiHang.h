#pragma once
#include "LoaiHang.h"

class QuanLyLoaiHang {
private:
    LoaiHang* ds[200];
    int soLuong;

public:

    // Chức năng:
    // Khởi tạo đối tượng quản lý loại hàng, đặt số lượng ban đầu = 0.
    //
    // Tham số:
    // Không có.
    //
    // Giá trị trả về:
    // Không có.
    QuanLyLoaiHang();

    // Chức năng:
    // Giải phóng bộ nhớ các đối tượng LoaiHang trong danh sách khi hủy đối tượng.
    //
    // Tham số:
    // Không có.
    //
    // Giá trị trả về:
    // Không có.
    ~QuanLyLoaiHang();

    // Chức năng:
    // Hiển thị menu quản lý loại hàng và xử lý lựa chọn của người dùng.
    //
    // Tham số:
    // Không có.
    //
    // Giá trị trả về:
    // Không có.
    void MenuLoaiHang();

    // Chức năng:
    // Thêm một loại hàng mới vào danh sách.
    //
    // Tham số:
    // Không có.
    //
    // Giá trị trả về:
    // Không có.
    void Them();

    // Chức năng:
    // Xóa một loại hàng dựa trên mã loại mà người dùng nhập.
    //
    // Tham số:
    // Không có.
    //
    // Giá trị trả về:
    // Không có.
    void Xoa();

    // Chức năng:
    // Sửa thông tin của một loại hàng đã tồn tại trong danh sách.
    //
    // Tham số:
    // Không có.
    //
    // Giá trị trả về:
    // Không có.
    void Sua();

    // Chức năng:
    // Tìm kiếm loại hàng theo mã, hiển thị nếu tìm thấy.
    //
    // Tham số:
    // Không có.
    //
    // Giá trị trả về:
    // Không có.
    void TimKiem();

    // Chức năng:
    // Hiển thị toàn bộ danh sách loại hàng.
    //
    // Tham số:
    // Không có.
    //
    // Giá trị trả về:
    // Không có.
    void HienThi();
    
    // Chức năng:
    // Đọc danh sách loại hàng từ file CSV và nạp vào danh sách.
    //
    // Tham số:
    // file -> Tên file CSV cần đọc.
    //
    // Giá trị trả về:
    // Không có.
    void DocCSV(const string& file);

    // Chức năng:
    // Ghi toàn bộ danh sách loại hàng ra file CSV.
    //
    // Tham số:
    // file -> Tên file CSV cần ghi.
    //
    // Giá trị trả về:
    // Không có.
    void GhiCSV(const string& file);
};
