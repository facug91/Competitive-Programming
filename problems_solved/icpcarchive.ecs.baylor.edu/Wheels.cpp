/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4942
        Name: Wheels
        Date: 21/02/2015
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

ll n, center[1005][2], radius[1005], rot[1005][2];
bool vis[1005], cw[1005];
vi adj[1005];

ll gcd (ll a, ll b) {
	if (a == 0) return b;
	return gcd(b%a, a);
}

void dfs (int u) {
	vis[u] = true;
	for (int i=0; i<adj[u].size(); i++) {
		int v = adj[u][i];
		if (!vis[v]) {
			cw[v] = !cw[u];
			rot[v][0] = radius[u]*rot[u][0];
			rot[v][1] = radius[v]*rot[u][1];
			ll g = gcd(rot[v][0], rot[v][1]);
			rot[v][0] /= g;
			rot[v][1] /= g;
			dfs(v);
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		for (i=0; i<1005; i++) adj[i].clear();
		cin>>n;
		for (i=0; i<n; i++) cin>>center[i][0]>>center[i][1]>>radius[i];
		for (i=0; i<n; i++)
			for (j=0; j<n; j++)
				if (i != j && (radius[i]+radius[j])*(radius[i]+radius[j]) == (center[i][0]-center[j][0])*(center[i][0]-center[j][0])+(center[i][1]-center[j][1])*(center[i][1]-center[j][1]))
					adj[i].push_back(j);
		memset(vis, 0, sizeof vis);
		memset(cw, 0, sizeof cw);
		cw[0] = 1; rot[0][0] = rot[0][1] = 1ll;
		dfs(0);
		for (i=0; i<n; i++) {
			if (vis[i]) {
				cout<<rot[i][0];
				if (rot[i][1] != 1ll) cout<<"/"<<rot[i][1];
				if (cw[i]) cout<<" clockwise"<<endl;
				else cout<<" counterclockwise"<<endl;
			} else cout<<"not moving"<<endl;
		}
	}
	
	return 0;
}
