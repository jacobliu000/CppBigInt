#include "Gargantua.h"
#include <iostream>

using namespace std;

int main() {
    Gargantua a("7910552");
    Gargantua b("07910552");
    Gargantua c("7910552");
    Gargantua d("7910000552");

    Gargantua e("-0000000000000000000000000009");
    Gargantua f("9");
    cout << e.str() << endl;
    cout << f.str() << endl;
    cout << (e == f) << endl;
}