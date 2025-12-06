#include "MatHang.h"
#include <fstream>
#include <sstream>
#include <iomanip>

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

void MatHang::Nhap(bool nhapMa) {
    if (nhapMa) {
        cout << "Nhap ma hang: ";
        cin >> maHang;
        cin.ignore();
    }
    cout << "Nhap ten hang: ";
    getline(cin, tenHang);
    cout << "Nhap han dung (DD-MM-YYYY): ";
    getline(cin, hanDung);
    cout << "Nhap cong ty san xuat: ";
    getline(cin, congTy);
    cout << "Nhap nam san xuat: ";
    cin >> namSX;
    cin.ignore();
    cout << "Nhap ma loai: ";
    cin >> maLoai;
    cin.ignore();
    cout << "Nhap so luong: ";
    cin >> soLuong;
    cin.ignore();
}

void MatHang::Xuat() {
    cout << left 
         << setw(6) << maHang
         << " | " << setw(20) << tenHang
         << " | " << setw(12) << hanDung
         << " | " << setw(15) << congTy
         << " | " << setw(6) << namSX
         << " | " << setw(6) << maLoai
         << " | " << setw(6) << soLuong
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

string MatHang::GetTenHang() {
    return tenHang;
}

string MatHang::GetCongTy() {
    return congTy;
}

int MatHang::GetNamSX() {
    return namSX;
}

string MatHang::GetMaLoai() {
    return maLoai;
}

void MatHang::SetSoLuong(int sl) {
    if (sl < 0) {
        return;
    }
    soLuong = sl;
}

void MatHang::SetMaHang(const string &ma) {
    maHang = ma;
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
    getline(ss, tmp, ',');
    namSX = stoi(tmp);
    getline(ss, maLoai, ',');
    getline(ss, tmp, ',');
    soLuong = stoi(tmp);
}
