#pragma once
#include <iostream>

template <typename T, bool Reduce = false> class Rational {
    T num, den;

    static T my_gcd(T x_, T y_) {
        unsigned long long x = x_ < 0 ? -x_ : x_, y = y_ < 0 ? -y_ : y_;
        if (!x or !y) return x + y;
        int n = __builtin_ctzll(x), m = __builtin_ctzll(y);
        x >>= n, y >>= m;
        while (x != y) {
            if (x > y)
                x = (x - y) >> __builtin_ctzll(x - y);
            else
                y = (y - x) >> __builtin_ctzll(y - x);
        }
        return x << (n > m ? m : n);
    }

    void normalize() {
        if (den < 0) num = -num, den = -den;
        if (den == 0) num = (num > 0 ? 1 : num < 0 ? -1 : 0);
        if constexpr (Reduce) {
            T g = my_gcd(num, den);
            if (g > 0) num /= g, den /= g;
        }
    }

  public:
    Rational() {}
    Rational(T num) : num(num), den(T(1)) {}
    Rational(T num, T den) : num(num), den(den) { normalize(); }

    Rational operator+(const Rational& r) const { return Rational(num * r.den + den * r.num, den * r.den); }
    Rational operator-(const Rational& r) const { return Rational(num * r.den - den * r.num, den * r.den); }
    Rational operator*(const Rational& r) const { return Rational(num * r.num, den * r.den); }
    Rational operator/(const Rational& r) const { return Rational(num * r.den, den * r.num); }
    Rational& operator+=(const Rational& r) { return *this = *this + r; }
    Rational& operator-=(const Rational& r) { return *this = *this - r; }
    Rational& operator*=(const Rational& r) { return *this = *this * r; }
    Rational& operator/=(const Rational& r) { return *this = *this / r; }

    Rational operator+(const T& val) const { return *this + Rational(val); }
    Rational operator-(const T& val) const { return *this - Rational(val); }
    Rational operator*(const T& val) const { return *this * Rational(val); }
    Rational operator/(const T& val) const { return *this / Rational(val); }
    Rational& operator+=(const T& val) { return *this = *this + val; }
    Rational& operator-=(const T& val) { return *this = *this - val; }
    Rational& operator*=(const T& val) { return *this = *this * val; }
    Rational& operator/=(const T& val) { return *this = *this / val; }
    friend Rational operator+(const T& val, const Rational& r) { return r + val; }
    friend Rational operator-(const T& val, const Rational& r) { return r - val; }
    friend Rational operator*(const T& val, const Rational& r) { return r * val; }
    friend Rational operator/(const T& val, const Rational& r) { return r / val; }

    Rational operator-() const { return Rational(-num, den); }
    Rational abs() const { return Rational(num < 0 ? -num : num, den); }

    bool operator==(const Rational& r) const {
        if (den == 0 and r.den == 0) return num == r.num;
        if (den == 0 or r.den == 0) return false;
        return num * r.den == den * r.num;
    }
    bool operator!=(const Rational& r) const { return !(*this == r); }
    bool operator<(const Rational& r) const {
        if (den == 0 and r.den == 0) return num < r.num;
        if (den == 0) return num < 0;
        if (r.den == 0) return r.num > 0;
        return num * r.den < den * r.num;
    }
    bool operator<=(const Rational& r) const { return (*this == r) or (*this < r); }
    bool operator>(const Rational& r) const { return r < *this; }
    bool operator>=(const Rational& r) const { return (*this == r) or (*this > r); }

    bool operator==(const T& val) const { return *this == Rational(val); }
    bool operator!=(const T& val) const { return *this != Rational(val); }
    bool operator<(const T& val) const { return *this < Rational(val); }
    bool operator<=(const T& val) const { return *this <= Rational(val); }
    bool operator>(const T& val) const { return *this > Rational(val); }
    bool operator>=(const T& val) const { return *this >= Rational(val); }
    friend bool operator==(const T& val, const Rational& r) { return r == val; }
    friend bool operator!=(const T& val, const Rational& r) { return r != val; }
    friend bool operator<(const T& val, const Rational& r) { return r > val; }
    friend bool operator<=(const T& val, const Rational& r) { return r >= val; }
    friend bool operator>(const T& val, const Rational& r) { return r < val; }
    friend bool operator>=(const T& val, const Rational& r) { return r <= val; }

    explicit operator double() const { return (double)num / (double)den; }
    explicit operator long double() const { return (long double)num / (long double)den; }
    friend std::ostream& operator<<(std::ostream& os, const Rational& r) { return os << r.num << '/' << r.den; }
};
