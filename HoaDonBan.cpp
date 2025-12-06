#include <regex>
#include <sstream>
#include <iostream>
#include "MatHang.h"
#include "HoaDonBan.h"
#include "QuanLyMatHang.h"
#include "QuanLyHoaDon.h"
using namespace std;

HoaDonBan::HoaDonBan() : HoaDon() {
    loai = LoaiHoaDon::Ban;
}
HoaDonBan::~HoaDonBan() {}

void HoaDonBan::Nhap(QuanLyMatHang* const qlMH, QuanLyHoaDon* const qlHD) {

    cout << "Hoa Don Ban:" << endl;
    if (!qlMH)
    { 
        cout << "Chua gan QuanLyMatHang!\n";
        return;
    }

    if (!qlHD)
    { 
        cout << "Chua gan QuanLyHoaDon!\n";
        return;
    }

    // Nhap: ngayLap, maHD
    HoaDon::Nhap(qlMH, qlHD); 

    // Kiểm tra maHD
    // Nhap moi hoa don thi kiem tra, sua hoa don (da ton tai maHang) thi khong kiem tra
    if(maHang == "") 
    {
        while (true) {
            HoaDon* hd = qlHD->TimTheoMa(maHD, loai);
            if (!hd || hd->GetLoai() != LoaiHoaDon::Ban)
                break;
            cout << "Ma hoa don bi trung! Nhap lai: ";
            cin >> maHD;
            cin.ignore();
        }
    }

    // Nhap maHang
    cout << "Nhap ma hang: ";
    cin >> maHang;
    cin.ignore();

    // Kiem tra maHang
    MatHang* mh = qlMH->TimTheoMa(maHang);

    while (mh == nullptr || mh->GetSoLuong() <= 0)
    {
        cout << "Ma hang khong ton tai hoac so luong trong kho = 0!\n";
        cout << "Vui long nhap ma hang khac: ";
        cin >> maHang;
        cin.ignore();

        mh = qlMH->TimTheoMa(maHang);
    }

    // Nhap soLuong
    cout << "Nhap so luong ban: ";
    cin >> soLuong;
    cin.ignore();

    // Kiem tra soLuong
    // MatHang* mh = qlMH->TimTheoMa(maHang);
    while (soLuong <= 0 || soLuong > mh->GetSoLuong())
    {
        cout << "So luong khong hop le hoac vuot qua ton kho (" << mh->GetSoLuong() << ")!" << endl;
        cout << "Vui long nhap lai so luong khac: ";
        cin >> soLuong;
        cin.ignore();
    }

    mh->SetSoLuong(mh->GetSoLuong() - soLuong);

    cout << "Da them hoa don ban.\n";
}

void HoaDonBan::Xuat() {
    cout << "[BAN] MaHD: " << maHD
         << " | Ngay: " << ngayLap
         << " | MaHang: " << maHang
         << " | SoLuong: " << soLuong << "\n";
}

LoaiHoaDon HoaDonBan::GetLoai()
{ 
    return loai; 
}

string HoaDonBan::ToCSV() {
    stringstream ss;
    ss << maHD << "," << ngayLap << "," << maHang << "," << soLuong;
    return ss.str();
}

void HoaDonBan::FromCSV(const string& line) {
    stringstream ss(line);
    string tmp;
    getline(ss, maHD, ',');
    getline(ss, ngayLap, ',');
    getline(ss, maHang, ',');
    getline(ss, tmp, ',');
    soLuong = stoi(tmp);
}
