#include "QuanLyHoaDon.h"
#include <fstream>
#include <sstream>

QuanLyHoaDon::QuanLyHoaDon() {
    soLuong = 0;
    for (int i = 0; i < 500; ++i) ds[i] = nullptr;
}

QuanLyHoaDon::~QuanLyHoaDon() {
    for (int i = 0; i < soLuong; ++i) if (ds[i]) delete ds[i];
}

void QuanLyHoaDon::ThemBan() {
    if (soLuong >= 500) { cout << "Danh sach day.\n"; return; }
    HoaDonBan* p = new HoaDonBan();
    p->Nhap();
    ds[soLuong++] = p;
}

void QuanLyHoaDon::ThemNhap() {
    if (soLuong >= 500) { cout << "Danh sach day.\n"; return; }
    HoaDonNhap* p = new HoaDonNhap();
    p->Nhap();
    ds[soLuong++] = p;
}

int findHDIndex(HoaDon* arr[], int n, const string& ma) {
    for (int i = 0; i < n; ++i) if (arr[i]) {
        // we don't have getter for maHD; parse ToCSV first
        string csv = arr[i]->ToCSV();
        // maHD is first token
        string token;
        stringstream ss(csv);
        getline(ss, token, ',');
        if (token == ma) return i;
    }
    return -1;
}

void QuanLyHoaDon::Xoa() {
    cout << "Nhap ma hoa don can xoa: ";
    string ma; cin >> ma;
    int idx = -1;
    for (int i = 0; i < soLuong; ++i) {
        if (!ds[i]) continue;
        string csv = ds[i]->ToCSV();
        string token;
        stringstream ss(csv);
        getline(ss, token, ',');
        if (token == ma) { idx = i; break; }
    }
    if (idx == -1) { cout << "Khong tim thay.\n"; return; }
    delete ds[idx];
    for (int i = idx; i < soLuong - 1; ++i) ds[i] = ds[i+1];
    ds[--soLuong] = nullptr;
    cout << "Da xoa.\n";
}

void QuanLyHoaDon::Sua() {
    cout << "Nhap ma hoa don can sua: ";
    string ma; cin >> ma;
    int idx = -1;
    for (int i = 0; i < soLuong; ++i) {
        if (!ds[i]) continue;
        string csv = ds[i]->ToCSV();
        string token;
        stringstream ss(csv);
        getline(ss, token, ',');
        if (token == ma) { idx = i; break; }
    }
    if (idx == -1) { cout << "Khong tim thay.\n"; return; }
    cout << "Nhap thong tin moi:\n";
    ds[idx]->Nhap();
    cout << "Da cap nhat.\n";
}

void QuanLyHoaDon::TimKiem() {
    cout << "Nhap ma hoa don hoac ma hang can tim: ";
    string key; cin >> key;
    bool ok = false;
    for (int i = 0; i < soLuong; ++i) {
        if (!ds[i]) continue;
        string csv = ds[i]->ToCSV();
        if (csv.find(key) != string::npos) {
            ds[i]->Xuat();
            ok = true;
        }
    }
    if (!ok) cout << "Khong co ket qua.\n";
}

void QuanLyHoaDon::HienThi() {
    cout << "Danh sach hoa don:\n";
    for (int i = 0; i < soLuong; ++i) if (ds[i]) ds[i]->Xuat();
}

void QuanLyHoaDon::DocCSV(const string& file, bool laHoaDonBan) {
    ifstream ifs(file);
    if (!ifs.is_open()) return;
    string line;
    while (getline(ifs, line)) {
        if (line.size() == 0) continue;
        if (laHoaDonBan) {
            HoaDonBan* p = new HoaDonBan();
            p->FromCSV(line);
            ds[soLuong++] = p;
        } else {
            HoaDonNhap* p = new HoaDonNhap();
            p->FromCSV(line);
            ds[soLuong++] = p;
        }
    }
    ifs.close();
}

void QuanLyHoaDon::GhiCSV(const string& file) {
    ofstream ofs(file);
    for (int i = 0; i < soLuong; ++i) if (ds[i]) ofs << ds[i]->ToCSV() << "\n";
    ofs.close();
}
