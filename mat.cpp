#include "mat.hpp"

std::ostream & operator<<(std::ostream &os, const frac &that) {
    os << that.m << '/' << that.n;
    return os;
}

frac::frac(const int64_t &a) {
    m = a;
    n = 1;
}

frac::frac(const int64_t &a, const uint64_t &b) {
    m = a / gcd(abs(a), b);
    n = b / gcd(abs(a), b);
}

const uint64_t frac::abs(const int64_t &a)const {
    return a < 0 ? -a : a;
}

const uint64_t frac::gcd(const uint64_t &a, const uint64_t &b)const {
    return b == 0 ? a : gcd(b, a % b);
}

const frac frac::operator+(const frac &that)const {
    return frac(m * that.n + n * that.m, n * that.n);
}

const frac frac::operator-()const {
    return frac(-m, n);
}

const frac frac::operator-(const frac &that)const {
    return *this + (-that);
}

const frac frac::operator*(const frac &that)const {
    return frac(m * that.m, n * that.n);
}

const frac frac::inv()const {
    return frac(m < 0 ? -n : n, abs(m));
}

const frac frac::operator/(const frac &that)const {
    return *this * that.inv();
}
