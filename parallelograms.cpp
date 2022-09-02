// https://codeforces.com/problemset/problem/660/D

#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef pair<int, int> pt;

pt operator-(pt& a, pt& b){
  return pt(a.x - b.x, a.y - b.y);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n; cin >> n;
  vector<pt> pts(n);

  int xx, yy;
  for(int i=0; i<n; ++i){
    cin >> xx >> yy;
    pts[i] = pt(xx, yy);
  }
  sort(pts.begin(), pts.end());

  map<pt, int> cnt_vec;
  for(int i=0; i<n; ++i){
    for(int j=i+1; j<n; ++j){
      pt vec = pts[j] - pts[i];
      ++cnt_vec[vec];
    }
  }

  int ans = 0, cnt;
  for(auto& p: cnt_vec){
    cnt = p.second;
    ans += cnt*(cnt-1)/2;
  }
  cout << ans/2 << endl;
}