
/**----------------------**
** By: Gabriel Tostes    **
** Date: 07-02-2024      **
** Hour: 22:22:24 (CET)  **
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

// Em O(n)
const int N = 50000;
int lp[N+1];
vector<int> pr;

void sieve(){
	for (int i=2; i<=N; ++i) {
	    if (lp[i] == 0) {
	        lp[i] = i;
	        pr.push_back (i);
	    }
	    for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
	        lp[i * pr[j]] = pr[j];
	}
}

int ct[50000];

map < int,int > fac(int a, int b){
  map < int, int > mp;
  for(int i=2; i<=a; i++){
    int j = i;
    while(j>1){
      mp[lp[j]]+=1;
      j/=lp[j];
    }
  }
  return mp;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //freopen("input5.in", "r", stdin);
  //freopen("problemname.txt", "w", stdout);
  sieve();
  int m,n; cin >> m >> n;
  for(int i=2; i<=m; i++){
    int j = i;
    while(j>1){
      ct[lp[j]]++;
      j/=lp[j];
    }
  }
  for(int i=2; i<=n; i++){
    int j = i;
    while(j>1){
      ct[lp[j]]--;
      j/=lp[j];
    }
  }
  for(int i=2; i<=m-n; i++){
    int j = i;
    while(j>1){
      ct[lp[j]]--;
      j/=lp[j];
    }
  }
  
  int ans = 0;
  for(int i=0; i<50000; i++) ans += ct[i] > 0;
  cout << ans << endl;
}