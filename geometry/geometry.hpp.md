---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/geometry/geometry.md
    document_title: geometry
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_A
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_A
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_C
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_D
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_A
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_B
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_C
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_A
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_A
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_C
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_D
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_E
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ geometry/geometry.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief geometry\n * @docs docs/geometry/geometry.md\n */\n\n#pragma\
    \ once\n\n#include \"../base.hpp\"\n\n#pragma region Geometry\nconst double EPS=1e-8,PI=acos(-1);\n\
    inline bool EQ(double a,double b){return fabs(b-a)<EPS;}\n\nstruct Point{\n  \
    \  double x,y;\n    Point(){}\n    Point(double x,double y):x(x),y(y){}\n    Point\
    \ operator+(Point p) const {return Point{x+p.x,y+p.y};}\n    Point operator-(Point\
    \ p) const {return Point{x-p.x,y-p.y};}\n    Point operator*(double t) const {return\
    \ Point{x*t,y*t};}\n    Point operator*(Point p) const {return Point{x*p.x-y*p.y,x*p.y+y*p.x};}\n\
    \    Point operator/(double t) const {return Point{x/t,y/t};}\n    bool operator<(const\
    \ Point &p) const {\n        return x!=p.x?x<p.x:y<p.y;\n    }\n    bool operator==(const\
    \ Point &p) const {\n        return fabs(x-p.x)<EPS&&fabs(y-p.y)<EPS;\n    }\n\
    \    friend istream &operator>>(istream &is,Point &p){\n        is >> p.x >> p.y;\n\
    \        return is;\n    }\n    friend ostream &operator<<(ostream &os,Point p){\n\
    \        os << fixed << setprecision(10) << p.x << ' ' << p.y;\n        return\
    \ os;\n    }\n};\n\nstruct Line{\n    Point a,b;\n    Line(){}\n    Line(Point\
    \ a,Point b):a(a),b(b){}\n    friend istream &operator>>(istream &is,Line &l){\n\
    \        is >> l.a >> l.b;\n        return is;\n    }\n    friend ostream &operator<<(ostream\
    \ &os,Line l){\n        os << l.a << \" to \" << l.b;\n        return os;\n  \
    \  }\n};\n\nstruct Segment:Line{\n    Segment(){}\n    Segment(Point a,Point b):Line(a,b){}\n\
    };\n\nstruct Circle{\n    Point c;\n    double r;\n    Circle(){}\n    Circle(Point\
    \ c,double r):c(c),r(r){}\n    friend istream &operator>> (istream &is,Circle\
    \ &c){\n        is >> c.c >> c.r;\n        return is;\n    }\n    friend ostream\
    \ &operator<<(ostream &os,Circle &c){\n        os << c.c << ' ' << c.r;\n    \
    \    return os;\n    }\n};\n\ntypedef vector<Point> Polygon;\nistream &operator>>(istream\
    \ &is,Polygon &p){\n    for (int i=0;i<p.size();++i) is >> p[i];\n    return is;\n\
    }\n\ndouble dot(const Point &a,const Point &b){\n    return a.x*b.x+a.y*b.y;\n\
    }\ndouble cross(const Point &a,const Point &b){\n    return a.x*b.y-a.y*b.x;\n\
    }\ndouble norm(const Point &a){\n    return a.x*a.x+a.y*a.y;\n}\ndouble abs(const\
    \ Point &a){\n    return sqrt(norm(a));\n}\n\n// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_A\n\
    Point proj(const Line &l,const Point &p){\n    double t=dot(p-l.a,l.b-l.a)/norm(l.b-l.a);\n\
    \    return l.a+(l.b-l.a)*t;\n}\n// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B\n\
    Point refl(const Line &l,const Point &p){\n    return p+(proj(l,p)-p)*2.0;\n}\n\
    \nPoint rotate(const Point &p,double theta){\n    return Point(cos(theta)*p.x-sin(theta)*p.y,sin(theta)*p.x+cos(theta)*p.y);\n\
    }\ndouble arg(const Point &p){\n    return atan2(p.y,p.x);\n}\ndouble get_angle(const\
    \ Point &a,const Point &b,const Point &c){\n    const Point v=b-a,w=c-b;\n   \
    \ double alpha=arg(v),beta=arg(w);\n    if (alpha>beta) swap(alpha,beta);\n  \
    \  double theta=beta-alpha;\n    return min(theta,2*PI-theta);\n}\n\nstatic const\
    \ int COUNTER_CLOCKWISE=1;\nstatic const int CLOCKWISE=-1;\nstatic const int ONLINE_BACK=2;\n\
    static const int ONLINE_FRONT=-2;\nstatic const int ON_SEGMENT=0;\n\n// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C\n\
    int ccw(const Point &a,Point b,Point c){\n    b=b-a,c=c-a;\n    if (cross(b,c)>EPS)\
    \ return COUNTER_CLOCKWISE;\n    if (cross(b,c)<-EPS) return CLOCKWISE;\n    if\
    \ (dot(b,c)<-EPS) return ONLINE_BACK;\n    if (norm(b)<norm(c)) return ONLINE_FRONT;\n\
    \    return ON_SEGMENT;\n}\n\n// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_A\n\
    bool orthogonal(const Point &a,const Point &b){\n    return EQ(dot(a,b),0.0);\n\
    }\nbool orthogonal(const Point &a,const Point &b,const Point &c,const Point &d){\n\
    \    return orthogonal(b-a,d-c);\n}\nbool orthogonal(const Line &l,const Line\
    \ &m){\n    return EQ(dot(l.b-l.a,m.b-m.a),0.0);\n}\n// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_A\n\
    bool parallel(const Point &a,const Point &b){\n    return EQ(cross(a,b),0.0);\n\
    }\nbool parallel(const Point &a,const Point &b,const Point &c,const Point &d){\n\
    \    return parallel(b-a,d-c);\n}\nbool parallel(const Line &l,const Line &m){\n\
    \    return EQ(cross(l.b-l.a,m.b-m.a),0.0);\n}\n\nbool intersect(const Line &l,const\
    \ Point &p){\n    return abs(ccw(l.a,l.b,p))!=1;\n}\nbool intersect(const Line\
    \ &l,const Line &m){\n    return abs(cross(l.b-l.a,m.b-m.a)>EPS||abs(cross(l.b-l.a,m.b-m.a))<EPS);\n\
    }\nbool intersect(const Line &l,const Segment &s){\n    return cross(l.b-l.a,s.a-l.a)*cross(l.b-l.a,s.b-l.a)<EPS;\n\
    }\nbool intersect(const Segment &s,const Point &p){\n    return ccw(s.a,s.b,p)==0;\n\
    }\n// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B\nbool intersect(const\
    \ Segment &s,const Segment &t){\n    return ccw(s.a,s.b,t.a)*ccw(s.a,s.b,t.b)<=0&&ccw(t.a,t.b,s.a)*ccw(t.a,t.b,s.b)<=0;\n\
    }\nbool intersect(const Circle &c,const Line &l){\n    return (norm(proj(l,c.c)-c.c)-c.r*c.r)<=EPS;\n\
    }\nint intersect(const Circle &c,const Segment &s){\n    if (norm(proj(s,c.c)-c.c)-c.r*c.r>EPS)\
    \ return 0;\n    double d1=abs(c.c-s.a),d2=abs(c.c-s.b);\n    if (d1<c.r+EPS&&d2<c.r+EPS)\
    \ return 0;\n    if (d1<c.r-EPS&&d2>c.r+EPS||d1>c.r+EPS&&d2<c.r-EPS) return 1;\n\
    \    const Point h=proj(s,c.c);\n    if (dot(s.a-h,s.b-h)<0) return 2;\n    return\
    \ 0;\n}\n// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_A\n\
    int intersect(Circle c,Circle d){\n    if (c.r<d.r) swap(c,d);\n    double dist=abs(c.c-d.c);\n\
    \    if (c.r+d.r<dist) return 4;\n    if (EQ(c.r+d.r,dist)) return 3;\n    if\
    \ (c.r-d.r<dist) return 2;\n    if (EQ(c.r-d.r,dist)) return 1;\n    return 0;\n\
    }\n\ndouble distance(const Point &a,const Point &b){\n    return abs(b-a);\n}\n\
    double distance(const Line &l,const Point &p){\n    return abs(p-proj(l,p));\n\
    }\ndouble distance(const Line &l,const Line &m){\n    return intersect(l,m)?0:distance(l,m.a);\n\
    }\ndouble distance(const Segment &s,const Point &p){\n    Point h=proj(s,p);\n\
    \    return intersect(s,h)?abs(h-p):min(abs(s.a-p),abs(s.b-p));\n}\n// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_D\n\
    double distance(const Segment &s,const Segment &t){\n    if (intersect(s,t)) return\
    \ 0;\n    return min({distance(s,t.a),distance(s,t.b),distance(t,s.a),distance(t,s.b)});\n\
    }\ndouble distance(const Line &l,const Segment &s){\n    return intersect(l,s)?0:min(distance(l,s.a),distance(l,s.b));\n\
    }\n\nPoint crosspoint(const Line &l,const Line &m){\n    double d1=cross(l.b-l.a,m.b-m.a),d2=cross(l.b-l.a,l.b-m.a);\n\
    \    if (EQ(abs(d1),0.0)&&EQ(abs(d2),0.0)) return m.a;\n    return m.a+(m.b-m.a)*d2/d1;\n\
    }\n// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_C\nPoint\
    \ crosspoint(const Segment &s,const Segment &t){\n    assert(intersect(s,t));\n\
    \    return crosspoint(Line(s),Line(t));\n}\n// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_D\n\
    vector<Point> crosspoint(const Circle &c,const Line &l){\n    Point pr=proj(l,c.c);\n\
    \    Point e=(l.b-l.a)/abs(l.b-l.a);\n    if (EQ(distance(l,c.c),c.r)) return\
    \ {pr};\n    double base=sqrt(c.r*c.r-norm(pr-c.c));\n    return {pr-e*base,pr+e*base};\n\
    }\nvector<Point> crosspoint(const Circle &c,const Segment &s){\n    Line l=Line(s);\n\
    \    assert(intersect(c,l));\n    auto res=crosspoint(c,l);\n    if (intersect(c,l)==2)\
    \ return res;\n    if (dot(l.a-res[0],l.b-res[0])<0) res.emplace_back(res[0]);\n\
    \    else res.pop_back();\n    return res;\n}\n// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_E\n\
    vector<Point> crosspoint(const Circle &c,const Circle &d){\n    double dist=abs(c.c-d.c);\n\
    \    double a=acos((c.r*c.r+dist*dist-d.r*d.r)/(2*c.r*dist));\n    double t=arg(d.c-c.c);\n\
    \    Point p1=c.c+Point(cos(t+a),sin(t+a))*c.r,p2=c.c+Point(cos(t-a),sin(t-a))*c.r;\n\
    \    return {p1,p2};\n}\n\n// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_C\n\
    Circle circumcenter(Point a,Point b,const Point &c){\n    a=(a-c)*0.5;\n    b=(b-c)*0.5;\n\
    \    Point center=c+crosspoint(Line(a,a*Point{1,1}),Line{b,b*Point{1,1}});\n \
    \   return Circle{center,abs(c-center)};\n}\nvector<Point> center_given_radius(const\
    \ Point &a,const Point &b,const double &r){\n    Point m=(b-a)*0.5;\n    double\
    \ d1=abs(m);\n    vector<Point> res;\n    if (EQ(d1,0.0)||d1>r) return res;\n\
    \    double d2=sqrt(r*r-d1*d1);\n    Point n=m*Point{0.0,1.0}*d2/d1;\n    res.emplace_back(a+m+n);\n\
    \    if (d2>EPS) res.emplace_back(a+m-n);\n    return res;\n}\n\n// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_B\n\
    bool convex(const Polygon &p){\n    int n=p.size();\n    for (int i=0;i<n;++i){\n\
    \        if (ccw(p[(i+n-1)%n],p[i],p[(i+1)%n])==-1){\n            return false;\n\
    \        }\n    }\n    return true;\n}\n// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_A\n\
    Polygon convex_hull(Polygon p){\n    int n=p.size(),k=0;\n    if (n<=2) return\
    \ p;\n    sort(p.begin(),p.end());\n    Polygon ch(2*n);\n    for (int i=0;i<n;ch[k++]=p[i++]){\n\
    \        while(k>=2&&cross(ch[k-1]-ch[k-2],p[i]-ch[k-1])<0) --k;\n    }\n    for\
    \ (int i=n-2,t=k+1;i>=0;ch[k++]=p[i--]){\n        while(k>=t&&cross(ch[k-1]-ch[k-2],p[i]-ch[k-1])<0)\
    \ --k;\n    }\n    ch.resize(k-1);\n    return ch;\n}\n\n// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_A\n\
    double area(const Polygon &p){\n    int n=p.size();\n    double res=0;\n    for\
    \ (int i=0;i<n;++i) res+=cross(p[i],p[(i+1)%n]);\n    return res*0.5;\n}\n\n//\
    \ https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_C\nstatic const\
    \ int OUT=0,ON=1,IN=2;\nint contains(const Polygon &P,const Point &p){\n    int\
    \ n=P.size();\n    bool res=false;\n    for (int i=0;i<n;++i){\n        Point\
    \ a=P[i]-p,b=P[(i+1)%n]-p;\n        if (a.y>b.y) swap(a,b);\n        if (a.y<=0&&0<b.y&&cross(a,b)<0)\
    \ res=!res;\n        if (cross(a,b)==0&&dot(a,b)<=0) return ON;\n    }\n    return\
    \ res?IN:OUT;\n}\n\n#pragma endregion"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: geometry/geometry.hpp
  requiredBy: []
  timestamp: '2020-09-20 18:39:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/geometry.hpp
layout: document
redirect_from:
- /library/geometry/geometry.hpp
- /library/geometry/geometry.hpp.html
title: geometry
---
## 概要

## 計算量