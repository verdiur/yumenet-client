#pragma once
#include <string>

/// @brief convert string to bool
inline bool stob(std::string const &s) {
    if (s == "0" || s == "false") {
        return false;
    } else {
        return true;
    }
}