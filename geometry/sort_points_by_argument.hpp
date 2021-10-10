#include <cmath>

struct pt {
    long long x, y;
    pt(long long x, long long y) : x(x), y(y) {}
};
bool comp(pt l, pt r) {
    auto la = std::atan2(l.y, l.x);
    auto ra = std::atan2(r.y, r.x);
    if (std::abs(la - ra) > 1)
        return la < ra;
    else
        return l.x * r.y > l.y * r.x;
}
