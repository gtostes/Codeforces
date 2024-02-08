
/**----------------------**
** By: Gabriel Tostes    **
** Date: 06-02-2024      **
** Hour: 20:27:04 (CET)  **
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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //freopen("input5.in", "r", stdin);
  //freopen("problemname.txt", "w", stdout);
  int n,m; cin >> n >> m;

  V < vl > val(n, vl(m));

  V < vl > ans(n, vl(m));
  for(int i=0; i<n; i++) for(int j=0; j<m; j++) ans[i][j] = 1e15;

  each(x,val) each(y,x) cin >> y;

  set < pair<ll,pi> > mn;
  for(int j = 0; j<m; j++){
    ans[n-1][j] = val[n-1][j];
    mn.insert({ans[n-1][j],mp(n-1,j)});
  }

  while(!mn.empty()){
    auto p = *mn.begin();
    mn.erase(mn.begin());
    if(p.f > ans[p.s.f][p.s.s]) continue;
    int i = p.s.f, j = p.s.s;
    V < pi > dif{{-1,0},{0,-1},{0,1}};
    for(pi d: dif){
      if(i + d.f >=0 and i + d.f < n and j+d.s>=0 and j+d.s<m and ans[i+d.f][j+d.s] > ans[i][j] + val[i+d.f][j+d.s]){
        ans[i+d.f][j+d.s] = ans[i][j] + val[i+d.f][j+d.s];
        mn.insert({ans[i+d.f][j+d.s], mp(i+d.f,j+d.s)});
      }
    }
  }

  vi chemin;
  int i = 0;
  int j = min_element(all(ans[0])) - ans[0].begin();
  chemin.pb(j+1);

  while(i < n-1){
    // cout << "here" << endl;
    // cout << i _ j << endl;
    V < pi > dif{{1,0},{0,-1},{0,1}};
    bool ch = false;
    for(pi d: dif){
      if(ch) continue;
      if(i + d.f >=0 and i + d.f < n and j+d.s>=0 and j+d.s<m and ans[i+d.f][j+d.s] == ans[i][j] - val[i][j]){
        ch = true;
        chemin.pb(j+d.s+1);
        i+=d.f; j+=d.s;
      }
    }
  }

  each(x,chemin) cout << x << ' ';
  cout << endl;
  // cout << chemin << endl;
}