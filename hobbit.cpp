// https://codeforces.com/problemset/problem/1468/G
#include <bits/stdc++.h>

#define el '\n'

using namespace std;

typedef long double ld;
const ld eps = 1e-8, pi = acos(-1);

struct pt{
  ld x, y;
  pt(){}
  pt(ld x, ld y): x(x), y(y){}

  ld norm2(){return *this**this;}
  ld norm(){return sqrt(norm2());}
  
  pt operator+(pt p){return pt(x+p.x, y+p.y);}
  pt operator-(pt p){return pt(x-p.x, y-p.y);}
  pt operator*(ld t){return pt(t*x, t*y);}
  pt operator/(ld t){return pt(t/x, t/y);}
  
  ld operator*(pt p){return x*p.x + y*p.y;} // dot
  ld operator%(pt p){return x*p.y - y*p.x;} // cross

  pt unit(){return *this/norm();}                                      
};

const pt pinf(1e18, 1e18);

struct ln{
  pt p, pq;
  ln(){}
  ln(pt p, pt q):p(p), pq(q-p){}
  
  bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<=eps;}
  pt operator^(ln l){
    if(*this/l) return pinf;
    pt r = l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
    return r;
  }
};

//  > 0: C left of AB 
// == 0: C on AB 
//  < 0: C right of AB
inline ld orient(pt a, pt b, pt c){
  return (b-a) % (c-a);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout << setprecision(20) << fixed; 

  int n, h; cin >> n >>h;
  vector<pt> p(n);
  for(int i=0; i<n; ++i) {
    int xx, yy; cin >> xx >> yy;
    p[i] = pt(xx, yy);
  }

  int i = n-1; 
  ld ans = 0;
  pt top = p.back(), 
    eye = pt(p.back().x, p.back().y+h); 
  while(i > 0){
    if(orient(eye, top, p[i-1]) > 0) {  // P[i-1] esta a la izq (tapado)
      --i;
      continue;
    } 
    
    if(orient(eye, top, p[i])==0 && orient(eye, top, p[i-1])==0){  // el segmento es paralelo a la proj.
      ans += (p[i] - p[i-1]).norm();
      --i; continue;
    }

    ln l(eye, top), seg(p[i], p[i-1]);
    pt cut = l^seg;
    ans += (cut-p[i-1]).norm();

    top = p[i-1];
    --i;
  }
  cout << ans << el;
}