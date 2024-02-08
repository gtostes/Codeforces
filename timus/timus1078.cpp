
/**----------------------**
** By: Gabriel Tostes    **
** Date: 06-02-2024      **
** Hour: 20:50:39 (CET)  **
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
  int n; cin >> n;
  V < vi > adj(n);
  V < pi > seg(n); each(x,seg) cin >> x.f >> x.s;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(j==i) continue;
      if(seg[i].f<seg[j].f and seg[j].s<seg[i].s) adj[i].pb(j);
    }
  }

  vi vis(n, 0);

  function < void(int) > dfs = [&](int v){
    if(vis[v]) return;
    vis[v] = 1;
    for(int u: adj[v]){
      dfs(u);
      vis[v] = max(vis[v],vis[u]+1);
    }
  };

  int ans = 0;
  int id;
  for(int i=0; i<n; i++){
    if(!vis[i]){
      dfs(i); 
      if(vis[i] > ans){
        ans = vis[i];
        id = i;
      }
    }
  }

  vi seq;

  while(1){
    seq.pb(id+1);
    if(vis[id]==1) break;
    bool ch = false;
    for(int v: adj[id]){
      if(ch) continue;
      if(vis[v] == vis[id]-1){
        id = v;
        ch = true;
      }
    }
  }

  reverse(all(seq));
  cout << ans << endl;
  for(int v: seq) cout << v << ' ';
  cout << endl;

  // cout << ans << endl << seq << endl;
}