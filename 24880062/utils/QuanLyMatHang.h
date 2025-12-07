#pragma once
#include "MatHang.h"

class QuanLyMatHang {
private:
    MatHang* ds[500];
    int soLuong;

public:

    // Chức năng:
    // Khởi tạo đối tượng quản lý mặt hàng, đặt số lượng ban đầu = 0.
    //
    // Tham số:
    // Không có.
    //
    // Giá trị trả về:
    // Không có.
    QuanLyMatHang();

    // Chức năng:
    // Giải phóng bộ nhớ tất cả các đối tượng MatHang đã được cấp phát.
    //
    // Tham số:
    // Không có.
    //
    // Giá trị trả về:
    // Không có.
    ~QuanLyMatHang();

    // Chức năng:
    // Hiển thị menu quản lý mặt hàng và xử lý lựa chọn của người dùng.
    //
    // Tham số:
    // Không có.
    //
    // Giá trị trả về:
    // Không có.
    void MenuMatHang();

    // Chức năng:
    // Thêm một mặt hàng mới vào danh sách.
    //
    // Tham số:
    // Không có.
    //
    // Giá trị trả về:
    // Không có.
    void Them();

    // Chức năng:
    // Xóa một mặt hàng dựa trên mã hàng người dùng nhập.
    //
    // Tham số:
    // Không có.
    //
    // Giá trị trả về:
    // Không có.
    void Xoa();

    // Chức năng:
    // Sửa thông tin của một mặt hàng đã tồn tại trong danh sách.
    //
    // Tham số:
    // Không có.
    //
    // Giá trị trả về:
    // Không có.
    void Sua();

    // Chức năng:
    // Tìm kiếm mặt hàng theo mã và hiển thị nếu tìm thấy.
    //
    // Tham số:
    // Không có.
    //
    // Giá trị trả về:
    // Không có.
    void TimKiem();

    // Chức năng:
    // Hiển thị toàn bộ danh sách mặt hàng.
    //
    // Tham số:
    // Không có.
    //
    // Giá trị trả về:
    // Không có.
    void HienThi();

    // Chức năng:
    // Tìm một mặt hàng trong danh sách dựa trên mã hàng.
    //
    // Tham số:
    // ma -> Mã mặt hàng cần tìm.
    //
    // Giá trị trả về:
    // Con trỏ MatHang nếu tìm thấy, nullptr nếu không tồn tại.
    MatHang* TimTheoMa(const string& ma);

    // Chức năng:
    // Thêm một mặt hàng mới vào danh sách (sử dụng khi tự tạo mặt hàng trong code).
    //
    // Tham số:
    // p -> Con trỏ đến đối tượng MatHang cần thêm.
    //
    // Giá trị trả về:
    // Không có.
    void ThemMatHangMoi(MatHang* p);

    // Chức năng:
    // Thống kê các mặt hàng còn tồn kho (soLuong > 0).
    //
    // Tham số:
    // Không có.
    //
    // Giá trị trả về:
    // Không có.
    void ThongKeTonKho();

    // Chức năng:
    // Thống kê các mặt hàng đã hết hạn sử dụng (dựa vào hanDung).
    //
    // Tham số:
    // Không có.
    //
    // Giá trị trả về:
    // Không có.
    void ThongKeHetHan();

    // Chức năng:
    // Đọc danh sách mặt hàng từ file CSV và nạp vào danh sách hiện tại.
    //
    // Tham số:
    // file -> Tên file CSV cần đọc.
    //
    // Giá trị trả về:
    // Không có.
    void DocCSV(const string& file);

    // Chức năng:
    // Ghi toàn bộ danh sách mặt hàng ra file CSV.
    //
    // Tham số:
    // file -> Tên file CSV cần ghi.
    //
    // Giá trị trả về:
    // Không có.
    void GhiCSV(const string& file);
};
