#include "Module.h"
#include <iostream>
#include <regex>
#include <algorithm>

string ToLower(const string &s) {
    string res = s;
    transform(res.begin(), res.end(), res.begin(), ::tolower);
    return res;
}

bool IsValidDate(const string& date) {
    regex re_date(R"(^\d{2}-\d{2}-\d{4}$)");

    if (!regex_match(date, re_date))
        return false;

    int d = stoi(date.substr(0, 2));
    int m = stoi(date.substr(3, 2));
    int y = stoi(date.substr(6, 4));

    if (m < 1 || m > 12) return false;

    int daysInMonth;
    switch (m) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            daysInMonth = 31; break;
        case 4: case 6: case 9: case 11:
            daysInMonth = 30; break;
        case 2:
            if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
                daysInMonth = 29;
            else
                daysInMonth = 28;
            break;
        default:
            return false;
    }

    return (d >= 1 && d <= daysInMonth);
}

string InputValidDate(const string& prompt) {
    string date;

    while (true) {
        cout << prompt;
        cin >> date;
        cin.ignore();

        if (!IsValidDate(date)) {
            cout << "Ngay khong hop le! Vui long nhap lai (DD-MM-YYYY).\n";
            continue;
        }

        return date; // Hợp lệ
    }
}
