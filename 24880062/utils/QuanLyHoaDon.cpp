#include "QuanLyHoaDon.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
using namespace std;

QuanLyHoaDon::QuanLyHoaDon() : soLuong(0) {
    for (int i = 0; i < 500; ++i)
        {
            ds[i] = nullptr;
        }
}

QuanLyHoaDon::~QuanLyHoaDon() {
    for (int i = 0; i < soLuong; ++i)
        if (ds[i]) delete ds[i];
}

void QuanLyHoaDon::MenuHoaDon() {
    int chonChucNang;
    do {
        cout << "\n=== QUAN LY HOA DON ===\n";
        cout << "1. Them hoa don\n";
        cout << "2. Xoa hoa don\n";
        cout << "3. Sua hoa don\n";
        cout << "4. Tim kiem hoa don\n";
        cout << "5. Hien thi danh sach\n";
        cout << "0. Quay lai\n";
        cout << "Chon: ";
        cin >> chonChucNang;
        cin.ignore();

        switch (chonChucNang) {
        case 1:
            this->Them();
            break;
        case 2:
            this->Xoa();
            break;
        case 3:
            this->Sua();
            break;
        case 4:
            this->TimKiem();
            break;
        case 5:
            this->HienThi();
            break;
        }
    } while (chonChucNang != 0);
}

void QuanLyHoaDon::SetQLMH(QuanLyMatHang* p)
{
    qlMH = p;
}

void QuanLyHoaDon::Them() {
    int chonLoai;
    do {
        cout << "Nhap loai hoa don (1. Hoa don ban, 2. Hoa don nhap): ";
        cin >> chonLoai;
        cin.ignore();
    }
    while (chonLoai != 1 && chonLoai !=2);

    if(chonLoai == 1)
    {
        ds[soLuong] = new HoaDonBan();
    }
    else
    {
        ds[soLuong] = new HoaDonNhap();
    }
    ds[soLuong]->Nhap(qlMH, this);
    soLuong++;
    cout << "Da them hoa don.\n";
}

void QuanLyHoaDon::Xoa() {

    int chonLoai;
    LoaiHoaDon loai;
    do {
        cout << "Nhap loai hoa don (1. Hoa don ban, 2. Hoa don nhap): ";
        cin >> chonLoai;
        cin.ignore();
    }
    while (chonLoai != 1 && chonLoai !=2);

    if(chonLoai == 1)
    {
        loai = LoaiHoaDon::Ban;
    }
    else
    {
        loai = LoaiHoaDon::Nhap;
    }

    string ma;
    cout << "Nhap ma hoa don can xoa: ";
    cin >> ma;
    cin.ignore();
    int idx = -1;
    for (int i = 0; i < soLuong; ++i)
    {
        if (ds[i] && ds[i]->GetMaHD() == ma && ds[i]->GetLoai() == loai)
        {
            idx = i;
            break;
        }
    }
    if (idx == -1)
    {
        cout << "Khong tim thay.\n";
        return;
    }

    // Rollback kho truoc khi xoa
    MatHang* mh = qlMH->TimTheoMa(ds[idx]->GetMaHang());
    if(ds[idx]->GetLoai() == LoaiHoaDon::Ban)
    {
        if (mh) {
            mh->SetSoLuong(mh->GetSoLuong() + ds[idx]->GetSoLuong());
        }
    }
    else
    {
        if (mh) {
            if (ds[idx]->GetLoai() == LoaiHoaDon::Nhap) {
                if (mh->GetSoLuong() < ds[idx]->GetSoLuong()) {
                    cout << "Khong the xoa. Ton kho khong du de rollback!\n";
                    return;
                }
                mh->SetSoLuong(mh->GetSoLuong() - ds[idx]->GetSoLuong());
            }

        }
    }

    delete ds[idx];
    for (int i = idx; i < soLuong - 1; ++i)
    {
        ds[i] = ds[i + 1];
    }
    ds[--soLuong] = nullptr;
    cout << "Da xoa.\n";
}

void QuanLyHoaDon::Sua() {
    int chonLoai;
    LoaiHoaDon loai;
    do {
        cout << "Nhap loai hoa don (1. Hoa don ban, 2. Hoa don nhap): ";
        cin >> chonLoai;
        cin.ignore();
    }
    while (chonLoai != 1 && chonLoai !=2);

    if(chonLoai == 1)
    {
        loai = LoaiHoaDon::Ban;
        
    }
    else
    {
        loai = LoaiHoaDon::Nhap;
    }

    string ma;
    cout << "Nhap ma hoa don can sua: ";
    cin >> ma;
    cin.ignore();
    int idx = -1;
    for (int i = 0; i < soLuong; ++i)
    {
        if (ds[i] && ds[i]->GetMaHD() == ma && ds[i]->GetLoai() == loai)
        {
            idx = i;
            break;
        }
    }
    if (idx == -1)
    {
        cout << "Khong tim thay.\n";
        return;
    }

    // Rollback kho truoc khi sua
    MatHang* mh = qlMH->TimTheoMa(ds[idx]->GetMaHang());
    if(ds[idx]->GetLoai() == LoaiHoaDon::Ban)
    {
        if (mh) {
            mh->SetSoLuong(mh->GetSoLuong() + ds[idx]->GetSoLuong()); 
        }
    }
    else
    {
        if (mh) {
            // mh->SetSoLuong(mh->GetSoLuong() - ds[idx]->GetSoLuong());

            if (ds[idx]->GetLoai() == LoaiHoaDon::Nhap) {
                if (mh->GetSoLuong() < ds[idx]->GetSoLuong()) {
                    cout << "Khong the xoa. Ton kho khong du de rollback!\n";
                    return;
                }
                mh->SetSoLuong(mh->GetSoLuong() - ds[idx]->GetSoLuong());
            }

        }
    }
    ds[idx]->Nhap(qlMH, this);
    cout << "Da cap nhat.\n";
}

void QuanLyHoaDon::TimKiem() {
    int loai;
    cout << "Nhap loai hoa don (1. Hoa don ban, 2. Hoa don nhap): ";
    cin >> loai;
    cin.ignore();

    while (loai != 1 && loai != 2) {
        cout << "Lua chon khong hop le. Nhap lai (1-Ban, 2-Nhap): ";
        cin >> loai;
        cin.ignore();
    }

    string key;
    cout << "Nhap ma hoa don hoac ma hang can tim: ";
    cin >> key;
    cin.ignore();

    bool ok = false;

    for (int i = 0; i < soLuong; ++i) {
        if (!ds[i]) continue;

        // Lọc theo loại
        if ((loai == 1 && ds[i]->GetLoai() != LoaiHoaDon::Ban) ||
            (loai == 2 && ds[i]->GetLoai() != LoaiHoaDon::Nhap))
            continue;

        // Lọc theo mã
        if (ds[i]->GetMaHD() == key || ds[i]->GetMaHang() == key) {
            ds[i]->Xuat();
            ok = true;
        }
    }

    if (!ok) cout << "Khong co ket qua.\n";
}

void QuanLyHoaDon::HienThi() {
    int chon;
    cout << "Nhap loai hoa don (1. Hoa don ban, 2. Hoa don nhap): ";
    cin >> chon;
    cin.ignore();

    LoaiHoaDon loai;
    if (chon == 1)
        loai = LoaiHoaDon::Ban;
    else if (chon == 2)
        loai = LoaiHoaDon::Nhap;
    else {
        cout << "Lua chon khong hop le!\n";
        return;
    }

    cout << "\nDanh sach hoa don "
         << (loai == LoaiHoaDon::Ban ? "BAN" : "NHAP") << ":\n";

    bool found = false;
    for (int i = 0; i < soLuong; ++i) {
        if (ds[i] && ds[i]->GetLoai() == loai) {
            ds[i]->Xuat();
            found = true;
        }
    }

    if (!found)
        cout << "Khong co hoa don nao thuoc loai nay!\n";
}

HoaDon* QuanLyHoaDon::TimTheoMa(const string& ma, LoaiHoaDon loai) {
    for (int i = 0; i < soLuong; ++i) {
        if (ds[i] 
            && ds[i]->GetMaHD() == ma 
            && ds[i]->GetLoai() == loai)
        {
            return ds[i];
        }
    }
    return nullptr;
}

void QuanLyHoaDon::DocCSV(const string& file, LoaiHoaDon loai) {
    ifstream ifs(file);
    if (!ifs.is_open()) return;

    string line;
    while (getline(ifs, line)) {
        if (line.empty()) continue;

        HoaDon* p = (loai == LoaiHoaDon::Ban) ? (HoaDon*)new HoaDonBan() : (HoaDon*)new HoaDonNhap();
        p->FromCSV(line);

        // Nếu đã có hóa đơn cùng mã và cùng loại => skip để tránh duplicate
        if (TimTheoMa(p->GetMaHD(), loai) != nullptr) {
            delete p;
            continue;
        }

        if (soLuong >= 500) {
            cout << "Vuot qua gioi han 500 hoa don!\n";
            delete p;
            ifs.close();
            return;
        }
        ds[soLuong++] = p;
    }
    ifs.close();
}

void QuanLyHoaDon::GhiCSV(const string& file, LoaiHoaDon loai) {
    ofstream ofs(file); if (!ofs.is_open()) return;
    for (int i = 0; i < soLuong; ++i)
        if (ds[i] && ds[i]->GetLoai() == loai)
            ofs << ds[i]->ToCSV() << "\n";
    ofs.close();
}
