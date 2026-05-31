#include "Gargantua.h"
#include <iostream>
#include <vector>

using namespace std;
Gargantua factorial(string n) {
    
    if (n == "1") {
        return Gargantua("1");
    }
    else {
        Gargantua cur(n);
        Gargantua one("1");
        return cur * factorial((cur - one).str());
    }
}
void test() {
    vector<string> first = {"1", "-1", "-50", "0", "-0", "0"};
    vector<string> second = {"800858008580085", "800858008580085", "-50", "0", "0", "-0"};
    vector<string> ans = {"800858008580085", "-800858008580085", "2500", "0", "0", "0"};


    int success = 0;
    int total = 0;
    for (int i = 0; i < first.size(); i++) {
        Gargantua a(first[i]);
        Gargantua b(second[i]);
        Gargantua result = a * b;

        if (result.str() != ans[i]) {
            cout << "Issue with test case " << i << endl;
        }
        else {
            success += 1;
        }
        total += 1;
    }

    cout << " conducted " << total << " tests with " << success << " correct ";
}

int main() {
    cout << factorial("100").str();
}
