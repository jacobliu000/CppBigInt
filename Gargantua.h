#pragma once

#include <vector>
#include <string>

class Gargantua {
    public:
        Gargantua(std::string s);

        std::string str();

        bool operator==(const Gargantua& other) const;
        bool operator>(const Gargantua& other) const;
        bool operator>=(const Gargantua& other) const;
        bool operator<(const Gargantua& other) const;
        bool operator<=(const Gargantua& other) const;


        Gargantua operator+(const Gargantua& other);

    private:

        int compare_magnitude(const Gargantua& other) const;
        bool is_negative = false;
        std::vector<long long> internal;
};