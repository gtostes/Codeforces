
/**----------------------**
** By: Gabriel Tostes    **
** Date: 08-02-2024      **
** Hour: 01:33:14 (CET)  **
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
  int t; cin >> t;
  map < int, int > color;
  color[0] = 1;
  color[1e9] = 0;
  while(t--){
    int a,b; string s; cin >> a >> b >> s;
    int c = s[0] == 'w';
    int bc = prev(color.upper_bound(b))->s;
    color[a] = c;
    color[b] = bc;

    auto p = color.upper_bound(a);
    while(p->f != b){
      auto q = p;
      p = next(p);
      color.erase(q);
    }

  }
  ll ans = 0;
  ll ie = -1;

  auto p = next(color.begin());
  ll at = 0;
  while(p!=color.end()){
    if(prev(p)->s == 0){
      at = 0;
      // ib = -1;
    }
    else{
      at += (p->f) - (prev(p)->f);
    }
    // p = next(p);
    if(at > ans){
      ans = at;
      ie = p->f;
    }
    // p = next(p);
    // cout << (*p) _ ans << endl;
    p = next(p);
  }

  cout << (ie - ans) _ ie << endl;
  // each(x,color) cout << x << ' ';
  // cout << endl;
}