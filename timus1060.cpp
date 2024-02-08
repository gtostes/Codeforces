
/**----------------------**
** By: Gabriel Tostes    **
** Date: 06-02-2024      **
** Hour: 21:56:30 (CET)  **
**-----------------------*/

#include<bits/stdc++.h>
using namespace std;
 
#define _ << ' ' <<
#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)
#define mp make_pair
#define f first
#define s second
#define sz(x) int((x).size())
#define each(x,A) for(auto &x: A)
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
using ll = long long;
using db = long double;
using pl = pair<ll,ll>;
using pi = pair<int,int>;
using cd = complex<db>;
using vi = vector<int>;
using vpi = vector<pi>;
using vd = vector<db>;
using vl = vector <ll>;
using str = string;
template<class T> using V = vector<T>; 
 
//const int MOD = 1e9+7;
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '('; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << ')'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
 
template<typename T > ostream& operator<<(ostream &os, const set<T> &st){os << '{'; string sep; for(const auto &x: st) os << sep << x, sep = ", "; return os << '}';}
template<typename A, typename B> ostream& operator<<(ostream &os, const map<A,B> &mm){os << '{'; string sep; for(const auto &x: mm) os << sep << x, sep = ", "; return os << '}';}
 
//mt19937_64 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
//uniform_int_distribution<long long> rg(1,1e9);

int val(V < string > &a){
  int at = 1;
  int ans = 0;
  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++){
      ans += at*(a[i][j] == 'w');
      at*=2;
    }
  }
  return ans;
}

V < string > vali(int u){
  V < string > a(4);
  for(int i=0; i<4; i++){
    string s;
    for(int j=0; j<4; j++){
      if(u&1) s+='w';
      else s+='b';
      u/=2;
    }
    a[i] = s;
  }
  return a;
}

int mx = 65535;

int invert(V < string > a, int i, int j){
  V < pi > dif({{-1,0},{1,0},{0,-1},{0,1}});

  if(a[i][j] == 'w') a[i][j] = 'b';
  else a[i][j] = 'w';

  for(pi p: dif){
    if(i+p.f>=0 and i+p.f<4 and j+p.s>=0 and j+p.s<4){
      if(a[i+p.f][j+p.s] == 'w') a[i+p.f][j+p.s] = 'b';
      else a[i+p.f][j+p.s] = 'w';
    }
  }

  return val(a);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //freopen("input5.in", "r", stdin);
  //freopen("problemname.txt", "w", stdout);

  // cout << vali(1) << endl;
  V < string > a(4);
  each(x,a) cin >> x;

  int ini = val(a);
  V < int > dist(mx+1,mx+1);
  dist[ini] = 0;
  queue < int > que; que.push(ini);

  while(!que.empty()){
    int i = que.front(); que.pop();
    auto a = vali(i);
    for(int j=0; j<4; j++){
      for(int k=0; k<4; k++){
        int ivv = invert(a, j, k);
        if(dist[ivv] == mx + 1){
          dist[ivv] = dist[i] + 1;
          que.push(ivv);
        }
      }
    }
  }

  // cout << dist[0] _ dist[mx] << endl;
  int mn = min(dist[0],dist[mx]);
  if(mn == mx+1) cout << "Impossible" << endl;
  else cout << mn << endl;
  // cout << ini _ mx << endl;
}