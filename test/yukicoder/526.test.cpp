#define PROBLEM "https://yukicoder.me/problems/no/526"

#include "../../base.hpp"
#include "../../linearalgebra/Matrix.hpp"
#include "../../modulo/dynamic_modint.hpp"

using mint = dynamic_modint;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;

    mint::set_mod(M);
    Matrix<mint> m(2);
    m[0][1] = m[1][0] = m[1][1] = 1;
    m ^= N;

    cout << m[0][0] << '\n';
}