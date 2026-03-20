#include "Gargantua.h"
#include <iostream>

using namespace std;

int main() {
    Gargantua a("7910552");
    Gargantua b("07910552");
    Gargantua c("7910552");
    Gargantua d("7910000552");

    cout << a == c << endl; //true
    cout << a == b << endl; //true
    cout << c == d << endl; //false
}