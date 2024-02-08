
/**----------------------**
** By: Gabriel Tostes    **
** Date: 05-02-2024      **
** Hour: 17:43:36 (CET)  **
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

ll nb[50];

ll pos(vi u){
  int n = sz(u);
  if(n==0){
    return 0;
  }
  if(n==1) return u[0];

  if(u[n-1] == 1){
    if(sz(u) < 2) return 1;
    u.pop_back(); u.pop_back();
    return nb[n-1] + pos(u);
  }
  else{
    // cout << "here" << endl;
    u.pop_back();
    return pos(u);
  }
}

void fill(vi &v, int j){
  int n = sz(v);
  int at = 1;
  if(j+1 < n and v[j+1] == 1) at = 0;
  for(int i = j; i>=0; i--){
    v[i] = at; 
    at = 1 - at;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //freopen("input5.in", "r", stdin);
  //freopen("problemname.txt", "w", stdout);

  int n,k; cin >> n >> k; k--;
  nb[0] = 1;
  nb[1] = 2;
  for(int i=2; i<44; i++) nb[i] = nb[i-1] + nb[i-2];
  if(nb[n]<k+1){
    cout << -1 << endl;
    return 0;
  }
  vi v(n);

  for(int i = n-1; i>=0; i--){
    v[i] = 0; fill(v,i-1);
    if(pos(v)<k) fill(v,i);
  }
  reverse(all(v));
  each(x,v) cout << x;
  cout << endl;
}

// 0 1 1 1 1
// 0 1 1 0 1
// 0 1 1 1 0
// 0 1 0 1 0
// 0 1 0 1 1