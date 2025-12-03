#pragma once
#include "HoaDon.h"

class HoaDonNhap : public HoaDon {
public:
    HoaDonNhap();
    ~HoaDonNhap();

    string ToCSV() override;
    void FromCSV(const string& line) override;
};
