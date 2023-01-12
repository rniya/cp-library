#pragma once
#include <algorithm>
#include <array>

namespace Nimber64 {

struct nim {
    const static std::array<std::array<unsigned char, 256>, 256> small;
    const static std::array<std::array<std::array<nim, 256>, 8>, 8> precalc;
    unsigned long long v;

    nim() : v(0) {}

    nim(unsigned long long _v) : v(_v) {}

    nim& operator+=(const nim& rhs) {
        v ^= rhs.v;
        return *this;
    }

    nim& operator-=(const nim& rhs) {
        v ^= rhs.v;
        return *this;
    }

    nim& operator*=(const nim& rhs) {
        nim res;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                res += precalc[i][j][small[(v >> (8 * i)) & 255][(rhs.v >> (8 * j)) & 255]];
            }
        }
        return *this = res;
    }

    const nim operator+(const nim& rhs) const { return nim(*this) += rhs; }

    const nim operator-(const nim& rhs) const { return nim(*this) -= rhs; }

    const nim operator*(const nim& rhs) const { return nim(*this) *= rhs; }
};

nim mul_naive(nim l, nim r) {
    unsigned long long a = l.v, b = r.v;
    if (a < b) std::swap(a, b);
    if (b == 0) return 0;
    if (b == 1) return a;
    int p = 32;
    while (std::max(a, b) < (1ULL << p)) p >>= 1;
    unsigned long long power = 1ULL << p;
    if (a >= power and b >= power) {
        nim res;
        res += mul_naive(a % power, b % power);
        res += mul_naive(a / power, b % power).v * power;
        res += mul_naive(a % power, b / power).v * power;
        auto x = mul_naive(a / power, b / power);
        res += x.v * power;
        res += mul_naive(x, power / 2);
        return res;
    } else
        return nim(mul_naive(a / power, b).v * power) + mul_naive(a % power, b);
}

const std::array<std::array<unsigned char, 256>, 256> nim::small = []() {
    std::array<std::array<unsigned char, 256>, 256> small;
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            small[i][j] = (unsigned char)(mul_naive(i, j).v);
        }
    }
    return small;
}();

const std::array<std::array<std::array<nim, 256>, 8>, 8> nim::precalc = []() {
    std::array<std::array<std::array<nim, 256>, 8>, 8> precalc;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            nim tmp = mul_naive(1ULL << (8 * i), 1ULL << (8 * j));
            for (int k = 0; k < 256; k++) precalc[i][j][k] = mul_naive(tmp, k);
        }
    }
    return precalc;
}();

}  // namespace Nimber64
