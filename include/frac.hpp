#include <iostream>

class frac {
private:
    int64_t a;
    uint64_t b;
public:
    frac(const int64_t & = 1, const uint64_t & = 1);
    friend std::ostream & operator<<(std::ostream &os, const frac &that);
    const uint64_t abs(const int64_t &)const;
    const uint64_t gcd(const uint64_t &, const uint64_t &)const;
    const frac operator+(const frac &)const;
    const frac operator-()const;
    const frac operator-(const frac &)const;
    const frac operator*(const frac &)const;
    const frac inv()const;
    const frac operator/(const frac &)const;
};
