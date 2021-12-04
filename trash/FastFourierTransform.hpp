#pragma once
#include "../base.hpp"

/**
 * @brief Fast Fourier Transform
 * @docs docs/convolution/FastFourierTransform.md
 */
namespace FastFourierTransform {
struct Complex {
    double x, y;
    Complex() : x(0), y(0) {}
    Complex(double x, double y) : x(x), y(y) {}
    inline Complex operator+(const Complex& c) const { return Complex(x + c.x, y + c.y); }
    inline Complex operator-(const Complex& c) const { return Complex(x - c.x, y - c.y); }
    inline Complex operator*(const Complex& c) const { return Complex(x * c.x - y * c.y, x * c.y + y * c.x); }
    inline Complex conj() const { return Complex(x, -y); }
};
const double PI = acosl(-1);
vector<Complex> roots = {{0, 0}, {1, 0}};
vector<int> rev = {0, 1};
int base = 1;
void ensure_base(int nbase) {
    if (nbase <= base) return;
    rev.resize(1 << nbase);
    for (int i = 0; i < (1 << nbase); i++) {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (nbase - 1));
    }
    roots.resize(1 << nbase);
    for (; base < nbase; base++) {
        double angle = PI * 2.0 / (1 << (base + 1));
        for (int i = 1 << (base - 1); i < (1 << base); i++) {
            roots[i << 1] = roots[i];
            double angle_i = angle * ((i << 1 | 1) - (1 << base));
            roots[i << 1 | 1] = Complex(cos(angle_i), sin(angle_i));
        }
    }
}
void fft(vector<Complex>& a, int n) {
    int zeros = __builtin_ctz(n);
    ensure_base(zeros);
    int shift = base - zeros;
    for (int i = 0; i < n; i++) {
        if (i < (rev[i] >> shift)) {
            swap(a[i], a[rev[i] >> shift]);
        }
    }
    for (int k = 1; k < n; k <<= 1) {
        for (int i = 0; i < n; i += (k << 1)) {
            for (int j = 0; j < k; j++) {
                Complex z = a[i + j + k] * roots[j + k];
                a[i + j + k] = a[i + j] - z;
                a[i + j] = a[i + j] + z;
            }
        }
    }
}
vector<long long> multiply(const vector<int>& a, const vector<int>& b) {
    int need = a.size() + b.size() - 1;
    int nbase = 1;
    while ((1 << nbase) < need) nbase++;
    ensure_base(nbase);
    int sz = 1 << nbase;
    vector<Complex> C(sz);
    for (int i = 0; i < sz; i++) {
        int x = (i < a.size() ? a[i] : 0);
        int y = (i < b.size() ? b[i] : 0);
        C[i] = Complex(x, y);
    }
    fft(C, sz);
    Complex r(0, -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);
    for (int i = 0; i <= (sz >> 1); i++) {
        int j = (sz - i) & (sz - 1);
        Complex z = (C[j] * C[j] - (C[i] * C[i]).conj()) * r;
        C[j] = (C[i] * C[i] - (C[j] * C[j]).conj()) * r;
        C[i] = z;
    }
    for (int i = 0; i < (sz >> 1); i++) {
        Complex C0 = (C[i] + C[i + (sz >> 1)]) * t;
        Complex C1 = (C[i] - C[i + (sz >> 1)]) * t * roots[(sz >> 1) + i];
        C[i] = C0 + C1 * s;
    }
    fft(C, sz >> 1);
    vector<long long> res(need);
    for (int i = 0; i < need; i++) {
        res[i] = llround(i & 1 ? C[i >> 1].y : C[i >> 1].x);
    }
    return res;
}
}  // namespace FastFourierTransform