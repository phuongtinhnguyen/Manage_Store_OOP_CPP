#include "QuanLyMatHang.h"
#include <fstream>
#include <sstream>
#include <ctime>
#include "Module.h"

QuanLyMatHang::QuanLyMatHang() {
    soLuong = 0;
    for (int i = 0; i < 500; ++i) ds[i] = nullptr;
}

QuanLyMatHang::~QuanLyMatHang() {
    for (int i = 0; i < soLuong; ++i) if (ds[i]) delete ds[i];
}

void QuanLyMatHang::MenuMatHang() {
    int chon;
    do {
        cout << "\n=== QUAN LY MAT HANG ===\n";
        cout << "1. Them mat hang\n";
        cout << "2. Xoa mat hang\n";
        cout << "3. Sua mat hang\n";
        cout << "4. Tim kiem mat hang\n";
        cout << "5. Hien thi danh sach\n";
        cout << "0. Quay lai\n";
        cout << "Chon: ";
        cin >> chon;
        cin.ignore();

        switch (chon) {
        case 1: this->Them(); break;
        case 2: this->Xoa(); break;
        case 3: this->Sua(); break;
        case 4: this->TimKiem(); break;
        case 5: this->HienThi(); break;
        }
    } while (chon != 0);
}

void QuanLyMatHang::Them() {
    if (soLuong >= 500) { 
        cout << "Danh sach day.\n"; return;
    }

    string ma;
    cout << "Nhap ma hang: ";
    cin >> ma;
    cin.ignore();

    for (int i = 0; i < soLuong; ++i) {
        if (ds[i] && ds[i]->GetMaHang() == ma) {
            cout << "Ma hang da ton tai!\n";
            return;
        }
    }

    MatHang* p = new MatHang();
    p->SetMaHang(ma);
    p->Nhap(false);
    ds[soLuong++] = p;
}

int findMHIndex(MatHang* arr[], int n, const string& ma) {
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] && arr[i]->GetMaHang() == ma)
            return i;
    }
    return -1;
}

void QuanLyMatHang::Xoa() {
    cout << "Nhap ma hang can xoa: ";
    string ma;
    cin >> ma;
    cin.ignore();
    int idx = findMHIndex(ds, soLuong, ma);
    if (idx == -1) { cout << "Khong tim thay.\n"; return; }
    delete ds[idx];
    for (int i = idx; i < soLuong - 1; ++i) ds[i] = ds[i+1];
    ds[--soLuong] = nullptr;
    cout << "Da xoa.\n";
}

void QuanLyMatHang::Sua() {
    cout << "Nhap ma hang can sua: ";
    string ma;
    cin >> ma;
    cin.ignore();
    int idx = findMHIndex(ds, soLuong, ma);
    if (idx == -1)
    { 
        cout << "Khong tim thay.\n";
        return;
    }
    cout << "Nhap thong tin moi:\n";
    ds[idx]->Nhap(false);
    cout << "Da cap nhat.\n";
}

void QuanLyMatHang::TimKiem() {
    cout << "Nhap ma hoac ten can tim: ";
    string key; 
    cin.ignore(); 
    getline(cin, key);
    key = ToLower(key);

    bool ok = false;
    for (int i = 0; i < soLuong; ++i) {
        if (ds[i]) {
            string csv = ToLower(ds[i]->ToCSV());
            if (csv.find(key) != string::npos) {
                ds[i]->Xuat(); 
                ok = true;
            }
        }
    }
    if (!ok) cout << "Khong co ket qua.\n";
}

void QuanLyMatHang::HienThi() {
    cout << "Danh sach mat hang:\n";
    for (int i = 0; i < soLuong; ++i) if (ds[i]) ds[i]->Xuat();
}

MatHang* QuanLyMatHang::TimTheoMa(const string& ma) {
    for (int i = 0; i < soLuong; ++i)
        if (ds[i] && ds[i]->GetMaHang() == ma)
            return ds[i];
    return nullptr;
}

void QuanLyMatHang::ThemMatHangMoi(MatHang* p) {
    if (soLuong < 500)
        ds[soLuong++] = p;
}

void QuanLyMatHang::ThongKeTonKho() {
    cout << "Thong ke ton kho:\n";
    for (int i = 0; i < soLuong; ++i) if (ds[i]) {
        cout << ds[i]->GetMaHang() << " - So luong: " << ds[i]->GetSoLuong() << endl;
    }
}

static bool isExpired(const string& hanDung) {
    // DD-MM-YYYY
    int y=0,m=0,d=0;
    if (sscanf(hanDung.c_str(), "%d-%d-%d", &d, &m, &y) != 3)
    {
        return false;
    }
    time_t t = time(NULL);
    struct tm *now = localtime(&t);
    int cy = now->tm_year + 1900;
    int cm = now->tm_mon + 1;
    int cd = now->tm_mday;
    if (y < cy) return true;
    if (y == cy) {
        if (m < cm) return true;
        if (m == cm && d < cd) return true;
    }
    return false;
}

void QuanLyMatHang::ThongKeHetHan() {
    cout << "Danh sach mat hang het han:\n";
    for (int i = 0; i < soLuong; ++i) if (ds[i]) {
        if (isExpired(ds[i]->GetHanDung())) ds[i]->Xuat();
    }
}

void QuanLyMatHang::DocCSV(const string& file) {
    ifstream ifs(file);
    if (!ifs.is_open()) return;
    string line;
    while (getline(ifs, line)) {
        if (line.size() == 0) continue;
        MatHang* p = new MatHang();
        p->FromCSV(line);
        if (soLuong >= 500) {
            cout << "Vuot qua gioi han 500 mat hang!\n";
            delete p;
            return;
        }
        ds[soLuong++] = p;
    }
    ifs.close();
}

void QuanLyMatHang::GhiCSV(const string& file) {
    ofstream ofs(file);
    for (int i = 0; i < soLuong; ++i) if (ds[i]) ofs << ds[i]->ToCSV() << "\n";
    ofs.close();
}
