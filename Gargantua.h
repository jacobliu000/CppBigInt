#pragma once

#include <vector>
#include <string>

class Gargantua {
    public:
        Gargantua(std::string s);

        std::string str();

        Gargantua operator+(const Gargantua& other);

    private:
        std::vector<long long> internal;
};