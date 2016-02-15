/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5219
        Name: Exposing corruption
        Date: 17/11/2015
*/
 
#include <bits/stdc++.h>
#define y1		nd03dnqwuidg1odbnw9uddu0132d
#define clock	asoudh219udhjdgausdhs9udy433
#define left	dfgag34gsfaf342rf23fgwrf42ff
#define middle	lk78k6ujkj76kjk88kkummnhh456
#define right	apidwcojbl213f80sjb3y8efjfas
#define move	df53y5fgsf43fdsfsdtg4j6hfdg4
#define count	nkwdfj111afbjdfsbj32r8yfwejb
#define prev	asdnklgbgbjfasdbhksdva4t9jds
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10005
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<int, ii> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iii> viii; typedef vector<iiii> viiii;

int d, p, r, b, price[205], u, v, color[205], size[2], cost[205], val[205], DP[205][10005], n, inv;
vi adj[205];
bool vis[205];

void dfs (int u) {
	vis[u] = true;
	cost[n] += price[u];
	size[color[u]]++;
	for (int v : adj[u]) if (!vis[v]) dfs(v);
}

int dp (int u, int c) {
	for (int i=0; i<=n; i++) DP[i][0] = 0;
	for (int j=0; j<=b; j++) DP[0][j] = 0;
	for (int i=1; i<=n; i++) for (int j=1; j<=b; j++) {
		if (j >= cost[i-1]) DP[i][j] = max(DP[i-1][j], DP[i-1][j-cost[i-1]] + val[i-1]*inv);
		else DP[i][j] = DP[i-1][j];
	}
	return DP[n][b];
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j, k, l;
	
	while (cin>>d>>p>>r>>b) {
		for (i=0; i<d+p; i++) adj[i].clear();
		n = d + p;
		for (i=0; i<d+p; i++) cin>>price[i];
		while (r--) {
			cin>>u>>v; u--; v--; v += d;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		memset(vis, 0, sizeof vis);
		for (i=0; i<d; i++) color[i] = 0;
		for (i=d; i<d+p; i++) color[i] = 1;
		n = 0;
		for (i=0; i<d+p; i++) if (!vis[i]) {
			size[0] = size[1] = 0;
			cost[n] = 0;
			dfs(i);
			val[n] = size[1]-size[0];
			n++;
		}
		inv = 1;
		cout<<d+dp(0, b);
		inv = -1;
		cout<<" "<<p+dp(0, b)<<endl;
	}
	
	return 0;
}
