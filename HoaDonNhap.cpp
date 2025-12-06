#include <sstream>
#include <iostream>
#include "HoaDonNhap.h"
#include "QuanLyHoaDon.h"
#include "QuanLyMatHang.h"
using namespace std;

HoaDonNhap::HoaDonNhap() : HoaDon() {
    loai = LoaiHoaDon::Nhap;
}
HoaDonNhap::~HoaDonNhap() {}

void HoaDonNhap::Nhap(QuanLyMatHang* const qlMH, QuanLyHoaDon* const qlHD) {
    cout << "Hoa Don Nhap:" << endl;

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
            if (!hd || hd->GetLoai() != LoaiHoaDon::Nhap)
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
    if (!mh) {
        cout << "Ma hang chua ton tai, tao moi.\n";
        mh = new MatHang();
        mh->SetMaHang(maHang);
        mh->Nhap(false);
        qlMH->ThemMatHangMoi(mh);
        soLuong = mh->GetSoLuong();
    } else {
        cout << "Nhap so luong nhap: ";
        cin >> soLuong;
        cin.ignore();
        if (soLuong <= 0)
        {
            cout << "So luong khong hop le!\n";
            return;
        }
        mh->SetSoLuong(mh->GetSoLuong() + soLuong);
    }

    cout << "Da them hoa don nhap.\n";
}

void HoaDonNhap::Xuat() {
    cout << "[NHAP] MaHD: " << maHD
         << " | Ngay: " << ngayLap
         << " | MaHang: " << maHang
         << " | SoLuong: " << soLuong << "\n";
}

LoaiHoaDon HoaDonNhap::GetLoai()
{ 
    return loai; 
}

string HoaDonNhap::ToCSV() {
    stringstream ss;
    ss << maHD << "," << ngayLap << "," << maHang << "," << soLuong;
    return ss.str();
}

void HoaDonNhap::FromCSV(const string& line) {
    stringstream ss(line);
    string tmp;
    getline(ss, maHD, ',');
    getline(ss, ngayLap, ',');
    getline(ss, maHang, ',');
    getline(ss, tmp, ','); soLuong = stoi(tmp);
}
