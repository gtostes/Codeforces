
/**----------------------**
** By: Gabriel Tostes    **
** Date: 07-02-2024      **
** Hour: 02:51:18 (CET)  **
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

string change(string u, int n){ 
  string v = "";
  int sm = 0;
  for(int i=0; i<sz(u); i++) sm+=(i+1)*(u[i] == '1');

  if((sm%(n+1)) == 0 and sz(u)==n) return u;

  if(sz(u)>n){
    // cout << "here" _ sm << endl;
    int ct = 0;
    for(int i = sz(u)-1; i>=0; i--){
      int val = sm - (i+1)*(u[i] == '1') - ct;
      // cout << i _ val << endl;
      ct += (u[i] == '1');
      if(val%(n+1) == 0){
        for(int j = 0; j<sz(u); j++){
          if(j==i) continue;
          v+=u[j];
        }
        return v;
      }
    }
  }
  else if(sz(u)==n){
    for(int i=0; i<n; i++){
      int val = sm - (i+1)*( (u[i] == '1') - (u[i] == '0'));
      if(val%(n+1) == 0){
        if(u[i] == '1') u[i] = '0';
        else u[i] = '1';
        return u;
      }
    }
  }
  else{
    if(sm%(n+1) == 0){
      u+='0';
      return u;
    }
    if((sm+n-1)%(n+1) == 0){
      u+='1';
      return u;
    }
    int ct = 0;
    for(int i=sz(u)-1; i>=0; i--){
      ct += (u[i] == '1');
      int val = sm + ct;
      if(val%(n+1) == 0){
        for(int j=0; j<sz(u); j++){
          if(j==i) v += '0';
          v += u[j];
        }
        return v;
      }
      if((val+i+1)%(n+1) == 0){
        for(int j=0; j<sz(u); j++){
          if(j==i) v += '1';
          v += u[j];
        }
        return v;
      }
    }
  }

  return "";
}

// 0110011

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //freopen("input5.in", "r", stdin);
  //freopen("problemname.txt", "w", stdout);

  // cout << change("11011",4) << endl;
  // return 0;

  // cout << change("1000011", 8) << endl;

  // auto m = change("1000011", 8);
  // int ss = 0; for(int i=0; i<sz(m); i++) ss += (i+1)*(m[i] == '1');
  // cout << ss << endl;

  int n; cin >> n;
  V < string > words(n);
  int mn = 1000, mx = 0;
  each(x,words){
    cin >> x;
    mn = min(mn,sz(x));
    mx = max(mx,sz(x));
  }
  if(mx - mn == 2){
    mx = mn + 1;
    mn = mx;
  }
  else if(mx - mn == 0){
    mn--; mx++;
  }
  cout << mn _ mx << endl;
  for(int i=mn; i<=mx; i++){
    V < string > A;
    bool a = true;
    each(x,words){
      string s = change(x,i);
      A.pb(s);
      // cout << s _ sz(s) << endl;
      if(sz(s)!=i) a = false;
    }
    // cout << a << endl;
    if(a){
      each(x,A) cout << x << endl;
      return 0;
    }
  }
}