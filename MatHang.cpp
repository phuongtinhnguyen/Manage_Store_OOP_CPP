#include "MatHang.h"
#include <fstream>
#include <sstream>

MatHang::MatHang() {
    maHang = "";
    tenHang = "";
    hanDung = "";
    congTy = "";
    namSX = 0;
    maLoai = "";
    soLuong = 0;
}

MatHang::~MatHang() {}

void MatHang::Nhap() {
    cout << "Nhap ma hang: ";
    cin >> maHang;
    cin.ignore();
    cout << "Nhap ten hang: ";
    getline(cin, tenHang);
    cout << "Nhap han dung (YYYY-MM-DD): ";
    getline(cin, hanDung);
    cout << "Nhap cong ty san xuat: ";
    getline(cin, congTy);
    cout << "Nhap nam san xuat: ";
    cin >> namSX;
    cout << "Nhap ma loai: ";
    cin >> maLoai;
    cout << "Nhap so luong: ";
    cin >> soLuong;
}

void MatHang::Xuat() {
    cout << "Ma: " << maHang
         << " | Ten: " << tenHang
         << " | HanDung: " << hanDung
         << " | CongTy: " << congTy
         << " | NamSX: " << namSX
         << " | MaLoai: " << maLoai
         << " | SoLuong: " << soLuong
         << endl;
}

string MatHang::GetMaHang() {
    return maHang;
}

string MatHang::GetHanDung() {
    return hanDung;
}

int MatHang::GetSoLuong() {
    return soLuong;
}

void MatHang::SetSoLuong(int sl) {
    soLuong = sl;
}

string MatHang::ToCSV() {
    stringstream ss;
    ss << maHang << "," << tenHang << "," << hanDung << "," << congTy << "," << namSX << "," << maLoai << "," << soLuong;
    return ss.str();
}

void MatHang::FromCSV(const string& line) {
    stringstream ss(line);
    string tmp;
    getline(ss, maHang, ',');
    getline(ss, tenHang, ',');
    getline(ss, hanDung, ',');
    getline(ss, congTy, ',');
    getline(ss, tmp, ','); namSX = stoi(tmp);
    getline(ss, maLoai, ',');
    getline(ss, tmp, ','); soLuong = stoi(tmp);
}
