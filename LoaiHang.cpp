#include "LoaiHang.h"
#include <sstream>

LoaiHang::LoaiHang() {
    maLoai = "";
    tenLoai = "";
}
LoaiHang::~LoaiHang() {}

void LoaiHang::Nhap() {
    cout << "Nhap ten loai: ";
    getline(cin, tenLoai);
}

void LoaiHang::Xuat() {
    cout << maLoai << " - " << tenLoai << endl;
}

string LoaiHang::GetMaLoai() {
    return maLoai;
}

void LoaiHang::SetMaLoai(const string &ma) {
    maLoai = ma;
}

string LoaiHang::ToCSV() {
    return maLoai + "," + tenLoai;
}

void LoaiHang::FromCSV(const string& line) {
    stringstream ss(line);
    getline(ss, maLoai, ',');
    getline(ss, tenLoai, ',');
}
