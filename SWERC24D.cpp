
/**----------------------**
** By: Gabriel Tostes    **
** Date: 31-01-2024      **
** Hour: 01:10:36 (CET)  **
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

ll mod = 1000000007;

ll pw(ll a, ll b){
  if(b==0) return 1;
  ll u = pw((a*a)%mod,b/2);
  if(b&1) u = (u*a) % mod;
  return u;
}

ll fac[60];

ll C[51][51][51][51];


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //freopen("input5.in", "r", stdin);
  //freopen("problemname.txt", "w", stdout);
  // cout << pw(4,mod) << endl;
  fac[0] = 1; for(int i=1; i<60; i++) fac[i] = (fac[i-1]*1ll*i) % mod;
  int n,k,t; cin >> n >> k >> t;

  for(int i=0; i<=k; i++){
    for(int a=0; a<=k; a++){
      for(int b=0; b<=k; b++){
        for(int c=0; c<=k; c++){
          if(i!=(a+b+c)) continue;
          // if(i==4 and a==2 and b==2 and c==0) cout << "here" << endl;
          C[i][a][b][c] = fac[a]*fac[b] % mod;
          C[i][a][b][c] = (C[i][a][b][c]*fac[c]) % mod;
          C[i][a][b][c] = pw(C[i][a][b][c], mod-2);
          C[i][a][b][c] = C[i][a][b][c]*fac[i] % mod;
        }
      }
    }
  }

  // cout << C[4][2][2][0] << endl;
  // return 0;

  while(t--){
    vi c(n);
    each(x,c){
      cin >> x; x--;
    }
    vi ic(n);
    for(int i=0; i<n; i++) ic[c[i]] = i;
    V < vi > p(n);
    p[0] = {0};

    for(int i=1; i<n; i++){
      p[i] = p[i-1]; p[i].pb(0);
      for(int j=0; j<i; j++){
        if(ic[j] < ic[i]) p[i][i]++;
        else p[i][j]++;
      }
    }

    V < vl > dp(n,vl(k+1,0));
    dp[0][0] = 1;

    for(int i=1; i<n; i++){
      for(int j=0; j<=k; j++){
        for(int r=0; r<=j; r++){
          if(!dp[i-1][r]) continue;
          int ss = j - r, dd = i - p[i][i];
          if(ss+dd>=0 and ss-dd>=0 and (ss-dd)%2 == 0){
            // cout << i _ j _ r << endl;
            int e = (ss+dd)/2, d = (ss-dd)/2;
            dp[i][j] = (dp[i][j] + dp[i-1][r]*C[j][r][e][d]) % mod;
          }
        }
        cout << dp[i][j] _ mp(i,j) << endl;
      }
    }

    cout << dp[n-1][k] << endl;
  }
}