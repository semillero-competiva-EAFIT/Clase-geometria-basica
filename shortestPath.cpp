// https://codeforces.com/problemset/gymProblem/101972/C?f0a28=2&locale=en

#include <bits/stdc++.h>

#define el '\n'
#define sz(v) v.size()
#define pb push_back

using namespace std;

typedef long double ld;

struct pt{
  ld x, y;
  pt(){}
  pt(ld x, ld y):x(x), y(y){}

  ld norm2(){return (*this) * (*this);}  // norm2 = x^2 + y^2
  ld norm(){return sqrt(norm2());} // norm = sqrt(x^2 + y^2)

  ld operator*(pt p){return x*p.x + y*p.y;}

  pt operator+(pt p){return pt(x+p.x, y+p.y);}
  pt operator-(pt p){return pt(x-p.x, y-p.y);}
  pt operator*(ld t){return pt(x*t, y*t);}
};
int a, b, c, x;
const ld eps = 1e-9;

ld calc(pt p, pt q){
  int x = b+c;
  ld l = min(p.y, q.y), r = max(p.y, q.y);

  while(l+eps < r){
    ld m1 = l + (r-l)/3,
      m2 = l + 2*(r-l)/3;
    pt p1(x, m1), p2(x, m2);
    ld d1 = (p-p1).norm() + (q-p1).norm(),
      d2 = (p-p2).norm() + (q-p2).norm();
    if(d1 > d2){
      l = m1;
    } else{
      r = m2;
    }
  }
  pt pp(x, (l+r)/2);
  return (p-pp).norm() + (q-pp).norm();
}

ld solve(pt o, pt c, pt m){
  return calc(c, o) + (m-o).norm() + calc(m, c);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout << setprecision(15) << fixed;
  int t; cin >>t;
  while(t--){
    cin >> a >> b >> c >> x;
    pt o(0,0), h(b, a);
    pt dir = h-o;
    pt m = o + dir*(x/100.0);
    cout << solve(o, h, m) << el;
  }
}