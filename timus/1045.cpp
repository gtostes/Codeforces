
/**----------------------**
** By: Gabriel Tostes    **
** Date: 08-02-2024      **
** Hour: 03:37:50 (CET)  **
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
  int n,k; cin >> n >> k; k--;
  V < vi > adj(n);

  for(int i=0; i<n-1; i++){
    int a,b; cin >> a >> b;
    a--; b--;
    adj[a].pb(b);
    adj[b].pb(a);
  }

  vi res(n,0);

  // cout << "mano" << endl;

  function < void(int,int) > dfs = [&](int u, int p){
    // cout << "here" << endl;
    for(int v: adj[u]){
      if(v == p) continue;
      dfs(v,u);
      if(res[v] == 0) res[u] = 1;
    }
  };
  // cout << "mano" << endl;
  dfs(k,-1);
  if(res[k]){
    int ap = n;
    for(int v: adj[k]) if(res[v] == 0) ap = min(ap,v);
    cout << "First player wins flying to airport " << ap+1 << endl;
  }
  else{
    cout << "First player loses" << endl;
  }
}