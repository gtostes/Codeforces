
/**----------------------**
** By: Gabriel Tostes    **
** Date: 05-02-2024      **
** Hour: 05:24:17 (CET)  **
**-----------------------*/

#include <bits/stdc++.h> 
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i) 
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii; 
typedef vector<int> vi;
 
//mt19937_64 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
//uniform_int_distribution<long long> rg(1,1e9);

vi topoSort(const vector<vi>& gr) {
	vi indeg(sz(gr)), ret;
	for (auto& li : gr) for (int x : li) indeg[x]++;
	queue<int> q; // use priority_queue for lexic. largest ans.
	rep(i,0,sz(gr)) if (indeg[i] == 0) q.push(i);
	while (!q.empty()) {
		int i = q.front(); // top() for priority queue
		ret.push_back(i);
		q.pop();
		for (int x : gr[i])
			if (--indeg[x] == 0) q.push(x);
	}
	return ret;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //freopen("input5.in", "r", stdin);
  //freopen("problemname.txt", "w", stdout);
  int n; cin >> n;
  vector < vi > gr(n);
  for(int i=0; i<n; i++){
    int t;
    while(cin >> t){
      if(t==0) break;
      gr[i].push_back(t-1);
    }
  }

  vi ts = topoSort(gr);
  for(int x: ts) cout << x+1 << ' ';
  cout << '\n';
}