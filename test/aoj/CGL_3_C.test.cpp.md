---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/geometry.hpp
    title: "2 \u6B21\u5143\u5E7E\u4F55\u30E9\u30A4\u30D6\u30E9\u30EA"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_C
  bundledCode: "#line 1 \"test/aoj/CGL_3_C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_C\"\
    \n\n#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n#pragma\
    \ region Macros\ntypedef long long ll;\ntypedef __int128_t i128;\ntypedef unsigned\
    \ int uint;\ntypedef unsigned long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\
    \ntemplate <typename T> istream& operator>>(istream& is, vector<T>& v) {\n   \
    \ for (T& x : v) is >> x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const vector<T>& v) {\n    for (int i = 0; i < (int)v.size(); i++) {\n \
    \       os << v[i] << (i + 1 == (int)v.size() ? \"\" : \" \");\n    }\n    return\
    \ os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const\
    \ pair<T, U>& p) {\n    os << '(' << p.first << ',' << p.second << ')';\n    return\
    \ os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const\
    \ map<T, U>& m) {\n    os << '{';\n    for (auto itr = m.begin(); itr != m.end();)\
    \ {\n        os << '(' << itr->first << ',' << itr->second << ')';\n        if\
    \ (++itr != m.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate\
    \ <typename T, typename U> ostream& operator<<(ostream& os, const unordered_map<T,\
    \ U>& m) {\n    os << '{';\n    for (auto itr = m.begin(); itr != m.end();) {\n\
    \        os << '(' << itr->first << ',' << itr->second << ')';\n        if (++itr\
    \ != m.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename\
    \ T> ostream& operator<<(ostream& os, const set<T>& s) {\n    os << '{';\n   \
    \ for (auto itr = s.begin(); itr != s.end();) {\n        os << *itr;\n       \
    \ if (++itr != s.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\n\
    template <typename T> ostream& operator<<(ostream& os, const multiset<T>& s) {\n\
    \    os << '{';\n    for (auto itr = s.begin(); itr != s.end();) {\n        os\
    \ << *itr;\n        if (++itr != s.end()) os << ',';\n    }\n    os << '}';\n\
    \    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream& os, const\
    \ unordered_set<T>& s) {\n    os << '{';\n    for (auto itr = s.begin(); itr !=\
    \ s.end();) {\n        os << *itr;\n        if (++itr != s.end()) os << ',';\n\
    \    }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const deque<T>& v) {\n    for (int i = 0; i < (int)v.size(); i++) {\n  \
    \      os << v[i] << (i + 1 == (int)v.size() ? \"\" : \" \");\n    }\n    return\
    \ os;\n}\n\ntemplate <int i, typename T> void print_tuple(ostream&, const T&)\
    \ {}\ntemplate <int i, typename T, typename H, class... Args> void print_tuple(ostream&\
    \ os, const T& t) {\n    if (i) os << ',';\n    os << get<i>(t);\n    print_tuple<i\
    \ + 1, T, Args...>(os, t);\n}\ntemplate <typename... Args> ostream& operator<<(ostream&\
    \ os, const tuple<Args...>& t) {\n    os << '{';\n    print_tuple<0, tuple<Args...>,\
    \ Args...>(os, t);\n    return os << '}';\n}\n\nvoid debug_out() { cerr << '\\\
    n'; }\ntemplate <class Head, class... Tail> void debug_out(Head&& head, Tail&&...\
    \ tail) {\n    cerr << head;\n    if (sizeof...(Tail) > 0) cerr << \", \";\n \
    \   debug_out(move(tail)...);\n}\n#ifdef LOCAL\n#define debug(...)           \
    \                                                        \\\n    cerr << \" \"\
    ;                                                                     \\\n   \
    \ cerr << #__VA_ARGS__ << \" :[\" << __LINE__ << \":\" << __FUNCTION__ << \"]\"\
    \ << '\\n'; \\\n    cerr << \" \";                                           \
    \                          \\\n    debug_out(__VA_ARGS__)\n#else\n#define debug(...)\
    \ 42\n#endif\n\ntemplate <typename T> T gcd(T x, T y) { return y != 0 ? gcd(y,\
    \ x % y) : x; }\ntemplate <typename T> T lcm(T x, T y) { return x / gcd(x, y)\
    \ * y; }\n\nint topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t);\
    \ }\nint topbit(long long t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }\n\
    int botbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }\nint botbit(long\
    \ long a) { return a == 0 ? 64 : __builtin_ctzll(a); }\nint popcount(signed t)\
    \ { return __builtin_popcount(t); }\nint popcount(long long t) { return __builtin_popcountll(t);\
    \ }\nbool ispow2(int i) { return i && (i & -i) == i; }\n\ntemplate <class T> T\
    \ ceil(T x, T y) {\n    assert(y >= 1);\n    return (x > 0 ? (x + y - 1) / y :\
    \ x / y);\n}\ntemplate <class T> T floor(T x, T y) {\n    assert(y >= 1);\n  \
    \  return (x > 0 ? x / y : (x - y + 1) / y);\n}\n\ntemplate <class T1, class T2>\
    \ inline bool chmin(T1& a, T2 b) {\n    if (a > b) {\n        a = b;\n       \
    \ return true;\n    }\n    return false;\n}\ntemplate <class T1, class T2> inline\
    \ bool chmax(T1& a, T2 b) {\n    if (a < b) {\n        a = b;\n        return\
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 8 \"geometry/geometry.hpp\"\
    \n\nnamespace geometry {\nusing Real = double;\nconstexpr Real EPS = 1e-8;\nconstexpr\
    \ Real PI = 3.14159265358979323846L;\n\ninline int sgn(Real x) { return x < -EPS\
    \ ? -1 : x > EPS ? 1 : 0; }\n\ninline int compare(Real a, Real b) { return sgn(a\
    \ - b); }\n\ninline bool equals(Real a, Real b) { return compare(a, b) == 0; }\n\
    \nstruct Point {\n    Real x, y;\n\n    Point() {}\n\n    Point(Real x, Real y)\
    \ : x(x), y(y) {}\n\n    Point& operator+=(const Point& p) {\n        x += p.x,\
    \ y += p.y;\n        return *this;\n    }\n\n    Point& operator-=(const Point&\
    \ p) {\n        x -= p.x, y -= p.y;\n        return *this;\n    }\n\n    Point&\
    \ operator*=(const Real& k) {\n        x *= k, y *= k;\n        return *this;\n\
    \    }\n\n    Point& operator/=(const Real& k) {\n        x /= k, y /= k;\n  \
    \      return *this;\n    }\n\n    Point operator+(const Point& p) const { return\
    \ Point(*this) += p; }\n\n    Point operator-(const Point& p) const { return Point(*this)\
    \ -= p; }\n\n    Point operator*(const Real& k) const { return Point(*this) *=\
    \ k; }\n\n    Point operator/(const Real& k) const { return Point(*this) /= k;\
    \ }\n\n    Point operator-() const { return Point(-x, -y); }\n\n    bool operator==(const\
    \ Point& p) const { return (compare(x, p.x) == 0 && compare(y, p.y) == 0); }\n\
    \n    bool operator!=(const Point& p) const { return !(*this == p); }\n\n    bool\
    \ operator<(const Point& p) const {\n        return compare(x, p.x) < 0 || (compare(x,\
    \ p.x) == 0 && compare(y, p.y) < 0);\n    }\n\n    bool operator>(const Point&\
    \ p) const {\n        return compare(x, p.x) > 0 || (compare(x, p.x) == 0 && compare(y,\
    \ p.y) > 0);\n    }\n\n    friend std::istream& operator>>(std::istream& is, Point&\
    \ p) { return is >> p.x >> p.y; }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Point& p) { return os << p.x << ' ' << p.y; }\n\n    Real norm() const\
    \ { return x * x + y * y; }\n\n    Real abs() const { return std::hypot(x, y);\
    \ }\n\n    Real arg() const { return std::atan2(y, x); }\n\n    Point normal()\
    \ const { return Point(-y, x); }\n\n    Point unit() const { return *this / abs();\
    \ }\n\n    Point rotate(Real theta) const {\n        return Point(x * std::cos(theta)\
    \ - y * std::sin(theta), x * std::sin(theta) + y * std::cos(theta));\n    }\n\
    };\n\nPoint polar(const Real& r, const Real& theta) { return Point(cos(theta),\
    \ sin(theta)) * r; }\n\nReal dot(const Point& p, const Point& q) { return p.x\
    \ * q.x + p.y * q.y; }\n\nReal cross(const Point& p, const Point& q) { return\
    \ p.x * q.y - p.y * q.x; }\n\nReal distance(const Point& p, const Point& q) {\
    \ return (p - q).abs(); }\n\nstruct Line {\n    Point a, b;\n\n    Line() {}\n\
    \n    Line(const Point& a, const Point& b) : a(a), b(b) {}\n\n    Line(const Real&\
    \ A, const Real& B, const Real& C) {  // Ax + By = c\n        if (equals(A, 0))\
    \ {\n            assert(!equals(B, 0));\n            a = Point(0, C / B);\n  \
    \          b = Point(1, C / B);\n        } else if (equals(B, 0)) {\n        \
    \    a = Point(C / A, 0);\n            b = Point(C / A, 1);\n        } else {\n\
    \            a = Point(0, C / B);\n            b = Point(C / A, 0);\n        }\n\
    \    }\n\n    friend std::istream& operator>>(std::istream& is, Line& l) { return\
    \ is >> l.a >> l.b; }\n\n    friend std::ostream& operator<<(std::ostream& os,\
    \ const Line& l) { return os << l.a << \" to \" << l.b; }\n\n    Point diff()\
    \ const { return b - a; }\n};\n\nstruct Segment : Line {\n    Segment() {}\n\n\
    \    Segment(Point a, Point b) : Line(a, b) {}\n\n    Real length() const { return\
    \ diff().abs(); }\n};\n\nPoint proj(const Line& l, const Point& p) {\n    Point\
    \ v = l.diff().unit();\n    return l.a + v * dot(v, p - l.a);\n}\n\nPoint refl(const\
    \ Line& l, const Point& p) {\n    Point h = proj(l, p);\n    return h + (h - p);\n\
    }\n\nbool orthogonal(const Line& l, const Line& m) { return equals(dot(l.diff(),\
    \ m.diff()), 0); }\n\nbool parallel(const Line& l, const Line& m) { return equals(cross(l.diff(),\
    \ m.diff()), 0); }\n\nenum Position { COUNTER_CLOCKWISE = +1, CLOCKWISE = -1,\
    \ ONLINE_BACK = +2, ONLINE_FRONT = -2, ON_SEGMENT = 0 };\n\nPosition ccw(const\
    \ Point& a, Point b, Point c) {\n    b -= a, c -= a;\n    if (sgn(cross(b, c))\
    \ == +1) return COUNTER_CLOCKWISE;\n    if (sgn(cross(b, c)) == -1) return CLOCKWISE;\n\
    \    if (sgn(dot(b, c)) == -1) return ONLINE_BACK;\n    if (compare(b.norm(),\
    \ c.norm()) == -1) return ONLINE_FRONT;\n    return ON_SEGMENT;\n}\n\nbool intersect(const\
    \ Line& l, const Point& p) { return abs(ccw(l.a, l.b, p)) != 1; }\n\nbool intersect(const\
    \ Line& l, const Line& m) {\n    Real A = cross(l.diff(), m.diff()), B = cross(l.diff(),\
    \ l.b - m.a);\n    if (equals(A, 0) && equals(B, 0)) return true;\n    return\
    \ !parallel(l, m);\n}\n\nbool intersect(const Line& l, const Segment& s) {\n \
    \   return sgn(cross(l.diff(), s.a - l.a)) * sgn(cross(l.diff(), s.b - l.a)) <=\
    \ 0;\n}\n\nbool intersect(const Segment& s, const Point& p) { return ccw(s.a,\
    \ s.b, p) == ON_SEGMENT; }\n\nbool intersect(const Segment& s, const Segment&\
    \ t) {\n    return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b,\
    \ s.a) * ccw(t.a, t.b, s.b) <= 0;\n}\n\nReal distance(const Line& l, const Point&\
    \ p) { return distance(p, proj(l, p)); }\n\nReal distance(const Line& l, const\
    \ Line& m) { return intersect(l, m) ? 0 : distance(l, m.a); }\n\nReal distance(const\
    \ Line& l, const Segment& s) {\n    return intersect(l, s) ? 0 : std::min(distance(l,\
    \ s.a), distance(l, s.b));\n}\n\nReal distance(const Segment& s, const Point&\
    \ p) {\n    Point h = proj(s, p);\n    return intersect(s, h) ? distance(p, h)\
    \ : std::min(distance(p, s.a), distance(p, s.b));\n}\n\nReal distance(const Segment&\
    \ s, const Segment& t) {\n    if (intersect(s, t)) return 0;\n    return std::min({distance(s,\
    \ t.a), distance(s, t.b), distance(t, s.a), distance(t, s.b)});\n}\n\nPoint crosspoint(const\
    \ Line& l, const Line& m) {\n    assert(intersect(l, m));\n    Real A = cross(l.diff(),\
    \ m.diff()), B = cross(l.diff(), l.b - m.a);\n    if (equals(A, 0) && equals(B,\
    \ 0)) return m.a;\n    return m.a + m.diff() * B / A;\n}\n\nstruct Circle {\n\
    \    Point center;\n    Real radius;\n\n    Circle() {}\n\n    Circle(const Point&\
    \ center, const Real& radius) : center(center), radius(radius) {}\n\n    friend\
    \ std::istream& operator>>(std::istream& is, Circle& c) { return is >> c.center\
    \ >> c.radius; }\n\n    friend std::ostream& operator<<(std::ostream& os, const\
    \ Circle& c) { return os << c.center << ' ' << c.radius; }\n};\n\nbool intersect(const\
    \ Circle& c, const Line& l) { return compare(c.radius, distance(l, c.center))\
    \ >= 0; }\n\nint intersect(const Circle& c, const Segment& s) {\n    Point h =\
    \ proj(s, c.center);\n    if (compare(distance(c.center, h), c.radius) > 0) return\
    \ 0;\n    Real d1 = (c.center - s.a).abs(), d2 = (c.center - s.b).abs();\n   \
    \ if (compare(c.radius, d1) >= 0 && compare(c.radius, d2) >= 0) return 0;\n  \
    \  if (compare(c.radius, d1) * compare(c.radius, d2) < 0) return 1;\n    if (sgn(dot(s.a\
    \ - h, s.b - h)) < 0) return 2;\n    return 0;\n}\n\nstd::vector<Point> crosspoint(const\
    \ Circle& c, const Line& l) {\n    Point h = proj(l, c.center);\n    Real d =\
    \ c.radius * c.radius - (c.center - h).norm();\n    if (sgn(d) < 0) return {};\n\
    \    if (sgn(d) == 0) return {h};\n    Point v = l.diff().unit() * sqrt(d);\n\
    \    return {h - v, h + v};\n}\n\nstd::vector<Point> crosspoint(const Circle&\
    \ c, const Segment& s) {\n    int num = intersect(c, s);\n    if (num == 0) return\
    \ {};\n    auto res = crosspoint(c, Line(s.a, s.b));\n    if (num == 2) return\
    \ res;\n    if (sgn(dot(s.a - res[0], s.b - res[0])) > 0) std::swap(res[0], res[1]);\n\
    \    return {res[0]};\n}\n\n// requirement : c != d\nstd::vector<Point> crosspoint(const\
    \ Circle& c1, const Circle& c2) {\n    Real r1 = c1.radius, r2 = c2.radius;\n\
    \    if (r1 < r2) return crosspoint(c2, c1);\n    Real d = distance(c1.center,\
    \ c2.center);\n    if (compare(d, r1 + r2) > 0 || compare(d, r1 - r2) < 0) return\
    \ {};\n    Real alpha = std::acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));\n\
    \    Real theta = (c2.center - c1.center).arg();\n    Point p = c1.center + polar(r1,\
    \ theta + alpha);\n    Point q = c1.center + polar(r1, theta - alpha);\n    if\
    \ (p == q) return {p};\n    return {p, q};\n}\n\nLine bisector(const Point& p,\
    \ const Point& q) {\n    Point c = (p + q) * 0.5;\n    Point v = (q - p).normal();\n\
    \    return Line(c - v, c + v);\n}\n\nCircle circumcircle(Point a, Point b, const\
    \ Point& c) {\n    Point center = crosspoint(bisector(a, c), bisector(b, c));\n\
    \    return Circle(center, distance(c, center));\n}\n\nstd::vector<Point> center_given_radius(const\
    \ Point& a, const Point& b, const Real& r) {\n    Point m = (b - a) * 0.5;\n \
    \   Real d1 = m.abs();\n    if (equals(d1, 0) || d1 > r) return {};\n    Real\
    \ d2 = sqrt(r * r - d1 * d1);\n    Point n = m.normal() * d2 / d1;\n    Point\
    \ p = a + m - n, q = a + m + n;\n    if (p == q) return {p};\n    return {p, q};\n\
    }\n\nint count_tangent(const Circle& c1, const Circle& c2) {\n    Real r1 = c1.radius,\
    \ r2 = c2.radius;\n    if (r1 < r2) return count_tangent(c2, c1);\n    Real d\
    \ = distance(c1.center, c2.center);\n    if (compare(d, r1 + r2) > 0) return 4;\n\
    \    if (compare(d, r1 + r2) == 0) return 3;\n    if (compare(d, r1 - r2) > 0)\
    \ return 2;\n    if (compare(d, r1 - r2) == 0) return 1;\n    return 0;\n}\n\n\
    std::vector<Point> tangent_to_circle(const Circle& c, const Point& p) {\n    return\
    \ crosspoint(c, Circle(p, sqrt((c.center - p).norm() - c.radius * c.radius)));\n\
    }\n\nenum Contain { OUT, ON, IN };\n\nstruct Polygon : std::vector<Point> {\n\
    \    using std::vector<Point>::vector;\n\n    Polygon(int n) : std::vector<Point>(n)\
    \ {}\n\n    std::vector<Segment> segments() const {\n        assert(size() > 1);\n\
    \        std::vector<Segment> segs;\n        for (size_t i = 0; i < size(); i++)\
    \ segs.emplace_back((*this)[i], (*this)[(i + 1) % size()]);\n        return segs;\n\
    \    }\n\n    Real area() const {\n        Real sum = 0;\n        for (size_t\
    \ i = 0; i < size(); i++) sum += cross((*this)[i], (*this)[(i + 1) % size()]);\n\
    \        return std::abs(sum) / 2;\n    }\n\n    bool is_convex(bool accept_on_segment\
    \ = true) const {\n        int n = size();\n        for (int i = 0; i < n; i++)\
    \ {\n            if (accept_on_segment) {\n                if (ccw((*this)[i],\
    \ (*this)[(i + 1) % n], (*this)[(i + 2) % n]) == CLOCKWISE) {\n              \
    \      return false;\n                }\n            } else {\n              \
    \  if (ccw((*this)[i], (*this)[(i + 1) % n], (*this)[(i + 2) % n]) != COUNTER_CLOCKWISE)\
    \ {\n                    return false;\n                }\n            }\n   \
    \     }\n        return true;\n    }\n};\n\nContain contain(const Polygon& P,\
    \ const Point& p) {\n    bool in = false;\n    for (size_t i = 0; i < P.size();\
    \ i++) {\n        if (ccw(P[i], P[(i + 1) % P.size()], p) == ON_SEGMENT) return\
    \ ON;\n        Point a = P[i] - p, b = P[(i + 1) % P.size()] - p;\n        if\
    \ (a.y > b.y) std::swap(a, b);\n        if (sgn(a.y) <= 0 && sgn(b.y) > 0 && sgn(cross(a,\
    \ b)) < 0) in = !in;\n    }\n    return in ? IN : OUT;\n}\n\nPolygon convex_hull(Polygon&\
    \ P, bool accept_on_segment = false) {\n    int n = P.size(), k = 0;\n    if (n\
    \ <= 2) return P;\n    std::sort(P.begin(), P.end());\n    Polygon ch(n * 2);\n\
    \    auto check = [&](int i) {\n        if (accept_on_segment) return ccw(ch[k\
    \ - 2], ch[k - 1], P[i]) == CLOCKWISE;\n        return ccw(ch[k - 2], ch[k - 1],\
    \ P[i]) != COUNTER_CLOCKWISE;\n    };\n    for (int i = 0; i < n; ch[k++] = P[i++])\
    \ {\n        while (k >= 2 && check(i)) {\n            k--;\n        }\n    }\n\
    \    for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = P[i--]) {\n        while\
    \ (k >= t && check(i)) {\n            k--;\n        }\n    }\n    ch.resize(k\
    \ - 1);\n    int start = 0;\n    for (int i = 1; i < k - 1; i++) {\n        if\
    \ (equals(ch[i].y, ch[start].y) ? ch[i].x < ch[start].x : ch[i].y < ch[start].y)\
    \ {\n            start = i;\n        }\n    }\n    std::rotate(ch.begin(), ch.begin()\
    \ + start, ch.end());\n    return ch;\n}\n\nstd::tuple<int, int, Real> convex_diameter(const\
    \ Polygon& convex) {\n    assert(convex.is_convex());\n    int n = convex.size();\n\
    \    Real max_dist = -1;\n    std::pair<int, int> argmax = {-1, -1};\n    for\
    \ (int i = 0, j = 0; i < n; i++) {\n        while (j + 1 < n && distance(convex[i],\
    \ convex[j + 1]) > distance(convex[i], convex[j])) j++;\n        double cur_dist\
    \ = distance(convex[i], convex[j]);\n        if (max_dist < cur_dist) {\n    \
    \        max_dist = cur_dist;\n            argmax = {i, j};\n        }\n    }\n\
    \    return {argmax.first, argmax.second, max_dist};\n}\n\nPolygon convex_cut(const\
    \ Polygon& convex, const Line& l) {\n    assert(convex.is_convex());\n    int\
    \ n = convex.size();\n    Polygon res;\n    for (int i = 0; i < n; i++) {\n  \
    \      const Point& cur = convex[i];\n        const Point& nxt = convex[(i + 1)\
    \ % n];\n        if (ccw(l.a, l.b, cur) != CLOCKWISE) res.emplace_back(cur);\n\
    \        if (ccw(l.a, l.b, cur) * ccw(l.a, l.b, nxt) < 0) res.emplace_back(crosspoint(Segment(cur,\
    \ nxt), l));\n    }\n    return res;\n}\n\nPolygon voronoi(const Polygon& P, const\
    \ std::vector<Point>& ps, size_t idx) {\n    Polygon res = P;\n    for (size_t\
    \ i = 0; i < ps.size(); i++) {\n        if (i == idx) continue;\n        res =\
    \ convex_cut(res, bisector(ps[idx], ps[i]));\n    }\n    return res;\n}\n\n} \
    \ // namespace geometry\n\n/**\n * @brief 2 \u6B21\u5143\u5E7E\u4F55\u30E9\u30A4\
    \u30D6\u30E9\u30EA\n * @docs docs/geometry/geometry.md\n */\n#line 5 \"test/aoj/CGL_3_C.test.cpp\"\
    \n\nusing namespace geometry;\n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    int n;\n    cin >> n;\n    Polygon g(n);\n    for (auto& p : g) cin >> p;\n\
    \    int q;\n    cin >> q;\n    for (; q--;) {\n        Point p;\n        cin\
    \ >> p;\n        cout << contain(g, p) << '\\n';\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_C\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../geometry/geometry.hpp\"\n\n\
    using namespace geometry;\n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    int n;\n    cin >> n;\n    Polygon g(n);\n    for (auto& p : g) cin >> p;\n\
    \    int q;\n    cin >> q;\n    for (; q--;) {\n        Point p;\n        cin\
    \ >> p;\n        cout << contain(g, p) << '\\n';\n    }\n    return 0;\n}"
  dependsOn:
  - base.hpp
  - geometry/geometry.hpp
  isVerificationFile: true
  path: test/aoj/CGL_3_C.test.cpp
  requiredBy: []
  timestamp: '2021-10-01 16:25:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL_3_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_3_C.test.cpp
- /verify/test/aoj/CGL_3_C.test.cpp.html
title: test/aoj/CGL_3_C.test.cpp
---
