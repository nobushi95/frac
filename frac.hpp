#include <iostream>

using namespace std;

class Frac {
private:
    int _n; // Numerator 分子
    int _d; // Denominator 分母

private:
    int lcm(int a, int b) const {
        int na = 1, nb = 1;
        while (a * na != b * nb) {
            if (a * na < b * nb) {
                na++;
            } else {
                nb++;
            }
        }
        return a * na;
    }

    int gcm(int a, int b) const {
        int i = a < b ? a : b;
        for (; i > 1; --i) {
            if (a % i == 0 && b % i == 0) {
                break;
            }
        }
        return i;
    }

public:
    Frac(int n, int d) : _n(n), _d(d) {
        #ifdef MY_DEBUG
        cout << "constructor : " << _n << " / " << _d << endl;
        #endif
    }
    Frac(int n) : _n(n), _d(1) {
        #ifdef MY_DEBUG
        cout << "constructor : " << _n << " / " << _d << endl;
        #endif
    }
    Frac(const Frac &f) {
        #ifdef MY_DEBUG
        cout << "copy constructor : " << f._n << " / " << f._d << endl;
        #endif
        *this = f;
    }

    Frac &operator=(const Frac &f) {
        _n = f._n;
        _d = f._d;
        return *this;
    }

    Frac &operator+=(const Frac &f) {
        Frac tmp = *this;
        _d = lcm(tmp._d, f._d);
        _n = tmp._n * _d / tmp._d + f._n * _d / f._d;
        return *this;
    }

    Frac &operator*=(const Frac &f) {
        _d *= f._d;
        _n *= f._n;
        return *this;
    }

    Frac reduce(const Frac &f) const {
        Frac ret = *this;
        int g = gcm(_n, _d);
        ret._n /= g;
        ret._d /= g;
        return ret;
    }

public:
    int numerator() const { return _n; }
    int denominator() const { return _d; }
    double toDouble() const { return _n / _d; }
};

Frac operator+(const Frac &f1, const Frac &f2) {
    Frac ret = f1;
    ret += f2;
    return ret;
}

Frac operator*(const Frac &f1, const Frac &f2) {
    Frac ret = f1;
    ret *= f2;
    return ret;
}