
/**----------------------**
** By: Gabriel Tostes    **
** Date: 06-02-2024      **
** Hour: 02:03:28 (CET)  **
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

int fd(vi a){
  // cout << a << endl;
  int n =sz(a);
  for(int i=0; i<n; i++) a.pb(a[i]);
  int at = 0;

  int val = n;

  for(int i=0; i<2*n; i++){
    if(!i) at = 1;
    else{
      if(a[i]>=a[i-1]) at++;
      else at = 1;
    }
    if(at > n) at = n;
    if(at == n and i>=n) val = min(val,2*n - 1 - i);
  } 

  return val;
}

int dif(vi a){
  sort(all(a));
  int ct = 0;
  for(int i=1; i<sz(a); i++) ct += a[i]!=a[i-1];
  return ct;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //freopen("input5.in", "r", stdin);
  //freopen("problemname.txt", "w", stdout);

  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    vi a(n);
    each(x,a) cin >> x;
    int df = dif(a);
    if(df == 0){
      cout << 0 << endl;
      continue;
    }
    if(df == 1){
      cout << "HERE" << endl;
      int u = fd(a);
      cout << "U" _ u << endl;
      if(u == n) cout << -1 << endl;
      else{
        cout << min(u,n-u+1) << endl;
      }
      continue;
    }
    int ans = 1e6;
    int u = fd(a); 
    // cout << u << endl;
    if(u!=n) ans = min(ans,u);
    reverse(all(a));
    u = fd(a);
    // cout << u << endl;
    if(u!=n) ans = min(ans,u+1);

    if(ans < 1e6) cout << ans << endl;
    else cout << -1 << endl;
  }
}

// 2 2 1 1 2

// 2 1 1 2 2