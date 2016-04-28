/*
	By: facug91
	From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4911
	Name: Permutation Cycles
	Date: 28/04/2016
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

int n, u, adj[1005], ans;
bool vis[1005];

void dfs (int u) {
	vis[u] = true;
	if (!vis[adj[u]]) dfs(adj[u]);
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(2); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j, k;
	
	cin>>tc;
	while (tc--) {
		cin>>n;
		for (i=0; i<n; i++) {
			cin>>u; u--;
			adj[i] = u;
			vis[i] = false;
		}
		ans = 0;
		for (i=0; i<n; i++) if (!vis[i]) {
			ans++;
			dfs(i);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
