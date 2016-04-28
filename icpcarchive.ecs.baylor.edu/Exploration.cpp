/*
	By: facug91
	From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4909
	Name: Exploration
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

int n, k, f, degree[2005], u, v, ans;
vector<int> adj[2005];
bool vis[2005];

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(2); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>n>>k>>f;
		for (i=0; i<n; i++) adj[i].clear();
		memset(degree, 0, sizeof degree);
		while (f--) {
			cin>>u>>v; u--; v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
			degree[u]++;
			degree[v]++;
		}
		memset(vis, 0, sizeof vis);
		bool in = true;
		while (in) {
			int minId = -1, minD = INT_MAX;
			for (i=0; i<n; i++) {
				if (!vis[i] && minD > degree[i]) {
					minId = i;
					minD = degree[i];
				}
			}
			if (minId == -1 || minD >= k) break;
			for (int v : adj[minId]) {
				if (!vis[v]) degree[v]--;
			}
			degree[minId] = 0;
			vis[minId] = true;
		}
		ans = 0;
		for (i=0; i<n; i++) if (!vis[i]) ans++;
		cout<<ans<<endl;
	}
	
	return 0;
}
