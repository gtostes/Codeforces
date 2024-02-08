
/**----------------------**
** By: Gabriel Tostes    **
** Date: 05-02-2024      **
** Hour: 21:49:44 (CET)  **
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

V < V < pi > > adj;
V < vl > dp;
vl tam;

void dfs(int u, int p){
  V<pi> child;
  tam[u] = 1;
  for(pi v: adj[u]) if(v.f!=p){
    child.pb(v);
    dfs(v.f,u);
    tam[u] += tam[v.f];
  }
  dp[u][0] = 0;
  if(child.empty()) return;
  pi L = child[0], R = child[1];
  // cout << u _ L _ R << endl;
  // dp[u][0] = 0;
  for(int j=0; j<tam[u]; j++) for(int k=0; k<=j; k++){
    dp[u][j] = min(dp[L.f][j-k] + dp[R.f][k], dp[u][j]);
  }

  // if(u==2) cout << "u" _ dp[u] << endl;
  for(int j=0; j<tam[R.f]; j++) dp[u][j + tam[L.f]] = min(dp[u][j + tam[L.f]], dp[L.f][tam[L.f]-1] + L.s + dp[R.f][j]);
  // if(u==2) cout << dp[L.f][0] _ tam[L.f]-1 << endl;

  for(int j=0; j<tam[L.f]; j++) dp[u][j + tam[R.f]] = min(dp[u][j + tam[R.f]], dp[R.f][tam[R.f]-1] + R.s + dp[L.f][j]);

  dp[u][tam[L.f]+tam[R.f]] = dp[L.f][tam[L.f]-1] + L.s  + dp[R.f][tam[R.f]-1] + R.s;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //freopen("input5.in", "r", stdin);
  //freopen("problemname.txt", "w", stdout);

  int n,q; cin >> n >> q;
  adj.resize(n);
  tam.resize(n);
  // deg.resize(n,0);

  dp.resize(n); for(int i=0; i<n; i++) dp[i].resize(n,30000000);

  ll sm = 0;
  for(int i=0; i<n-1; i++){
    int a,b; ll v; cin >> a >> b >> v; a--; b--;
    adj[a].pb({b,v});
    adj[b].pb({a,v});
    sm += v;
  }

  dfs(0,-1);
  cout << sm - dp[0][n-1-q] << endl;
  // cout << dp[0] << endl;
}