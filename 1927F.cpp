
/**----------------------**
** By: Gabriel Tostes    **
** Date: 07-02-2024      **
** Hour: 05:29:04 (CET)  **
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

class DSU{
	private:
	vector<ll>p,r;
	public:
	DSU(int n){
		p.resize(n); r.resize(n,0);
		iota(all(p),0);
	}
	int find(int u){
		if(p[u]==u) return u;
		else{
			p[u] = find(p[u]);
			return p[u];
		}
	}
	bool join(int i, int j){
		long long x=find(i), y=find(j);
		if(x==y) return false;
		if(r[x]>r[y]){
			p[y]=x;
		}
		else{
			p[x]=y;
			if(r[x]==r[y]) r[y]++;
		}
		return true;
	}
};


void solve(){
  int n,m; cin >> n >> m;
  V < array<int,3> > arr(m);
  for(int i=0; i<m; i++){
    cin >> arr[i][1] >> arr[i][2] >> arr[i][0];
    arr[i][1]--; arr[i][2]--;
    arr[i][0] = -arr[i][0];
  }

  DSU d(n);

  sort(all(arr));
  int l = 0;
  for(int i=0; i<m; i++){
    int a = arr[i][1], b = arr[i][2];
    if(d.find(a) == d.find(b)){
      l = i;
    }
    else{
      d.join(a,b);
    }
  }

  int a = arr[l][1], b = arr[l][2];
  vi dist(n,n);
  queue < pi > que;
  V < vi > adj(n);

  for(int i=0; i<l; i++){
    int x = arr[i][1], y = arr[i][2];
    adj[x].pb(y);
    adj[y].pb(x);
  }

  que.push({a,0}); dist[a] = 0;
  while(!que.empty()){
    pi p = que.front(); que.pop();
    if(p.s > dist[p.f]) continue;
    for(int v: adj[p.f]){
      if(dist[v] > dist[p.f]+1){
        dist[v] = dist[p.f] + 1;
        que.push({v,dist[v]});
      }
    }
  }

  // cout << dist << endl;
  // // return;
  // cout << "ab" _ a _ b _ "l" _ l << endl;
  // return;
  // cout << "b" _ dist[b] << endl;
  vi che;
  while(b!=a){
    // cout << b _ "b" << endl;
    che.pb(b+1);
    bool stp = false;
    int nb;
    for(int v: adj[b]){
      // cout << dist[v] _ dist[b] << endl;
      if(stp) continue;
      if(dist[v] == dist[b] - 1){
        stp = true;
        nb = v;
      }
    }
    b = nb;
  }
  che.pb(a+1);
  cout << -arr[l][0] _ sz(che) << endl;
  each(x,che) cout << x << ' ';
  cout << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //freopen("input5.in", "r", stdin);
  //freopen("problemname.txt", "w", stdout);

  int t; cin >> t;
  while(t--) solve();
}