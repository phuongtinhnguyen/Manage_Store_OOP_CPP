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

    // Chức năng:
    // Khởi tạo đối tượng quản lý hóa đơn, đặt số lượng ban đầu = 0.
    //
    // Tham số:
    // Không có.
    //
    // Giá trị trả về:
    // Không có.
    QuanLyHoaDon();

    // Chức năng:
    // Giải phóng các hóa đơn trong danh sách khi đối tượng bị hủy.
    //
    // Tham số:
    // Không có.
    //
    // Giá trị trả về:
    // Không có.
    ~QuanLyHoaDon();

    // Chức năng:
    // Hiển thị menu quản lý hóa đơn và điều hướng lựa chọn của người dùng.
    //
    // Tham số:
    // Không có.
    //
    // Giá trị trả về:
    // Không có.
    void MenuHoaDon();

    // Chức năng:
    // Thêm một hóa đơn mới (nhập hoặc bán) vào danh sách.
    //
    // Tham số:
    // Không có.
    //
    // Giá trị trả về:
    // Không có.
    void Them();

    // Chức năng:
    // Xóa một hóa đơn dựa trên mã hóa đơn người dùng nhập.
    //
    // Tham số:
    // Không có.
    //
    // Giá trị trả về:
    // Không có.
    void Xoa();

    // Chức năng:
    // Sửa thông tin của một hóa đơn đã tồn tại.
    //
    // Tham số:
    // Không có.
    //
    // Giá trị trả về:
    // Không có.
    void Sua();

    // Chức năng:
    // Tìm kiếm hóa đơn theo mã, hiển thị nếu tìm thấy.
    //
    // Tham số:
    // Không có.
    //
    // Giá trị trả về:
    // Không có.
    void TimKiem();

    // Chức năng:
    // Hiển thị toàn bộ danh sách hóa đơn.
    //
    // Tham số:
    // Không có.
    //
    // Giá trị trả về:
    // Không có.
    void HienThi();

    // Chức năng:
    // Thiết lập danh sách quản lý mặt hàng để phục vụ kiểm tra mã hàng
    // và cập nhật tồn kho khi thêm hóa đơn.
    //
    // Tham số:
    // p -> Con trỏ đến quản lý mặt hàng.
    //
    // Giá trị trả về:
    // Không có.
    void SetQLMH(QuanLyMatHang* p);

    // Chức năng:
    // Tìm hóa đơn theo mã và loại hóa đơn.
    //
    // Tham số:
    // ma -> Chuỗi mã hóa đơn cần tìm.
    // loai -> Loại hóa đơn cần so khớp (Nhập hoặc Bán).
    //
    // Giá trị trả về:
    // Con trỏ đến hóa đơn nếu tìm thấy.
    // nullptr nếu không tìm thấy.
    HoaDon* TimTheoMa(const string& ma, LoaiHoaDon loai);
    
    // Chức năng:
    // Lấy tổng số lượng hóa đơn hiện có.
    //
    // Tham số:
    // Không có.
    //
    // Giá trị trả về:
    // Số lượng hóa đơn.
    int GetSoLuong() const {
        return soLuong;
    }

    // Chức năng:
    // Đọc dữ liệu hóa đơn từ file CSV và nạp vào danh sách.
    //
    // Tham số:
    // file -> Tên file CSV cần đọc.
    // loai -> Loại hóa đơn cần đọc (Nhập hoặc Bán).
    //
    // Giá trị trả về:
    // Không có.
    void DocCSV(const string& file, LoaiHoaDon loai);

    // Chức năng:
    // Ghi toàn bộ danh sách hóa đơn ra file CSV.
    //
    // Tham số:
    // file -> Tên file CSV cần ghi.
    // loai -> Loại hóa đơn cần ghi (Nhập hoặc Bán).
    //
    // Giá trị trả về:
    // Không có. 
    void GhiCSV(const string& file, LoaiHoaDon loai);
};
