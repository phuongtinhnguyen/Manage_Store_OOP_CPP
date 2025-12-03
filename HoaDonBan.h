#pragma once
#include "HoaDon.h"

class HoaDonBan : public HoaDon {
public:
    HoaDonBan();
    ~HoaDonBan();

    string ToCSV() override;
    void FromCSV(const string& line) override;
};
