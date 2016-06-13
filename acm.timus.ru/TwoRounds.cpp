/*
	By: facug91
	From: http://acm.timus.ru/problem.aspx?space=1&num=1156
	Name: Two Rounds
	Date: 06/06/2016
*/

#include <bits/stdc++.h>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
//#define MOD 100000007
#define MAXN 10000005

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, int> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, m, u, v, color[110], ncomp, bipartite;
int DP[110][55]; // -1 no visitado ; 0 visitado pero fallido ; 1 visitado y usó el primero ; 2 visitado y usó el segundo
vi adj[110];
vi comp[110][2];

void dfs (int u) {
	comp[ncomp][color[u]].push_back(u);
	for (int v : adj[u]) {
		if (color[v] == -1) {
			color[v] = (color[u] + 1) % 2;
			dfs(v);
		} else if (color[u] == color[v]) {
			bipartite = false;
		}
	}
}

int dp (int idx, int sum) {
	if (sum > n/2) return 0;
	if (idx == ncomp && sum == n/2) return 1;
	if (DP[idx][sum] != -1) return 0;
	if (dp(idx+1, sum+comp[idx][0].size())) return DP[idx][sum] = 1;
	if (dp(idx+1, sum+comp[idx][1].size())) return DP[idx][sum] = 2;
	return DP[idx][sum] = 0;
}

int main () {
	//#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	//#endif
	//cout<<fixed<<setprecision(9); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j, k;
	
	cin>>n>>m;
	n <<= 1;
	while (m--) {
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(color, -1, sizeof color);
	ncomp = 0;
	bipartite = true;
	for (i=1; i<=n; i++) if (color[i] == -1) {
		color[i] = 0;
		dfs(i);
		ncomp++;
		if (!bipartite) break;
	}
	memset(DP, -1, sizeof DP);
	if (!bipartite || !dp(0, 0)) cout<<"IMPOSSIBLE"<<endl;
	else {
		for (int it=0; it<2; it++) {
			i = 0; j = 0;
			bool first = true;
			while (i < ncomp) {
				for (k=0; k<comp[i][it^(DP[i][j]-1)].size(); k++) {
					if (first) first = false;
					else cout<<" ";
					cout<<comp[i][it^(DP[i][j]-1)][k];
				}
				j += comp[i][DP[i][j]-1].size();
				i++;
			}
			cout<<endl;
		}
	}
	
	return 0;
}
