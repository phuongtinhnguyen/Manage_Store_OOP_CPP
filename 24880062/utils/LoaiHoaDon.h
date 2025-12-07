#pragma once

// Chức năng:
// Định nghĩa kiểu liệt kê (enum class) để biểu diễn loại hóa đơn
// trong hệ thống. Giúp phân biệt hóa đơn nhập và hóa đơn bán.
//
// Giá trị:
// - LoaiHoaDon::Nhap  -> Hóa đơn nhập hàng vào kho.
// - LoaiHoaDon::Ban   -> Hóa đơn bán hàng ra khỏi kho.
//
// Ý nghĩa sử dụng:
// enum class giúp tránh nhầm lẫn giữa các kiểu số nguyên
//
// Tham số truyền vào: 
// Không có.
//
// Giá trị trả về:
// Không có (đây chỉ là khai báo kiểu).
enum class LoaiHoaDon { Nhap, Ban };
