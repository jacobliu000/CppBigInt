#include "Gargantua.h"
#include <iostream>

using namespace std;

int main() {
    Gargantua a("51034850234859402393546795402092409401908205");
    Gargantua b("850234859402393546795402092409401908205");
    Gargantua c("100");
    Gargantua d("00000000000000100");

    Gargantua e("-9999999999");
    Gargantua f("-1");

    Gargantua g("0");

    cout << (a + b).str() << endl;
    cout << (a-b).str() << endl;
    cout << (b-a).str() << endl;
    /*
    cout << (a > a) << endl; //false
    cout << (a <= a) << endl; //true
    cout << (a < a) << endl; //false
    cout << (a >= a) << endl; //true

    
    cout << (a > b) << endl; //true
    cout << (a <= b) << endl; //false
    cout << (a < b) << endl; //false
    cout << (a >= b) << endl; //true

    cout << (c == d) << endl;
    cout << (c > d) << endl;
    cout << (c < d) << endl;
    cout << (c >= d) << endl;
    cout << (c <= d) << endl;

    cout << (f > e) << endl;

    cout << (f < e) << endl;



    cout << (a > g) << endl;
    cout << ( a < g) << endl;

    cout << (a == g) << endl;
    cout << (a <= g) << endl;
    cout << (a >= g) << endl;
    */

}