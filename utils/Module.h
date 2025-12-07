#pragma once
#include <string>

using namespace std;

string ToLower(const string &s);

bool IsValidDate(const string& date);  // Hàm kiểm tra hợp lệ ngày
string InputValidDate(const string& prompt);  // Hàm nhập ngày hợp lệ
