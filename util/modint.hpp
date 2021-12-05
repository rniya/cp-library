#pragma once
#include <iostream>
#include "atcoder/modint"

namespace atcoder {

template <int MOD> std::istream& operator>>(std::istream& is, static_modint<MOD>& x) {
    int64_t v;
    x = static_modint<MOD>{(is >> v, v)};
    return is;
}

template <int MOD> std::ostream& operator<<(std::ostream& os, const static_modint<MOD>& x) { return os << x.val(); }

template <int ID> std::ostream& operator<<(std::ostream& os, const dynamic_modint<ID>& x) { return os << x.val(); }

}  // namespace atcoder
