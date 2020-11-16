

class Frac {
private:
    int _n; // Numerator 分子
    int _d; // Denominator 分母

public:
    Frac(int n, int d) : _n(n), _d(d) {}
    Frac(int n) : _n(n), _d(1) {}

public:
    int numerator() const { return _n; }
    int denominator() const { return _d; }
};