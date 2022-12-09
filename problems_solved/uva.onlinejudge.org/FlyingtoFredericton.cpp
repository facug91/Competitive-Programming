/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=680&page=show_problem&problem=2255
        Name: Flying to Fredericton
        Date: 22/05/2015
*/
 
#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10000100
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

int n, m, DP[105][105], u, v, w	, q, d;
vii adj[105];
map<string, int> to_idx;
string city1, city2;

void bellmanFord () {
	int i, j, u, v, w;
	for (i=0; i<n; i++) for (j=0; j<n; j++) DP[i][j] = INF;
	DP[0][0] = 0;
	for (j=1; j<=n; j++) {
		for (u=0; u<n; u++) {
			for (i=0; i<adj[u].size(); i++) {
				v = adj[u][i].first;
				w = adj[u][i].second;
				DP[v][j] = min(DP[v][j], DP[u][j-1]+w);
			}
			DP[u][j] = min(DP[u][j], DP[u][j-1]);
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tc, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		if (it != 1) cout<<"\n";
		cin>>n;
		to_idx.clear();
		for (i=0; i<n; i++) {
			cin>>city1;
			to_idx[city1] = i;
			adj[i].clear();
		}
		cin>>m;
		for (i=0; i<m; i++) {
			cin>>city1>>city2>>w;
			u = to_idx[city1];
			v = to_idx[city2];
			adj[u].push_back(ii(v, w));
		}
		bellmanFord();
		cin>>q;
		cout<<"Scenario #"<<it<<"\n";
		while (q--) {
			cin>>d; d++; d = min(d, n-1);
			if (DP[n-1][d] == INF) cout<<"No satisfactory flights\n";
			else cout<<"Total cost of flight(s) is $"<<DP[n-1][d]<<"\n";
		}
	}
	
	return 0;
}
