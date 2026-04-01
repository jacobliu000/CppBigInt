#pragma once

#include <vector>
#include <string>

class Gargantua {
    public:
    

        Gargantua(std::string s);
        Gargantua(std::vector<int> intern, bool is_neg);

        std::string str() const;

        bool operator==(const Gargantua& other) const;
        bool operator>(const Gargantua& other) const;
        bool operator>=(const Gargantua& other) const;
        bool operator<(const Gargantua& other) const;
        bool operator<=(const Gargantua& other) const;


        Gargantua operator+(const Gargantua& other) const;
        Gargantua operator-(const Gargantua& other) const;
        Gargantua operator*(const Gargantua& other) const;


    private:

        long long MAX_SIZE = 1000000000;

        Gargantua karatsube(const Gargantua& first, const Gargantua& second) const;
        Gargantua arithmetic(const Gargantua &other, bool is_neg, bool other_is_neg) const;
        int compare_magnitude(const Gargantua& other) const;
        bool is_negative = false;
        std::vector<int> internal;

        void trim();
};