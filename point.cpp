#include <bits/stdc++.h>

using namespace std;

typedef long double T;

struct pt{
  T x, y;

  pt(){}
  pt(T x, T y):x(x), y(y){}

  bool operator<(pt p) const{ return x == p.x ? y < p.y : x < p.x;}

  pt operator+(pt p){ return pt(x + p.x, y + p.y);}
  pt operator-(pt p){ return pt(x - p.x, y - p.y);}

  pt operator*(T t){ return pt(t * x, t * y);}
  pt operator/(T t){ return pt(x/t, y/t);}


};


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  pt a, b;
  int x, y;
  cin >> x >> y;
  a = pt(x, y);
  map<pt, int> cnt;
  cnt[a]++;
}