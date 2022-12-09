/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4545
        Name: Join two kingdoms
        Date: 03/11/2015
*/

#include <bits/stdc++.h>
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
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

ll n[2], u, v, ext[2][2], dim[2], dis[2][40005], rsq[2][40005], num, den, mn, idx;
vi tree[2][40005];

void dfs_dim (int u, int f, int len, int idx, int curr) {
	if (dim[idx] < len) {
		dim[idx] = len;
		ext[idx][curr] = u;
	}
	for (int v : tree[idx][u]) if (v != f) dfs_dim(v, u, len+1, idx, curr);
}

void dfs_dis (int u, int f, int len, int idx) {
	if (dis[idx][u] < len) dis[idx][u] = len;
	for (int v : tree[idx][u]) if (v != f) dfs_dis(v, u, len+1, idx);
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	cout<<fixed<<setprecision(3); cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j;
	
	while (cin>>n[0]>>n[1]) {
		mn = -1;
		for (i=0; i<2; i++) {
			for (j=1; j<=n[i]; j++) tree[i][j].clear();
			for (j=1; j<=n[i]-1; j++) {
				cin>>u>>v;
				tree[i][u].push_back(v);
				tree[i][v].push_back(u);
			}
			dim[i] = -1;
			dfs_dim(1, -1, 0, i, 0);
			dim[i] = -1;
			dfs_dim(ext[i][0], -1, 0, i, 1);
			mn = max(mn, dim[i]);
			memset(dis[i], 0, sizeof dis[i]);
			dfs_dis(ext[i][0], -1, 0, i);
			dfs_dis(ext[i][1], -1, 0, i);
			dis[i][0] = -INT_MAX;
			sort(dis[i], dis[i]+n[i]+1);
			rsq[i][0] = 0;
			for (j=1; j<=n[i]; j++) rsq[i][j] = rsq[i][j-1] + dis[i][j];
		}
		num = 0;
		den = n[0]*n[1];
		idx = n[1]+1;
		for (i=1; i<=n[0]; i++) {
			while (dis[1][idx-1] > mn-(dis[0][i]+1ll)) idx--;
			num += ((rsq[1][n[1]]-rsq[1][idx-1])+(n[1]-(idx-1ll))*(dis[0][i]+1ll));
			num += ((idx-1)*mn);
		}
		cout<<(double)num/(double)den<<endl;
	}
	
	return 0;
}
