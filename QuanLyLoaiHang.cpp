#include "QuanLyLoaiHang.h"
#include <fstream>
#include <sstream>
#include "Module.h"

QuanLyLoaiHang::QuanLyLoaiHang() {
    soLuong = 0;
    for (int i = 0; i < 200; ++i) ds[i] = nullptr;
}

QuanLyLoaiHang::~QuanLyLoaiHang() {
    for (int i = 0; i < soLuong; ++i) {
        if (ds[i]) delete ds[i];
    }
}

void QuanLyLoaiHang::Them() {
    if (soLuong >= 200) {
        cout << "Danh sach day.\n";
        return;
    }

    string ma;
    cout << "Nhap ma loai: ";
    cin >> ma;

    // kiểm tra mã loại trùng
    for (int i = 0; i < soLuong; ++i) {
        if (ds[i] && ds[i]->GetMaLoai() == ma) {
            cout << "Ma loai da ton tai! Khong the them.\n";
            return;
        }
    }

    // nếu không trùng thì tạo và nhập tên
    LoaiHang* p = new LoaiHang();
    p->SetMaLoai(ma);
    cin.ignore(); // dọn bộ nhớ đệm trước getline
    p->Nhap();    // chỉ nhập tên loai
    ds[soLuong++] = p;

    cout << "Da them loai hang.\n";
}


int findIndex(LoaiHang* arr[], int n, const string& ma) {
    for (int i = 0; i < n; ++i) if (arr[i] && arr[i]->GetMaLoai() == ma) return i;
    return -1;
}

void QuanLyLoaiHang::Xoa() {
    cout << "Nhap ma loai can xoa: ";
    string ma; cin >> ma;
    int idx = findIndex(ds, soLuong, ma);
    if (idx == -1) {
        cout << "Khong tim thay.\n";
        return;
    }
    delete ds[idx];
    for (int i = idx; i < soLuong - 1; ++i) ds[i] = ds[i+1];
    ds[--soLuong] = nullptr;
    cout << "Da xoa.\n";
}

void QuanLyLoaiHang::Sua() {
    cout << "Nhap ma loai can sua: ";
    string ma; cin >> ma;
    int idx = findIndex(ds, soLuong, ma);
    if (idx == -1) { cout << "Khong tim thay.\n"; return; }
    cout << "Nhap thong tin moi:\n";
    ds[idx]->Nhap();
    cout << "Da cap nhat.\n";
}

void QuanLyLoaiHang::TimKiem() {
    cout << "Nhap ma hoac ten can tim: ";
    string key; 
    cin.ignore();
    getline(cin, key);
    key = ToLower(key);  // chuyển key về chữ thường

    bool ok = false;
    for (int i = 0; i < soLuong; ++i) {
        if (ds[i]) {
            // so sánh mã loại
            if (ToLower(ds[i]->GetMaLoai()) == key) {
                ds[i]->Xuat();
                ok = true;
            } else {
                // hoặc tìm trong CSV
                string csv = ToLower(ds[i]->ToCSV());
                if (csv.find(key) != string::npos) {
                    ds[i]->Xuat();
                    ok = true;
                }
            }
        }
    }

    if (!ok) cout << "Khong co ket qua.\n";
}

void QuanLyLoaiHang::HienThi() {
    cout << "Danh sach loai hang:\n";
    for (int i = 0; i < soLuong; ++i) {
        if (ds[i]) ds[i]->Xuat();
    }
}

void QuanLyLoaiHang::DocCSV(const string& file) {
    ifstream ifs(file);
    if (!ifs.is_open()) return;
    string line;
    while (getline(ifs, line)) {
        if (line.size() == 0) continue;
        LoaiHang* p = new LoaiHang();
        p->FromCSV(line);
        if (soLuong >= 200) {
            cout << "Vuot qua gioi han 200 loai hang!\n";
            delete p;
            return;
        }
        ds[soLuong++] = p;
    }
    ifs.close();
}

void QuanLyLoaiHang::GhiCSV(const string& file) {
    ofstream ofs(file);
    for (int i = 0; i < soLuong; ++i) {
        if (ds[i]) ofs << ds[i]->ToCSV() << "\n";
    }
    ofs.close();
}
