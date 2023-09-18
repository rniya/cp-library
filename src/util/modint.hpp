#pragma once
#include <iostream>
#include "atcoder/modint"

namespace atcoder {

template <class T, internal::is_modint_t<T>* = nullptr> std::istream& operator>>(std::istream& is, T& x) {
    int v;
    is >> v;
    x = T::raw(v);
    return is;
}

template <class T, internal::is_modint_t<T>* = nullptr> std::ostream& operator<<(std::ostream& os, const T& x) {
    return os << x.val();
}

}  // namespace atcoder
