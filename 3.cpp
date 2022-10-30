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
//using cd = complex<db>;
using vi = vector<int>;
using vd = vector<db>;
using vl = vector <ll>;
using str = string;
template<class T> using V = vector<T>; 
 
//const int MOD = 1e9+7;
 
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
 
/*mt19937_64 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
uniform_int_distribution<long long> rg(1,1e18);*/

int dp[2][505][505];
int dpm[2][505][505];

int main(){
  ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
  cin.tie(nullptr);
#endif
  /*freopen("names.txt", "r", stdin);
  freopen("names.csv", "w", stdout);*/
  int n; cin >> n;
  vi a(n+1);
  for(int i=1; i<=n; i++) cin >> a[i];
  
  int ans = 0;
  for(int i=1; i<=n; i++){
  	for(int id=1; id<=n; id++){
  		for(int ch=0; ch<=i; ch++){
  			if(dp[(i-1)&1][id][ch-1]!=0) dp[i&1][id][ch] = dp[(i-1)&1][id][ch-1]+a[id];
  			if(id>=i and ch>=id-i){
  				int d = id-i;
  				dp[i&1][id][ch] = max(dp[i&1][id][ch], a[id]+dpm[(i-1)&1][id-1][ch-d]);
			}
			dpm[i&1][id][ch] = max(dpm[i&1][id-1][ch],dp[i&1][id][ch]);
			if(i==n) ans = max(ans, dp[i&1][id][ch]);
		}
	}
	for(int id=1; id<=n; id++) for(int ch=0; ch<=n; ch++) dpm[(i-1)&1][id][ch] = dp[(i-1)&1][id][ch] = 0;
  }
  
  cout << ans << endl;
}
