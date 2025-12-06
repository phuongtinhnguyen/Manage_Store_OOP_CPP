#include "Module.h"
#include <algorithm>

std::string ToLower(const std::string &s) {
    std::string res = s;
    std::transform(res.begin(), res.end(), res.begin(), ::tolower);
    return res;
}
