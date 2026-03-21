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

    if (internal.empty() || (internal.size() == 0 && internal[0] == 0)) is_negative = false;
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

//1: |a| > |b|, 0: |a| == |b|, -1 |a| < |b|
int Gargantua::compare_magnitude(const Gargantua& other) const {
        if (other.internal.size() > internal.size()) return -1;
        if (internal.size() > other.internal.size()) return 1;

        if (other.internal.size() == internal.size()) {
            for (int i = internal.size()-1; i>=0; i--) {
                if (internal[i] > other.internal[i]) {
                    return 1;
                }
                if (other.internal[i] > internal[i]) {
                    return -1;
                }
            }
        }

        return 0;
}

bool Gargantua::operator>(const Gargantua& other) const {
    if (is_negative && !other.is_negative) return false;
    if (!is_negative && other.is_negative) return true;

    int cmp = compare_magnitude(other);

    if (is_negative) {
        return cmp == -1;
    }
    else {
        return cmp == 1;
    }
    
}

bool Gargantua::operator<(const Gargantua& other) const {
    if (is_negative && !other.is_negative) return true;
    if (!is_negative && other.is_negative) return false;

    int cmp = compare_magnitude(other);

    if (is_negative) {
        return cmp == 1;
    }
    else {
        return cmp == -1;
    }
    
}

bool Gargantua::operator>=(const Gargantua& other) const {
    if (is_negative && !other.is_negative) return false;
    if (!is_negative && other.is_negative) return true;

    int cmp = compare_magnitude(other);

    if (cmp == 0) return true;

    if (is_negative) {
        return cmp == -1;
    }
    else {
        return cmp == 1;
    }    
}

bool Gargantua::operator<=(const Gargantua& other) const {
    if (is_negative && !other.is_negative) return true;
    if (!is_negative && other.is_negative) return false;

    int cmp = compare_magnitude(other);

    if (cmp == 0) return true;

    if (is_negative) {
        return cmp == 1;
    }
    else {
        return cmp == -1;
    }    
}