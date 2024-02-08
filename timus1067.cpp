
/**----------------------**
** By: Gabriel Tostes    **
** Date: 07-02-2024      **
** Hour: 02:19:26 (CET)  **
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

V < string > split(string u){
  V < string > ans;
  string s = "";
  u+=char(92);
  each(x,u){
    if(int(x) == 92){
      ans.pb(s);
      s = "";
      continue;
    }
    s+=x;
  }
  return ans;
}

void pesp(int esp){
  for(int i=0; i<esp; i++) cout << ' ';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //freopen("input5.in", "r", stdin);
  //freopen("problemname.txt", "w", stdout);

  // cout << char(92) << endl;

  int n; cin >> n;
  // string s; cin >> s;
  // each(x,s) cout << int(x) << ' ';
  // cout << endl;
  // return 0;
  map < int, map<string,int> > adj;
  map < int, string > knames;
  knames[0] = "";
  int nb = 1;

  for(int i=0; i<n; i++){
    int at = 0;
    string s; cin >> s;
    auto ch = split(s);

    for(string &u: ch){
      if(adj[at].find(u) == adj[at].end()){
        adj[at][u] = nb;
        knames[nb] = u;
        at = nb;
        nb++;
      }
      else{
        at = adj[at][u];
      }
    }
  }

  // each(x,adj){
  //   each(y,x.s){
  //     cout << knames[x.f] _ knames[y.s] << endl;
  //   }
  // }

  function < void(int, int) > putmap = [&](int u, int esp){
    if(u!=0){ pesp(esp); cout << knames[u] << endl;}
    auto &mp = adj[u];
    each(x,mp) putmap(x.s,esp+1);
  };

  putmap(0,-1);
}