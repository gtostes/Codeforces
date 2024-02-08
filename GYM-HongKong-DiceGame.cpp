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

ll mod = 998244353;

map < pl, pl > seg_seen;

pl seg(ll l, ll r){
    if(l>r) return pl{0,0};
    if(l==0 and r==0) return pl{0,0};
    if(seg_seen.find({l,r})!=seg_seen.end()) return seg_seen[{l,r}];
    ll max_bit = 31 - __builtin_clz(r);
    ll max_pot = 1 << max_bit;
    seg_seen[{l,r}] = pl{0,0};
    cout << pl{l,r} << endl;
    seg(l,max_pot-1);
    seg(0,r-max_pot);
    return pl{1,1};
}

void solve(){
    seg_seen.clear();
    ll n; cin >> n;
    vl c(30,0);
    ll p = 2;
    for(int i=0; i<30; i++){
        c[i] += (n/p)*(p/2);
        if(n%p >= p/2) c[i] += (n%p) - (p/2) + 1;
        p = 2*p;
    }
};


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //freopen("input5.in", "r", stdin);
  //freopen("problemname.txt", "w", stdout);
  seg(9313,194919);
  int t;
  cin >> t;
  while(t--) solve();
}