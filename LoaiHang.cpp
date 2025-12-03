#include "LoaiHang.h"
#include <sstream>

LoaiHang::LoaiHang() {}
LoaiHang::~LoaiHang() {}

void LoaiHang::Nhap() {
    cout << "Nhap ma loai: ";
    cin >> maLoai;
    cout << "Nhap ten loai: ";
    cin.ignore();
    getline(cin, tenLoai);
}


void LoaiHang::Xuat() {
    cout << maLoai << " - " << tenLoai << endl;
}

string LoaiHang::GetMaLoai() { return maLoai; }

string LoaiHang::ToCSV() {
    return maLoai + "," + tenLoai;
}

void LoaiHang::FromCSV(const string& line) {
    stringstream ss(line);
    getline(ss, maLoai, ',');
    getline(ss, tenLoai, ',');
}
