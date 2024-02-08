
/**----------------------**
** By: Gabriel Tostes    **
** Date: 06-02-2024      **
** Hour: 21:09:17 (CET)  **
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

int spacein(string s){
  int n = sz(s);
  for(int i=1; i<n-1; i++) if(s[i] == ' ' and s[i-1]!=' ' and s[i+1]!=' ') return i;
  return 0;
}

pair<string,string> split(string s){
  string a,b;
  int n = sz(s);
  int j = spacein(s);
  for(int k = 0; k<j; k++) a+=s[k];
  for(int k=j+1; k<n; k++) b+=s[k];
  return mp(a,b);
}

int strtoint(string s){
  // reverse(all(s));
  int ans = 0;
  int n = sz(s);
  for(int i=0; i<n; i++) ans = 10*ans + (s[i]-'0');
  return ans;
}

V < pi > neig(pi p, string s){
  V < pi > ans;
  each(x,s){
    if(x == 'R') ans.pb(mp(p.f+1,p.s));
    if(x == 'T') ans.pb(mp(p.f,p.s+1));
    if(x == 'L') ans.pb(mp(p.f-1,p.s));
    if(x == 'B') ans.pb(mp(p.f,p.s-1));
  }

  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //freopen("input5.in", "r", stdin);
  //freopen("problemname.txt", "w", stdout);

  V < string > lines;
  string s;
  while(getline(cin,s)){
    lines.pb(s);
  }
  // cout << lines[2] << endl;
  // return 0;
  if(!spacein(lines[0])){
    // cout << "here" << endl;

    int n = strtoint(lines[0]);
    V < pi > pts;
    V < vi > in(11,vi(11,0));
    for(int i=1; i<=n; i++){
      string a,b;
      tie(a,b) = split(lines[i]);
      // cout << "ab" _ a _ b _ lines[i] << endl;
      pts.pb({strtoint(a),strtoint(b)});
      in[pts.back().f][pts.back().s] = 1;
    }

    // cout << pts << endl;

    queue < pi > que; que.push(pts[0]); in[pts[0].f][pts[0].s] = 0;
    cout << pts[0].f _ pts[0].s << '\n';
    while(1){
      int i,j; tie(i,j) = que.front(); que.pop();

      if(i+1<=10 and in[i+1][j]){
        cout << "R";
        in[i+1][j] = 0;
        que.push({i+1,j});
      }

      if(j+1<=10 and in[i][j+1]){
        cout << "T";
        in[i][j+1] = 0;
        que.push({i,j+1});
      }

      if(i-1>=0 and in[i-1][j]){
        cout << "L";
        in[i-1][j] = 0;
        que.push({i-1,j});
      }


      if(j-1>=0 and in[i][j-1]){
        cout << "B";
        in[i][j-1] = 0;
        que.push({i,j-1});
      }


      if(!que.empty()) cout << ",\n";
      else{
        cout << ".\n";
        break;
      }
    }
  }
  else{
    V < pi > pts;
    string a,b; tie(a,b) = split(lines[0]);
    int ii = strtoint(a), jj = strtoint(b);
    pts.pb({ii,jj});

    queue < pi > que;
    que.push(pts[0]);
    int n = sz(lines)-1;

    for(int i=1; i<=n; i++){
      pi p = que.front(); que.pop();
      auto adj = neig(p,lines[i]);
      for(pi q: adj){
        pts.pb(q);
        que.push(q);
      }
    }
    sort(all(pts));
    cout << sz(pts) << endl;
    each(x,pts) cout << x.f _ x.s << endl;
    // cout << pts << endl;
  }
}