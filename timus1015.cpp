
/**----------------------**
** By: Gabriel Tostes    **
** Date: 07-02-2024      **
** Hour: 22:32:33 (CET)  **
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

// A B C D

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


V < vi > neigh(vi a){
  V < vi > ans;
  ans.pb({a[0],a[1],a[5],a[2],a[3],a[4]});
  ans.pb({a[5],a[3],a[2],a[0],a[4],a[1]});
  ans.pb({a[2],a[4],a[1],a[3],a[0],a[5]});

  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //freopen("input5.in", "r", stdin);
  //freopen("problemname.txt", "w", stdout);
  int n; cin >> n;
  V < vi > a(n, vi(6));

  map < vi, int > mp;

  vi seq{1,2,3,4,5,6};
  DSU uf(720);

  int at = 0;
  do{
    mp[seq] = at++;
  }while(next_permutation(all(seq)));

  at = 0;
  do{
    auto vis = neigh(seq);
    for(int i=0; i<3; i++) uf.join(at,mp[vis[i]]);
    at++;
  }while(next_permutation(all(seq)));
  // return 0;

  // cout << "mano" << endl;
  V < vi > which(720);
  vi foi(720,0);
  int ct = 0;

  for(int i=0;i<n; i++){
    auto &x = a[i];
    each(y,x){
      cin >> y;
    }
    // cout << "i" _ mp[x] << endl;
    int j = uf.find(mp[x]);
    which[j].pb(i);
    if(sz(which[j]) == 1) ct++;
  }

  cout << ct << endl;

  for(int i=0; i<n; i++){
    int j = uf.find(mp[a[i]]);
    if(!foi[j]){
      foi[j] = 1;
      each(x,which[j]) cout << x+1 << ' ';
      cout << endl;
    }
  }
}

// (3, 6, 4, 1, 2, 5)
// (3, 6, 4, 5, 2, 1)
// (4, 2, 6, 1, 3, 5)