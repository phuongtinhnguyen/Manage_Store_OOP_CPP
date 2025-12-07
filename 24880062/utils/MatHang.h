#pragma once
#include <iostream>
#include <string>
using namespace std;

class MatHang {
private:
    string maHang;
    string tenHang;
    string hanDung;
    string congTy;
    int namSX;
    string maLoai;
    int soLuong;

public:
    // Chức năng:
    // Hàm dựng khởi tạo giá trị mặc định cho mặt hàng.
    //
    // Tham số: không
    // Trả về: không
    MatHang();

    // Chức năng:
    // Giải phóng tài nguyên (nếu có).
    ~MatHang();

    // Chức năng:
    // Nhập thông tin mặt hàng từ bàn phím.
    //
    // Tham số truyền vào:
    // - nhapMa: true -> cho phép nhập mã hàng,
    //            false -> giữ nguyên mã hàng hiện có (dùng khi sửa).
    //
    // Trả về: không.
    void Nhap(bool nhapMa = true);

    // Chức năng:
    // Xuất thông tin mặt hàng ra màn hình.
    //
    // Tham số: không.
    // Trả về: không.
    void Xuat();

    // Các hàm getter:
    // Trả về các thông tin thành viên tương ứng:
    // - Mã hàng
    // - Hạn dùng
    // - Số lượng tồn
    // - Tên hàng
    // - Công ty
    // - Năm sản xuất
    // - Mã loại hàng
    string GetMaHang();
    string GetHanDung();
    int GetSoLuong();
    string GetTenHang();
    string GetCongTy();
    int GetNamSX();
    string GetMaLoai();

    // Hàm setter:
    // Thay đổi số lượng tồn
    void SetSoLuong(int sl);

    // Đặt mã hàng
    void SetMaHang(const string &ma);

    // Chức năng:
    // Chuyển thông tin mặt hàng thành chuỗi CSV.
    //
    // Trả về:
    // Chuỗi dạng "maHang,tenHang,hanDung,congTy,namSX,maLoai,soLuong"
    string ToCSV();

    // Chức năng:
    // Đọc dữ liệu từ một dòng CSV và gán vào thuộc tính.
    //
    // Tham số:
    // - line: chuỗi CSV của 1 mặt hàng.
    //
    // Trả về: không.
    void FromCSV(const string& line);
};
