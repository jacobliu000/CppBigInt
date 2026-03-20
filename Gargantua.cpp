#include "Gargantua.h"
#include <sstream> 


Gargantua::Gargantua(std::string s) {
    is_negative = false;
    
    if (s[0] == '-') {
        s.erase(0, 1);
        is_negative = true;
    }
    for (int i = s.length(); i > 0; i -= 9) {
        if (i < 9) {
            internal.push_back(std::stoi(s.substr(0, i)));
        }
        else {
            internal.push_back(std::stoi(s.substr(i-9, 9)));
        }
    }

    for (int i = internal.size()-1; i >= 0; i--) {
        if (internal[i] == 0) {
            internal.pop_back();
        } else {
            break;
        }
    }
}




std::string Gargantua::str() {
    std::stringstream ss;

    if (is_negative) ss << '-';
    ss << std::to_string(internal[internal.size()-1]);
    for (int i = internal.size() - 2; i >= 0; i--) {
        std::string section = std::to_string(internal[i]);
        int size = section.length();

        std::string filler(9 - size, '0');
        ss << filler << section;
    }

    return ss.str();
}

bool Gargantua::operator==(const Gargantua& other) const {
    return is_negative == other.is_negative
        && internal == other.internal;
}