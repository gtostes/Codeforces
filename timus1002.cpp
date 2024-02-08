
/**----------------------**
** By: Gabriel Tostes    **
** Date: 05-02-2024      **
** Hour: 15:50:04 (CET)  **
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

void translate(string &s){
  each(x,s){
    if(x == 'i' or x =='j') x = '1';
    if(x == 'a' or x == 'b' or x == 'c') x = '2';
    if(x == 'd' or x == 'e' or x == 'f') x = '3';
    if(x == 'g' or x =='h') x = '4';
    if(x == 'k' or x =='l') x = '5';
    if(x == 'm' or x =='n') x = '6';
    if(x == 'p' or x == 'r' or x == 's') x = '7';
    if(x == 't' or x == 'u' or x == 'v') x = '8';
    if(x == 'w' or x == 'x' or x == 'y') x = '9';
    if(x == 'o' or x == 'w' or x == 'z') x = '0';
  }
}

bool check(string &s, string &x, int i){
  int n = sz(x);
  for(int j = 0; j<n; j++) if(x[j]!=s[j-n+1+i]) return false;
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //freopen("input5.in", "r", stdin);
  //freopen("problemname.txt", "w", stdout);
  string s;
  while(cin >> s){
    if(s[0] == '-') break;
    // cout << "s" _ s << endl;
    int n; cin >> n;
    // cout << n << endl;
    V < string > words(n);
    each(x,words){
      cin >> x;
      // cout << x << endl;
    }
    // cout << "here" << endl;
    auto swords = words;
    each(x,words) translate(x);
    V < pi > ans(sz(s),{sz(s)+1,-1});

    for(int i=0; i<sz(s); i++){
      for(int j=0; j<n; j++){
        auto &x = words[j];
        if(sz(x)<=i and ans[i].f > ans[i-sz(x)].f + 1 and check(s,x,i)) ans[i] = mp(ans[i-sz(x)].f + 1, j);
        if(sz(x)==i+1 and check(s,x,i)) ans[i] = {1,j};
      }
    }

    if(ans[sz(s)-1].f == sz(s)+1) cout << "No solution." << endl;
    else{
      V < string > elem;
      int j = sz(s)-1;
      while(j>=0){
        // cout << "mano" << endl;
        elem.pb(swords[ans[j].s]);
        j -= sz(words[ans[j].s]);
      }
      reverse(all(elem));
      each(x,elem) cout << x << ' ';
      cout << endl;
    }
    // cout << ans[sz(s)-1] << endl;
    // each(x,elem) cout << x << endl;
  }
}