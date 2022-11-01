#include "frac.hpp"

std::ostream & operator<<(std::ostream &os, const frac &that) {
    os << that.a << '/' << that.b;
    return os;
}

frac::frac(const int64_t &x, const uint64_t &y) {
    a = x / gcd(abs(x), y);
    b = y / gcd(abs(x), y);
}

const uint64_t frac::abs(const int64_t &x)const {
    return x < 0 ? -x : x;
}

const uint64_t frac::gcd(const uint64_t &x, const uint64_t &y)const {
    return y == 0 ? x : gcd(y, x % y);
}

const frac frac::operator+(const frac &that)const {
    return frac(a * that.b + b * that.a, b * that.b);
}

const frac frac::operator-()const {
    return frac(-a, b);
}

const frac frac::operator-(const frac &that)const {
    return *this + (-that);
}

const frac frac::operator*(const frac &that)const {
    return frac(a * that.a, b * that.b);
}

const frac frac::inv()const {
    return a < 0 ? frac(-b, -a) : frac(b, a);
}

const frac frac::operator/(const frac &that)const {
    return *this * that.inv();
}

