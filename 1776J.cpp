
/**----------------------**
** By: Gabriel Tostes    **
** Date: 29-01-2024      **
** Hour: 23:04:06 (CET)  **
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

  int n,m,K; cin >> n >> m >> K;
  vi c(n);
  each(x,c) cin >> x;

  V < vi > dist(2*n, vi(2*n,1e9));

  for(int i=0; i<2*n; i++) dist[i][i] = 0;

  // V < pi > arestas;
  for(int i=0; i<m; i++){
    int a,b; cin >> a >> b; a--; b--;
    // arestas.pb({a,b});
    if(c[a]==c[b]){
      dist[a][b] = 1;
      dist[b][a] = 1;

      dist[a+n][b+n] = 1;
      dist[b+n][a+n] = 1;
    }
    else{
      dist[a][b+n] = 1;
      dist[b+n][a] = 1;

      dist[a+n][b] = 1;
      dist[b][a+n] = 1;
    }
  }

  F0R(k,2*n) F0R(i,2*n) F0R(j,2*n) if(dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j];

  int ans = 0;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      int e = dist[i][j];
      int o = dist[i][j+n];
      // cout << i _ j _ e _ o << endl;
      int dd = min(e,o+K);
      for(int l=0; l<K; l++) dd = max(dd, min(e+K-l,o+l));
      ans = max(ans,dd);
      // cout << i _ j _ e _ o _ ans << endl;
    }
  }

  cout << ans << endl;
}