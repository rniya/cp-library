---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':question:'
    path: geometry/geometry.hpp
    title: geometry
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_D
  bundledCode: "#line 1 \"test/aoj/CGL_2_D.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_D\"\
    \n\n#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\ntypedef\
    \ long long ll;\ntypedef __int128_t i128;\ntypedef unsigned int uint;\ntypedef\
    \ unsigned long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\ntemplate <typename\
    \ T> istream& operator>>(istream& is, vector<T>& v) {\n    for (T& x : v) is >>\
    \ x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream& os,\
    \ const vector<T>& v) {\n    for (int i = 0; i < v.size(); i++) {\n        os\
    \ << v[i] << (i + 1 == v.size() ? \"\" : \" \");\n    }\n    return os;\n}\ntemplate\
    \ <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>&\
    \ p) {\n    os << '(' << p.first << ',' << p.second << ')';\n    return os;\n\
    }\ntemplate <typename T, typename U, typename V> ostream& operator<<(ostream&\
    \ os, const tuple<T, U, V>& t) {\n    os << '(' << get<0>(t) << ',' << get<1>(t)\
    \ << ',' << get<2>(t) << ')';\n    return os;\n}\ntemplate <typename T, typename\
    \ U, typename V, typename W> ostream& operator<<(ostream& os, const tuple<T, U,\
    \ V, W>& t) {\n    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t)\
    \ << ',' << get<3>(t) << ')';\n    return os;\n}\ntemplate <typename T, typename\
    \ U> ostream& operator<<(ostream& os, const map<T, U>& m) {\n    os << '{';\n\
    \    for (auto itr = m.begin(); itr != m.end();) {\n        os << '(' << itr->first\
    \ << ',' << itr->second << ')';\n        if (++itr != m.end()) os << ',';\n  \
    \  }\n    os << '}';\n    return os;\n}\ntemplate <typename T, typename U> ostream&\
    \ operator<<(ostream& os, const unordered_map<T, U>& m) {\n    os << '{';\n  \
    \  for (auto itr = m.begin(); itr != m.end();) {\n        os << '(' << itr->first\
    \ << ',' << itr->second << ')';\n        if (++itr != m.end()) os << ',';\n  \
    \  }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const set<T>& s) {\n    os << '{';\n    for (auto itr = s.begin(); itr !=\
    \ s.end();) {\n        os << *itr;\n        if (++itr != s.end()) os << ',';\n\
    \    }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const multiset<T>& s) {\n    os << '{';\n    for (auto itr = s.begin();\
    \ itr != s.end();) {\n        os << *itr;\n        if (++itr != s.end()) os <<\
    \ ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream&\
    \ operator<<(ostream& os, const unordered_set<T>& s) {\n    os << '{';\n    for\
    \ (auto itr = s.begin(); itr != s.end();) {\n        os << *itr;\n        if (++itr\
    \ != s.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename\
    \ T> ostream& operator<<(ostream& os, const deque<T>& v) {\n    for (int i = 0;\
    \ i < v.size(); i++) {\n        os << v[i] << (i + 1 == v.size() ? \"\" : \" \"\
    );\n    }\n    return os;\n}\n\nvoid debug_out() { cerr << '\\n'; }\ntemplate\
    \ <class Head, class... Tail> void debug_out(Head&& head, Tail&&... tail) {\n\
    \    cerr << head;\n    if (sizeof...(Tail) > 0) cerr << \", \";\n    debug_out(move(tail)...);\n\
    }\n#ifdef LOCAL\n#define debug(...)                                          \
    \                         \\\n    cerr << \" \";                             \
    \                                        \\\n    cerr << #__VA_ARGS__ << \" :[\"\
    \ << __LINE__ << \":\" << __FUNCTION__ << \"]\" << '\\n'; \\\n    cerr << \" \"\
    ;                                                                     \\\n   \
    \ debug_out(__VA_ARGS__)\n#else\n#define debug(...) 42\n#endif\n\ntemplate <typename\
    \ T> T gcd(T x, T y) { return y != 0 ? gcd(y, x % y) : x; }\ntemplate <typename\
    \ T> T lcm(T x, T y) { return x / gcd(x, y) * y; }\n\ntemplate <class T1, class\
    \ T2> inline bool chmin(T1& a, T2 b) {\n    if (a > b) {\n        a = b;\n   \
    \     return true;\n    }\n    return false;\n}\ntemplate <class T1, class T2>\
    \ inline bool chmax(T1& a, T2 b) {\n    if (a < b) {\n        a = b;\n       \
    \ return true;\n    }\n    return false;\n}\n#line 3 \"geometry/geometry.hpp\"\
    \n\n/**\n * @brief geometry\n * @docs docs/geometry/geometry.md\n */\nconst double\
    \ EPS = 1e-8, PI = acos(-1);\ninline bool EQ(double a, double b) { return fabs(b\
    \ - a) < EPS; }\n\nstruct Point {\n    double x, y;\n    Point() {}\n    Point(double\
    \ x, double y) : x(x), y(y) {}\n    Point operator-() const { return Point(-x,\
    \ -y); }\n    Point operator+(Point p) const { return Point(x + p.x, y + p.y);\
    \ }\n    Point operator-(Point p) const { return Point(x - p.x, y - p.y); }\n\
    \    Point operator*(double t) const { return Point(x * t, y * t); }\n    Point\
    \ operator*(Point p) const { return Point(x * p.x - y * p.y, x * p.y + y * p.x);\
    \ }\n    Point operator/(double t) const { return Point(x / t, y / t); }\n   \
    \ bool operator<(const Point& p) const { return x != p.x ? x < p.x : y < p.y;\
    \ }\n    bool operator==(const Point& p) const { return EQ(x, p.x) && EQ(y, p.y);\
    \ }\n    friend istream& operator>>(istream& is, Point& p) {\n        is >> p.x\
    \ >> p.y;\n        return is;\n    }\n    friend ostream& operator<<(ostream&\
    \ os, Point p) {\n        os << fixed << setprecision(10) << p.x << ' ' << p.y;\n\
    \        return os;\n    }\n};\n\nstruct Line {\n    Point a, b;\n    Line() {}\n\
    \    Line(Point a, Point b) : a(a), b(b) {}\n    friend istream& operator>>(istream&\
    \ is, Line& l) {\n        is >> l.a >> l.b;\n        return is;\n    }\n    friend\
    \ ostream& operator<<(ostream& os, Line l) {\n        os << l.a << \" to \" <<\
    \ l.b;\n        return os;\n    }\n};\n\nstruct Segment : Line {\n    Segment()\
    \ {}\n    Segment(Point a, Point b) : Line(a, b) {}\n};\n\nstruct Circle {\n \
    \   Point c;\n    double r;\n    Circle() {}\n    Circle(Point c, double r) :\
    \ c(c), r(r) {}\n    friend istream& operator>>(istream& is, Circle& c) {\n  \
    \      is >> c.c >> c.r;\n        return is;\n    }\n    friend ostream& operator<<(ostream&\
    \ os, Circle& c) {\n        os << c.c << ' ' << c.r;\n        return os;\n   \
    \ }\n};\n\nusing Polygon = vector<Point>;\n\ndouble dot(const Point&, const Point&);\n\
    double cross(const Point&, const Point&);\ndouble norm(const Point&);\ndouble\
    \ abs(const Point&);\nPoint projection(const Line&, const Point&);\nPoint reflection(const\
    \ Line&, const Point&);\ndouble arg(const Point&);\ndouble radian_to_degree(const\
    \ double&);\ndouble degree_to_radian(const double&);\nPoint polar(const double&,\
    \ const double&);\nPoint rotate(const Point&, const double&);\ndouble get_angle(const\
    \ Point&, const Point&, const Point&);\nenum { COUNTER_CLOCKWISE = 1, CLOCKWISE\
    \ = -1, ONLINE_BACK = 2, ONLINE_FRONT = -2, ON_SEGMENT = 0 };\nint ccw(const Point&,\
    \ Point, Point);\nbool orthogonal(const Point&, const Point&);\nbool orthogonal(const\
    \ Point&, const Point&, const Point&, const Point&);\nbool orthogonal(const Line&,\
    \ const Line&);\nbool parallel(const Point&, const Point&);\nbool parallel(const\
    \ Point&, const Point&);\nbool parallel(const Point&, const Point&, const Point&,\
    \ const Point&);\nbool parallel(const Line&, const Line&);\nbool intersect(const\
    \ Line&, const Point&);\nbool intersect(const Line&, const Line&);\nbool intersect(const\
    \ Line&, const Segment&);\nbool intersect(const Segment&, const Point&);\nbool\
    \ intersect(const Segment&, const Segment&);\nbool intersect(const Circle&, const\
    \ Line&);\nint intersect(const Circle&, const Segment&);\nbool intersect(Circle,\
    \ Circle);\nint count_tangent(Circle, Circle);\ndouble distance(const Point&,\
    \ const Point&);\ndouble distance(const Line&, const Point&);\ndouble distance(const\
    \ Line&, const Line&);\ndouble distance(const Segment&, const Point&);\ndouble\
    \ distance(const Segment&, const Segment&);\ndouble distance(const Line&, const\
    \ Segment&);\nPoint crosspoint(const Line&, const Line&);\nPoint crosspoint(const\
    \ Segment&, const Segment&);\npair<Point, Point> crosspoint(const Circle&, const\
    \ Line&);\npair<Point, Point> crosspoint(const Circle&, const Segment&);\npair<Point,\
    \ Point> crosspoint(const Circle&, const Circle&);\nCircle circumcenter(Point,\
    \ Point, const Point&);\npair<Point, Point> center_given_radius(const Point&,\
    \ const Point&, const double&);\npair<Point, Point> tangent(const Circle&, const\
    \ Point&);\nvector<Line> common_tangent(Circle, Circle);\ndouble area(const Polygon&);\n\
    enum { OUT, ON, IN };\nint contain(const Polygon&, const Point&);\nint contain(const\
    \ Circle&, const Point&);\nbool is_convex(const Polygon&);\nPolygon convex_hull(Polygon,\
    \ bool);\ndouble convex_diameter(Polygon);\nPolygon convex_cut(const Polygon&,\
    \ const Line&);\n\ndouble dot(const Point& a, const Point& b) { return a.x * b.x\
    \ + a.y * b.y; }\ndouble cross(const Point& a, const Point& b) { return a.x *\
    \ b.y - a.y * b.x; }\ndouble norm(const Point& p) { return p.x * p.x + p.y * p.y;\
    \ }\ndouble abs(const Point& p) { return sqrt(norm(p)); }\n\nPoint projection(const\
    \ Line& l, const Point& p) {\n    double t = dot(p - l.a, l.b - l.a) / norm(l.b\
    \ - l.a);\n    return l.a + (l.b - l.a) * t;\n}\nPoint reflection(const Line&\
    \ l, const Point& p) { return p + (projection(l, p) - p) * 2.0; }\n\ndouble arg(const\
    \ Point& p) { return atan2(p.y, p.x); }\ndouble radian_to_degree(const double&\
    \ r) { return r * 180.0 / PI; }\ndouble degree_to_radian(const double& d) { return\
    \ d * PI / 180.0; }\nPoint polar(const double& r, const double& theta) { return\
    \ Point(cos(theta), sin(theta)) * r; }\nPoint rotate(const Point& p, const double&\
    \ theta) {\n    return Point(cos(theta) * p.x - sin(theta) * p.y, sin(theta) *\
    \ p.x + cos(theta) * p.y);\n}\ndouble get_angle(const Point& a, const Point& b,\
    \ const Point& c) {\n    const Point v = b - a, w = c - b;\n    double alpha =\
    \ arg(v), beta = arg(w);\n    if (alpha > beta) swap(alpha, beta);\n    double\
    \ theta = beta - alpha;\n    return min(theta, 2 * PI - theta);\n}\n\nint ccw(const\
    \ Point& a, Point b, Point c) {\n    b = b - a, c = c - a;\n    if (cross(b, c)\
    \ > EPS) return COUNTER_CLOCKWISE;\n    if (cross(b, c) < -EPS) return CLOCKWISE;\n\
    \    if (dot(b, c) < 0) return ONLINE_BACK;\n    if (norm(b) < norm(c)) return\
    \ ONLINE_FRONT;\n    return ON_SEGMENT;\n}\n\nbool orthogonal(const Point& a,\
    \ const Point& b) { return EQ(dot(a, b), 0.0); }\nbool orthogonal(const Point&\
    \ a, const Point& b, const Point& c, const Point& d) { return orthogonal(b - a,\
    \ d - c); }\nbool orthogonal(const Line& l, const Line& m) { return EQ(dot(l.b\
    \ - l.a, m.b - m.a), 0.0); }\nbool parallel(const Point& a, const Point& b) {\
    \ return EQ(cross(a, b), 0.0); }\nbool parallel(const Point& a, const Point& b,\
    \ const Point& c, const Point& d) { return parallel(b - a, d - c); }\nbool parallel(const\
    \ Line& l, const Line& m) { return EQ(cross(l.b - l.a, m.b - m.a), 0.0); }\n\n\
    bool intersect(const Line& l, const Point& p) { return abs(ccw(l.a, l.b, p)) !=\
    \ COUNTER_CLOCKWISE; }\nbool intersect(const Line& l, const Line& m) {\n    return\
    \ abs(cross(l.b - l.a, m.b - m.a)) > EPS || abs(cross(l.b - l.a, m.b - l.a)) <\
    \ EPS;\n}\nbool intersect(const Line& l, const Segment& s) {\n    return cross(l.b\
    \ - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < EPS;\n}\nbool intersect(const\
    \ Segment& s, const Point& p) { return ccw(s.a, s.b, p) == ON_SEGMENT; }\nbool\
    \ intersect(const Segment& s, const Segment& t) {\n    return ccw(s.a, s.b, t.a)\
    \ * ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;\n\
    }\nbool intersect(const Circle& c, const Line& l) { return distance(l, c.c) <=\
    \ c.r + EPS; }\nint intersect(const Circle& c, const Segment& s) {\n    Point\
    \ h = projection(s, c.c);\n    double d1 = abs(c.c - s.a), d2 = abs(c.c - s.b);\n\
    \    if (norm(h - c.c) - c.r * c.r > EPS) return 0;\n    if (d1 < c.r + EPS &&\
    \ d2 < c.r + EPS) return 0;\n    if ((d1 < c.r - EPS && d2 > c.r + EPS) || (d1\
    \ > c.r + EPS && d2 < c.r - EPS)) return 1;\n    if (dot(s.a - h, s.b - h) < 0)\
    \ return 2;\n    return 0;\n}\nbool intersect(Circle a, Circle b) {\n    int c\
    \ = count_tangent(a, b);\n    return 1 <= c && c <= 3;\n}\nint count_tangent(Circle\
    \ a, Circle b) {\n    if (a.r < b.r) swap(a, b);\n    double d = abs(a.c - b.c);\n\
    \    if (a.r + b.r < d) return 4;\n    if (EQ(a.r + b.r, d)) return 3;\n    if\
    \ (a.r - b.r < d) return 2;\n    if (EQ(a.r - b.r, d)) return 1;\n    return 0;\n\
    }\n\ndouble distance(const Point& a, const Point& b) { return abs(b - a); }\n\
    double distance(const Line& l, const Point& p) { return distance(p, projection(l,\
    \ p)); }\ndouble distance(const Line& l, const Line& m) { return intersect(l,\
    \ m) ? 0 : distance(l, m.a); }\ndouble distance(const Segment& s, const Point&\
    \ p) {\n    Point h = projection(s, p);\n    return intersect(s, h) ? distance(p,\
    \ h) : min(distance(p, s.a), distance(p, s.b));\n}\ndouble distance(const Segment&\
    \ s, const Segment& t) {\n    return intersect(s, t) ? 0 : min({distance(s, t.a),\
    \ distance(s, t.b), distance(t, s.a), distance(t, s.b)});\n}\ndouble distance(const\
    \ Line& l, const Segment& s) {\n    return intersect(l, s) ? 0 : min(distance(l,\
    \ s.a), distance(l, s.b));\n}\n\nPoint crosspoint(const Line& l, const Line& m)\
    \ {\n    assert(intersect(l, m));\n    double d1 = cross(l.b - l.a, m.b - m.a),\
    \ d2 = cross(l.b - l.a, l.b - m.a);\n    if (EQ(abs(d1), 0.0) && EQ(abs(d2), 0.0))\
    \ return m.a;\n    return m.a + (m.b - m.a) * d2 / d1;\n}\nPoint crosspoint(const\
    \ Segment& s, const Segment& t) {\n    assert(intersect(s, t));\n    return crosspoint(Line(s),\
    \ Line(t));\n}\npair<Point, Point> crosspoint(const Circle& c, const Line& l)\
    \ {\n    assert(intersect(c, l));\n    Point h = projection(l, c.c);\n    Point\
    \ e = (l.b - l.a) / abs(l.b - l.a) * sqrt(c.r * c.r - norm(h - c.c));\n    return\
    \ minmax(h - e, h + e);\n}\npair<Point, Point> crosspoint(const Circle& c, const\
    \ Segment& s) {\n    assert(intersect(c, s));\n    auto res = crosspoint(c, Line(s));\n\
    \    if (intersect(c, s) == 2) return res;\n    return intersect(s, res.first)\
    \ ? make_pair(res.first, res.first) : make_pair(res.second, res.second);\n}\n\
    pair<Point, Point> crosspoint(const Circle& a, const Circle& b) {\n    assert(intersect(a,\
    \ b));\n    double d = distance(a.c, b.c);\n    double alpha = acos((a.r * a.r\
    \ + d * d - b.r * b.r) / (2 * a.r * d));\n    double theta = arg(b.c - a.c);\n\
    \    return minmax(a.c + polar(a.r, theta + alpha), a.c + polar(a.r, theta - alpha));\n\
    }\n\nCircle circumcenter(Point a, Point b, const Point& c) {\n    a = (a - c)\
    \ * 0.5;\n    b = (b - c) * 0.5;\n    Point center = c + crosspoint(Line(a, a\
    \ * Point(1.0, 1.0)), Line{b, b * Point(1.0, 1.0)});\n    return Circle{center,\
    \ abs(c - center)};\n}\npair<Point, Point> center_given_radius(const Point& a,\
    \ const Point& b, const double& r) {\n    Point m = (b - a) * 0.5;\n    double\
    \ d1 = abs(m);\n    assert(!(EQ(d1, 0.0) || d1 > r));\n    double d2 = sqrt(r\
    \ * r - d1 * d1);\n    Point n = m * Point(0.0, 1.0) * d2 / d1;\n    return minmax(a\
    \ + m - n, a + m + n);\n}\npair<Point, Point> tangent(const Circle& c, const Point&\
    \ p) {\n    return crosspoint(c, Circle(p, sqrt(norm(c.c - p) - c.r * c.r)));\n\
    }\nvector<Line> common_tangent(Circle a, Circle b) {\n    vector<Line> res;\n\
    \    if (a.r < b.r) swap(a, b);\n    double g = distance(a.c, b.c);\n    if (EQ(g,\
    \ 0.0)) return res;\n    Point u = (b.c - a.c) / g;\n    Point v = rotate(u, PI\
    \ * 0.5);\n    for (int s : {-1, 1}) {\n        double h = (a.r + s * b.r) / g;\n\
    \        if (EQ(1.0 - h * h, 0.0))\n            res.emplace_back(a.c + u * a.r,\
    \ a.c + (u + v) * a.r);\n        else if (1.0 - h * h > 0.0) {\n            Point\
    \ U = u * h, V = v * sqrt(1 - h * h);\n            res.emplace_back(a.c + (U +\
    \ V) * a.r, b.c - (U + V) * b.r * s);\n            res.emplace_back(a.c + (U -\
    \ V) * a.r, b.c - (U - V) * b.r * s);\n        }\n    }\n    return res;\n}\n\n\
    double area(const Polygon& P) {\n    int n = P.size();\n    double res = 0;\n\
    \    for (int i = 0; i < n; i++) res += cross(P[i], P[(i + 1) % n]);\n    return\
    \ res * 0.5;\n}\n\nint contain(const Polygon& P, const Point& p) {\n    int n\
    \ = P.size();\n    bool in = false;\n    for (int i = 0; i < n; i++) {\n     \
    \   Point a = P[i] - p, b = P[(i + 1) % n] - p;\n        if (a.y > b.y) swap(a,\
    \ b);\n        if (a.y <= 0 && 0 < b.y && cross(a, b) < 0) in = !in;\n       \
    \ if (cross(a, b) == 0 && dot(a, b) <= 0) return ON;\n    }\n    return in ? IN\
    \ : OUT;\n}\nint contain(const Circle& c, const Point& p) {\n    double d = distance(c.c,\
    \ p);\n    return EQ(d, c.r) ? ON : d < c.r ? IN : OUT;\n}\n\nbool is_convex(const\
    \ Polygon& P) {\n    int n = P.size();\n    for (int i = 0; i < n; i++) {\n  \
    \      if (ccw(P[(i + n - 1) % n], P[i], P[(i + 1) % n]) == CLOCKWISE) {\n   \
    \         return false;\n        }\n    }\n    return true;\n}\nPolygon convex_hull(Polygon\
    \ P, bool ONSEG) {\n    int n = P.size(), k = 0;\n    if (n <= 2) return P;\n\
    \    sort(P.begin(), P.end());\n    Polygon ch(2 * n);\n    for (int i = 0; i\
    \ < n; ch[k++] = P[i++]) {\n        if (ONSEG)\n            while (k >= 2 && ccw(ch[k\
    \ - 2], ch[k - 1], P[i]) == CLOCKWISE) k--;\n        else\n            while (k\
    \ >= 2 && ccw(ch[k - 2], ch[k - 1], P[i]) != COUNTER_CLOCKWISE) k--;\n    }\n\
    \    for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = P[i--]) {\n        if (ONSEG)\n\
    \            while (k >= t && ccw(ch[k - 2], ch[k - 1], P[i]) == CLOCKWISE) k--;\n\
    \        else\n            while (k >= t && ccw(ch[k - 2], ch[k - 1], P[i]) !=\
    \ COUNTER_CLOCKWISE) k--;\n    }\n    ch.resize(k - 1);\n    int start = 0;\n\
    \    for (int i = 1; i < k - 1; i++) {\n        if (EQ(ch[i].y, ch[start].y) ?\
    \ ch[i].x < ch[start].x : ch[i].y < ch[start].y) start = i;\n    }\n    rotate(ch.begin(),\
    \ ch.begin() + start, ch.end());\n    return ch;\n}\n\ndouble convex_diameter(Polygon\
    \ P) {\n    if (!is_convex(P)) P = convex_hull(P, false);\n    int n = P.size();\n\
    \    int is = 0, js = 0;\n    for (int i = 1; i < n; i++) {\n        if (P[i].y\
    \ > P[is].y) is = i;\n        if (P[i].y < P[js].y) js = i;\n    }\n    double\
    \ maxd = norm(P[is] - P[js]);\n    int i, maxi, j, maxj;\n    i = maxi = is;\n\
    \    j = maxj = js;\n    do {\n        if (cross(P[(i + 1) % n] - P[i], P[(j +\
    \ 1) % n] - P[j]) >= 0)\n            j = (j + 1) % n;\n        else\n        \
    \    i = (i + 1) % n;\n        if (maxd < norm(P[i] - P[j])) {\n            maxd\
    \ = norm(P[i] - P[j]);\n            maxi = i;\n            maxj = j;\n       \
    \ }\n    } while (i != is || j != js);\n    return sqrt(maxd);\n}\n\nPolygon convex_cut(const\
    \ Polygon& P, const Line& l) {\n    int n = P.size();\n    Polygon res;\n    for\
    \ (int i = 0; i < n; i++) {\n        Point cur = P[i], nxt = P[(i + 1) % n];\n\
    \        if (ccw(l.a, l.b, cur) != CLOCKWISE) res.emplace_back(cur);\n       \
    \ if (ccw(l.a, l.b, cur) * ccw(l.a, l.b, nxt) < 0) res.emplace_back(crosspoint(Segment(cur,\
    \ nxt), l));\n    }\n    return res;\n}\n#line 5 \"test/aoj/CGL_2_D.test.cpp\"\
    \n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    cout <<\
    \ fixed << setprecision(10);\n    int q; cin >> q;\n    for (;q--;){\n       \
    \ Segment s_1,s_2; cin >> s_1 >> s_2;\n        cout << distance(s_1,s_2) << '\\\
    n';\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_D\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../geometry/geometry.hpp\"\n\n\
    int main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    cout << fixed\
    \ << setprecision(10);\n    int q; cin >> q;\n    for (;q--;){\n        Segment\
    \ s_1,s_2; cin >> s_1 >> s_2;\n        cout << distance(s_1,s_2) << '\\n';\n \
    \   }\n}"
  dependsOn:
  - base.hpp
  - geometry/geometry.hpp
  isVerificationFile: true
  path: test/aoj/CGL_2_D.test.cpp
  requiredBy: []
  timestamp: '2021-01-20 10:53:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL_2_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_2_D.test.cpp
- /verify/test/aoj/CGL_2_D.test.cpp.html
title: test/aoj/CGL_2_D.test.cpp
---
