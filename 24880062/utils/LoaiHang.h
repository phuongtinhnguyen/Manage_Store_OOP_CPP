#pragma once
#include <iostream>
#include <string>
using namespace std;

class LoaiHang {
private:
    string maLoai;
    string tenLoai;

public:

    // Chức năng:
    // Khởi tạo đối tượng LoaiHang với giá trị mặc định (chuỗi rỗng).
    //
    // Tham số truyền vào:
    // Không có.
    //
    // Ý nghĩa giá trị trả về:
    // Không có (constructor).
    LoaiHang();

    // Chức năng:
    // Hủy đối tượng LoaiHang.
    //
    // Tham số truyền vào:
    // Không có.
    //
    // Ý nghĩa giá trị trả về:
    // Không có (destructor).
    ~LoaiHang();

    // Chức năng:
    // Nhập thông tin loại hàng từ bàn phím (mã loại và tên loại).
    //
    // Tham số truyền vào:
    // Không có.
    //
    // Ý nghĩa giá trị trả về:
    // Không có (void).
    void Nhap();

    // Chức năng:
    // Xuất thông tin loại hàng ra màn hình.
    //
    // Tham số truyền vào:
    // Không có.
    //
    // Ý nghĩa giá trị trả về:
    // Không có (void).
    void Xuat();

    // Chức năng:
    // Lấy mã loại hàng.
    //
    // Tham số truyền vào:
    // Không có.
    //
    // Ý nghĩa giá trị trả về:
    // Trả về chuỗi mã loại hàng.
    string GetMaLoai();

    // Chức năng:
    // Gán giá trị cho mã loại hàng.
    //
    // Tham số truyền vào:
    // ma: Chuỗi mã loại cần gán.
    //
    // Ý nghĩa giá trị trả về:
    // Không có (void).
    void SetMaLoai(const string &ma);

    // Chức năng:
    // Chuyển toàn bộ thông tin loại hàng thành một dòng CSV.
    //
    // Tham số truyền vào:
    // Không có.
    //
    // Ý nghĩa giá trị trả về:
    // Chuỗi CSV biểu diễn loại hàng.
    string ToCSV();

    // Chức năng:
    // Đọc và phân tách một dòng CSV, gán dữ liệu vào maLoai và tenLoai.
    //
    // Tham số truyền vào:
    // line: Chuỗi CSV chứa thông tin loại hàng.
    //
    // Ý nghĩa giá trị trả về:
    // Không có (void).
    void FromCSV(const string& line);
};
