#include "QuanLyMatHang.h"
#include <fstream>
#include <sstream>
#include <ctime>

QuanLyMatHang::QuanLyMatHang() {
    soLuong = 0;
    for (int i = 0; i < 500; ++i) ds[i] = nullptr;
}

QuanLyMatHang::~QuanLyMatHang() {
    for (int i = 0; i < soLuong; ++i) if (ds[i]) delete ds[i];
}

void QuanLyMatHang::Them() {
    if (soLuong >= 500) { cout << "Danh sach day.\n"; return; }
    MatHang* p = new MatHang();
    p->Nhap();
    ds[soLuong++] = p;
}

int findMHIndex(MatHang* arr[], int n, const string& ma) {
    for (int i = 0; i < n; ++i) if (arr[i] && arr[i]->GetMaHang() == ma) return i;
    return -1;
}

void QuanLyMatHang::Xoa() {
    cout << "Nhap ma hang can xoa: ";
    string ma; cin >> ma;
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
    int idx = findMHIndex(ds, soLuong, ma);
    if (idx == -1) { cout << "Khong tim thay.\n"; return; }
    cout << "Nhap thong tin moi:\n";
    ds[idx]->Nhap();
    cout << "Da cap nhat.\n";
}

void QuanLyMatHang::TimKiem() {
    cout << "Nhap ma hoac ten can tim: ";
    string key; cin.ignore(); getline(cin, key);
    bool ok = false;
    for (int i = 0; i < soLuong; ++i) {
        if (ds[i]) {
            string csv = ds[i]->ToCSV();
            if (csv.find(key) != string::npos) {
                ds[i]->Xuat(); ok = true;
            }
        }
    }
    if (!ok) cout << "Khong co ket qua.\n";
}

void QuanLyMatHang::HienThi() {
    cout << "Danh sach mat hang:\n";
    for (int i = 0; i < soLuong; ++i) if (ds[i]) ds[i]->Xuat();
}

void QuanLyMatHang::CapNhatNhapKho(string maHang, int sl) {
    int idx = findMHIndex(ds, soLuong, maHang);
    if (idx == -1) {
        cout << "Khong tim thay mat hang de cap nhat.\n";
        return;
    }
    int cur = ds[idx]->GetSoLuong();
    ds[idx]->SetSoLuong(cur + sl);
}

void QuanLyMatHang::CapNhatBanHang(string maHang, int sl) {
    int idx = findMHIndex(ds, soLuong, maHang);
    if (idx == -1) {
        cout << "Khong tim thay mat hang de cap nhat.\n";
        return;
    }
    int cur = ds[idx]->GetSoLuong();
    ds[idx]->SetSoLuong(cur - sl);
}

void QuanLyMatHang::ThongKeTonKho() {
    cout << "Thong ke ton kho:\n";
    for (int i = 0; i < soLuong; ++i) if (ds[i]) {
        cout << ds[i]->GetMaHang() << " - So luong: " << ds[i]->GetSoLuong() << endl;
    }
}

static bool isExpired(const string& hanDung) {
    // expect YYYY-MM-DD
    int y=0,m=0,d=0;
    if (sscanf(hanDung.c_str(), "%d-%d-%d", &y, &m, &d) != 3) return false;
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
        ds[soLuong++] = p;
    }
    ifs.close();
}

void QuanLyMatHang::GhiCSV(const string& file) {
    ofstream ofs(file);
    for (int i = 0; i < soLuong; ++i) if (ds[i]) ofs << ds[i]->ToCSV() << "\n";
    ofs.close();
}
