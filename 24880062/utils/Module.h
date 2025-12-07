#pragma once
#include <string>

using namespace std;

// Chức năng:
// Chuyển toàn bộ chuỗi s thành chữ thường.
//
// Tham số:
// s -> Chuỗi cần chuyển sang chữ thường.
//
// Giá trị trả về:
// Chuỗi mới đã được chuyển thành chữ thường.
string ToLower(const string &s);

// Chức năng:
// Kiểm tra xem chuỗi ngày tháng có hợp lệ theo định dạng dd-mm-yyyy hay không.
//
// Tham số:
// date -> Chuỗi ngày tháng cần kiểm tra.
//
// Giá trị trả về:
// true nếu ngày hợp lệ.
// false nếu ngày không hợp lệ.
bool IsValidDate(const string& date);  // Hàm kiểm tra hợp lệ ngày

// Chức năng:
// Nhập vào một ngày hợp lệ, tự kiểm tra và yêu cầu nhập lại đến khi đúng.
//
// Tham số:
// prompt -> Chuỗi thông báo hiển thị cho người dùng.
//
// Giá trị trả về:
// Chuỗi ngày tháng hợp lệ theo định dạng dd-mm-yyyy.
string InputValidDate(const string& prompt);  // Hàm nhập ngày hợp lệ
