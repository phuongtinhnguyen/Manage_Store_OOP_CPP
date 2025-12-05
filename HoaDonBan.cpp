#include "HoaDonBan.h"
#include <sstream>
#include <iostream>
#include "MatHang.h"
#include "QuanLyMatHang.h"
#include "QuanLyHoaDon.h"
#include <regex>
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
    // while (qlHD->TimTheoMa(maHD))
    // {
    //     cout << "Ma hoa don bi trung!";
    //     cout << "Vui long nhap lai ma hoa don khac: ";
    //     cin >> maHD;
    // }
    // Nhap moi hoa don thi kiem tra, sua hoa don (da ton tai maHang) thi khong kiem tra
    if(maHang == "") 
    {
        while (true) {
            HoaDon* hd = qlHD->TimTheoMa(maHD, loai);
            if (!hd || hd->GetLoai() != LoaiHoaDon::Ban)
                break;
            cout << "Ma hoa don bi trung! Nhap lai: ";
            cin >> maHD;
        }
    }

    // Nhap maHang
    cout << "Nhap ma hang: ";
    cin >> maHang;

    // Kiem tra maHang
    while (!qlMH->TimTheoMa(maHang))
    {
        cout << "Khong ton tai ma hang nay!";
        cout << "Vui long nhap lai ma hang khac: ";
        cin >> maHang;
    }

    // Nhap soLuong
    cout << "Nhap so luong ban: ";
    cin >> soLuong;

    // Kiem tra soLuong
    MatHang* mh = qlMH->TimTheoMa(maHang);
    while (soLuong <= 0 || soLuong > mh->GetSoLuong())
    {
        cout << "So luong khong hop le hoac vuot qua ton kho (" << mh->GetSoLuong() << ")!" << endl;
        cout << "Vui long nhap lai so luong khac: ";
        cin >> soLuong;
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
