
/**----------------------**
** By: Gabriel Tostes    **
** Date: 08-02-2024      **
** Hour: 03:15:02 (CET)  **
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

ll toint(string s){
  ll val = 0;
  each(x,s){
    val = 10*val + (x-'0');
  }
  return val;
}

ll split(string s){
  string u = "";
  ll ans = 0;
  each(x,s){
    if( x == '.'){
      ans = 256*ans + toint(u);
      // ans.pb(toint(u));
      u = "";
    }
    else{
      u += x;
    }
  }
  ans = 256*ans + toint(u);
  // ans.pb(toint(u));
  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //freopen("input5.in", "r", stdin);
  //freopen("problemname.txt", "w", stdout);
  int n; cin >> n;
  V < V < ll > > per(n);
  V < vi > adj(n);

  for(int i=0; i<n; i++){
    int k; cin >> k;
    for(int j=0; j<k; j++){
      string a,b; cin >> a >> b;
      ll va = split(a), vb = split(b);
      per[i].pb(va&vb);
    }
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if( j == i) continue;
      bool exs = false;
      each(x,per[i]) each(y,per[j]) if(x == y) exs = true;
      if(exs){
        adj[i].pb(j);
        adj[j].pb(i);
      }
    }
  }
  
  int a,b; cin >> a >> b; a--; b--;
  vi dist(n,100);
  queue < int > que; que.push(a);
  dist[a] = 0;
  while(!que.empty()){
    int u = que.front(); que.pop();
    for(int v: adj[u]){
      if(dist[v] > dist[u]+1){
        dist[v] = dist[u]+1;
        que.push(v);
      }
    }
  }

  if(dist[b]<100){
    cout << "Yes" << endl;
    vi chemin;
    int u = b;
    while(1){
      chemin.pb(u+1);
      if(u==a) break;
      int nu;
      for(int v: adj[u]){
        if(dist[v] == dist[u]-1) nu = v;
      }
      u = nu;
    }
    reverse(all(chemin));
    each(x,chemin) cout << x << ' ';
    cout << endl;
  }
  else{
    cout << "No" << endl;
  }
}