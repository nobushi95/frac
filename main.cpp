#define MY_DEBUG
#include "frac.hpp"

int main() {
    Frac a(1, 2);
    Frac b(1, 3);
    Frac c = a + b;
    Frac d = a * b;
    Frac e = d * 15;
    Frac f = e.reduce();
    Frac g = f * 2;
    Frac h = g.reduce();

    cout << "a = " << a.str() << endl;
    cout << "b = " << b.str() << endl;
    cout << "c = " << c.str() << endl;
    cout << "d = " << d.str() << endl;
    cout << "e = " << e.str() << endl;
    cout << "f = " << f.str() << endl;
    cout << "g = " << g.str() << endl;
    cout << "h = " << h.str() << endl;
}