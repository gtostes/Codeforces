
/**----------------------**
** By: Gabriel Tostes    **
** Date: 05-02-2024      **
** Hour: 16:36:23 (CET)  **
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

ll ans = 0;

ll vis[40][40];

void dfs(int a, int b, V < string > &gr){
  int n = sz(gr);
  if(a<0 or a>=n) return;
  if(b<0 or b>=n) return;
  if(gr[a][b] == '#') return;
  if(vis[a][b]) return;
  vis[a][b] = 1;
  // int n = sz(gr);
  // if(a==15) cout << a _ b _ ans << endl;
  if(a==n-1 or gr[a+1][b] == '#') ans++;
  if(a==0 or gr[a-1][b] == '#') ans++;
  if(b==0 or gr[a][b-1] == '#') ans++;
  if(b==n-1 or gr[a][b+1] == '#') ans++;
  // if(a==0 and b==2 ) cout << "ans" _ ans << endl;
  // if(a==15) cout << a _ b _ ans << endl;
  // cout << a _ b _ ans << endl;
  // for(int i=-1; i<=1; i++) for(int j=-1; j<=1; j++) if(i!=0 or j!=0) dfs(a+i,b+j,gr);
  dfs(a-1,b,gr); dfs(a+1,b,gr); dfs(a,b-1,gr); dfs(a,b+1,gr);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //freopen("input5.in", "r", stdin);
  //freopen("problemname.txt", "w", stdout);
  int n; cin >> n;
  V < string > gr(n); each(x,gr) cin >> x;
  dfs(0,0,gr);
  dfs(n-1,n-1,gr);
  cout << (ans-4)*9 << endl;
}