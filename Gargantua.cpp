#include "Gargantua.h"
#include <sstream> 
Gargantua::Gargantua(std::string s) {
    for (int i = s.length(); i > 0; i -= 9) {
        if (i < 9) {
            internal.push_back(std::stoi(s.substr(0, i)));
        }
        else {
            internal.push_back(std::stoi(s.substr(i-9, 9)));
        }
    }
}

std::string Gargantua::str() {
    std::stringstream ss;

    ss << std::to_string(internal[internal.size()-1]);
    for (int i = internal.size() - 2; i >= 0; i--) {
        std::string section = std::to_string(internal[i]);
        int size = section.length();

        std::string filler(9 - size, '0');
        ss << filler << section;
    }

    return ss.str();
}