/*
	By: facug91
	From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5243
	Name: Odd Cycle
	Date: 26/04/2016
*/

#include <bits/stdc++.h>
#define endl "\n"
#define next sbjkdfh329re9fdshfd98fyh
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
//#define MOD 1000000007ll
#define MAXN 100000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, m, u, v, s, next[100005];
vi adj[100005];
bool vis[100005], curr[100005];

bool dfs (int u, int f) {
	vis[u] = true;
	curr[u] = true;
	if (vis[u^1] && curr[u^1]) {
		s = u ^ 1;
		return true;
	}
	for (int v : adj[u]) {
		if (f == v/2) continue;
		next[u] = v;
		if (!vis[v] && dfs(v, u/2)) return true;
	}
	curr[u] = false;
	return false;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(1); cerr<<fixed<<setprecision(1); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>n>>m;
		for (i=0; i<n*2; i++) adj[i].clear();
		while (m--) {
			cin>>u>>v; u--; v--;
			adj[u*2].push_back(v*2+1);
			adj[u*2+1].push_back(v*2);
		}
		memset(vis, 0, sizeof vis);
		memset(curr, 0, sizeof curr);
		bool oddCycle = false;
		for (i=0; i<n*2; i++) if (!vis[i]) {
			if (dfs(i, -1)) {
				int aux = next[s], cnt = 1;
				cout<<1<<endl;
				while (aux/2 != s/2) {
					aux = next[aux];
					cnt++;
				}
				cout<<cnt<<endl;
				cout<<s/2+1<<endl;
				aux = next[s];
				while (aux/2 != s/2) {
					cout<<aux/2+1<<endl;
					aux = next[aux];
				}
				oddCycle = true;
				break;
			}
		}
		if (!oddCycle) cout<<-1<<endl;
	}
	
	return 0;
}
