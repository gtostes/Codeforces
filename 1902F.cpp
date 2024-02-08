/*
**----------------------**
** By: Tostes           **
** Date: DD-MM-YYYY     **
** Hour: HH:MM:SS       **
**----------------------**
*/


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


bool add_base(vl& base, ll v){
    for(ll &e: base){
        if((v^e) < v) v = (v^e);
        if(v==0) return false;
        if(v > e) swap(v,e);
    }
    base.pb(v);
    return true;
}

void merge_base(vl& base1, vl& base2){
    for(ll el: base2){
        add_base(base1,el);
        if(sz(base1)==20) break;
    }
}

bool test_base(vl& base, ll v){
    for(ll &e: base){
        if((v^e) < v) v = (v^e);
    }
    return v==0;
}

ll pai[200000][19];
V < vi > adj;
V < vi > inter;
vl a;
vi level;
int n;

int up(int u, int h){
  for(int i=0; i<20; i++) if((h>>i)&1) u = pai[u][i];
  return u;
}

bool cmp(int i, int j){
  return i>j;
}

vl lca(int u, int v){
  if(level[u] < level[v]) swap(u,v);
  int dif = level[u] - level[v];
  vl add;
  int lu = u, lv = v;
  int lc;
  for(int i=0; i<19; i++) if(dif&(1<<i)){
      lu = pai[lu][i];
  }
  if(lu == lv){
    lc = lv;
    vl base;
    each(e, inter[u]){
      if(level[e] >= level[lc]) add_base(base,a[e]);
    }
    return base;
  }
  else{
    int i=0; 
    while(pai[lu][i]!=pai[lv][i]) i++;
    i--;
    for(int j=i; j>=0; j--){
      if(pai[lu][j]!=pai[lv][j]){
          lu = pai[lu][j];
          lv = pai[lv][j];
      }
    }
    lc = pai[lu][0];
    vl base1, base2;
    
    each(e, inter[u]){
      if(level[e] >= level[lc]) add_base(base1, a[e]);
    }
    each(e, inter[v]){
      if(level[e] >= level[lc]) add_base(base2, a[e]);
    }
    // if(u==15 and v == 9) cout << base1 _ base2 _ lc+1 << endl;
    merge_base(base1,base2);
    // if(u==15 and v == 9) cout << base1 _ base2 _ lc+1 << endl;
    return base1;
  }
  
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //freopen("input5.in", "r", stdin);
  //freopen("problemname.txt", "w", stdout);
//   vl A{18,30,24,4};
//   vl bbb;
//   each(x,A) add_base(bbb,x);
//   cout << bbb << endl;
  cin >> n;
  a.resize(n);
  each(x,a) cin >> x;
  adj.resize(n);
  inter.resize(n);
  level.resize(n,0);

  for(int i=0; i<n-1; i++){
    int u,v; cin >> u >> v; u--; v--;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  function < void(int, int) > dfs = [&](int u, int p){
    vl base;
    if(a[u]!=0){
      inter[u].pb(u);
      base.pb(a[u]);
    }
    if(p!=-1){
      each(e, inter[p]){
        if(add_base(base,a[e])) inter[u].pb(e);
      }
    }
    for(int v: adj[u]){
        if (v==p) continue;
        level[v] = level[u]+1;
        pai[v][0] = u;
        dfs(v,u);
    }
  };
  dfs(0,-1);

  // for(int i=0; i<n; i++) cout << i _ inter[i] << endl;

  for(int p=1; p<19; p++){
    for(int i=0; i<n; i++){
        pai[i][p] = pai[pai[i][p-1]][p-1];
    }
  }

  int q; cin >> q;

  while(q--){
    int u,v; cin >> u >> v;
    u--; v--;
    ll k; cin >> k;
    if(k==0) cout << "YES" << endl;
    else{
        vl bs = lca(u,v);
        // if(u == 9 and v == 15) cout << bs << endl;
        if(test_base(bs,k)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
  }
}