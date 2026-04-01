#include "Gargantua.h"
#include <sstream> 
#include <iostream>

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

    trim();

}
void Gargantua::trim() {
    for (int i = internal.size()-1; i >= 0; i--) {
        if (internal[i] == 0) {
            internal.pop_back();
        } else {
            break;
        }
    }

    if (internal.empty()) {
        internal.push_back(0);
    }

    if (internal.empty() || (internal.size() == 1 && internal[0] == 0)) is_negative = false;
}
Gargantua::Gargantua(std::vector<int> intern, bool is_neg) {
    internal = intern;
    is_negative = is_neg;
    trim();
}

std::string Gargantua::str() const {
    if (internal.empty()) return "0";

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

Gargantua Gargantua::operator+(const Gargantua& other) const {
    return arithmetic(other, is_negative, other.is_negative);
}

Gargantua Gargantua::operator-(const Gargantua& other) const {
    return arithmetic(other, is_negative, !other.is_negative);
}

Gargantua Gargantua::arithmetic(const Gargantua& other, bool is_neg, bool other_is_neg) const {
    if (is_neg == other_is_neg) {
        long long carry = 0;

        std::vector<int> result;
        bool ans_neg = is_negative;

        int digits = std::max(internal.size(), other.internal.size());
        for (int i = 0; i < digits; i++) {
            long long A = 0;
            long long B = 0;

            if (i < internal.size()) A = internal[i];
            if (i < other.internal.size()) B = other.internal[i];
            long long tot = A + B + carry;
            result.push_back(tot % MAX_SIZE);
            carry = tot / MAX_SIZE;
        }

        if (carry > 0) result.push_back(carry);

        return Gargantua(result, ans_neg);

    }
    else {

        std::vector<int> result;
        long long borrow = 0;

        bool res_neg = false;

        const Gargantua* bigger;
        const Gargantua* smaller;

        int cmp = compare_magnitude(other);
        if (cmp == 1) {
            bigger = this;
            smaller = &other;
            res_neg = is_neg;
        }
        else if (cmp == -1) {
            bigger = &other;
            smaller = this;
            res_neg = other_is_neg;
        }
        else {
            return Gargantua("0");
        }

  //      std::cout << "bigger is " << bigger->str() << std::endl;



        int digits = bigger->internal.size();
        for (int i = 0; i < digits; i++) {
            long long A = 0;
            long long B = 0;
            if (i < bigger->internal.size())  A = bigger->internal[i];
            if (i < smaller->internal.size()) B = smaller->internal[i];

            long long diff = A - B - borrow;

            if (diff < 0) {
                diff += MAX_SIZE;
                borrow = 1;
            } else {
                borrow = 0;
            }

            result.push_back(diff);
        }
 
        return Gargantua(result, res_neg);
    }
}


Gargantua Gargantua::operator*(const Gargantua& other) const {
    std::cout << " HERE ";
    Gargantua a = karatsube(*this, other);
    if (is_negative != other.is_negative) a.is_negative = true;
    else a.is_negative = false;
    return a;

}

Gargantua Gargantua::karatsube(const Gargantua& first, const Gargantua& second) const {


   std::cout << "multiplying " << first.str() << " and " << second.str() << std::endl;

  //  std::cout << second.internal.size() << " "; //segfault here?

    if (first.internal.size() <= 1 && second.internal.size() <= 1) {
        if (first.internal.size()==0 || second.internal.size()==0) return Gargantua("0");
        Gargantua ans(std::to_string((long long)first.internal[0] * second.internal[0]));
        return ans;
    }
    int m = std::max(first.internal.size(), second.internal.size()) / 2;
    std::cout << m;

    Gargantua x_low = Gargantua(std::vector<int>(first.internal.begin(), first.internal.begin() + std::min((int)first.internal.size(), m)), false);

    Gargantua x_high = Gargantua(std::vector<int>(first.internal.begin() + std::min((int)first.internal.size(), m), first.internal.end()), false);
    

    Gargantua y_low = Gargantua(std::vector<int>(second.internal.begin(), second.internal.begin() + std::min((int)second.internal.size(), m)), false);

    Gargantua y_high = Gargantua(std::vector<int>(second.internal.begin() + std::min((int)second.internal.size(), m), second.internal.end()), false);


    Gargantua z2 = karatsube(x_high, y_high);
    Gargantua z0 = karatsube(x_low, y_low);
    Gargantua z1 = karatsube((x_high+x_low), (y_high+y_low)) - z2 - z0;

    z1.trim();
    z2.trim();
    z0.trim();

    z2.internal.insert(z2.internal.begin(), 2*m, 0);
    z1.internal.insert(z1.internal.begin(), m, 0);

    return z2 + z1 + z0;
}