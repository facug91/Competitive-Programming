/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1720
        Name: Collectors Problem
        Date: 02/05/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, m, k, c, s, t, res[50][50], level[50], card[50];
vi adj[50];

bool bfs () {
	queue<int> q; q.push(s);
	memset(level, -1, sizeof level);
	level[s] = 0;
	int u, v;
	while (q.size()) {
		u = q.front(); q.pop();
		for (int i=0; i<adj[u].size(); i++) {
			v = adj[u][i];
			if (level[v] == -1 && res[u][v] > 0) {
				level[v] = level[u] + 1;
				q.push(v);
				if (v == t) return true;
			}
		}
	}
	return false;
}

int dfs (int u, int min_edge) {
	if (u == t) return min_edge;
	int v, faux, fsum = 0;
	for (int i=0; i<adj[u].size(); i++) {
		v = adj[u][i];
		if (level[v] == level[u] + 1 && res[u][v] > 0) {
			faux = dfs(v, min(min_edge, res[u][v]));
			if (faux) {
				fsum += faux;
				res[u][v] -= faux;
				res[v][u] += faux;
				min_edge -= faux;
				if (min_edge == 0) break;
			}
		}
	}
	return fsum;
}

int max_flow () {
	int mf = 0;
	while (bfs()) mf += dfs(s, INT_MAX);
	return mf;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(4); cerr<<fixed<<setprecision(10); //cout.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>n>>m;
		for (i=0; i<m+n+2; i++) adj[i].clear();
		memset(res, 0, sizeof res);
		s = m+2; t = 1;
		for (i=2; i<m+2; i++) {
			adj[i].push_back(t);
			adj[t].push_back(i);
			res[i][t] = 1;
		}
		for (i=m+2; i<2+m+n; i++) {
			for (j=1; j<=m; j++) card[j] = 0;
			cin>>k;
			for (j=0; j<k; j++) {
				cin>>c;
				card[c]++;
			}
			for (j=1; j<=m; j++) {
				if (i == m+2) {
					if (card[j] > 0) {
						adj[i].push_back(j+1);
						adj[j+1].push_back(i);
						res[i][j+1] = card[j];
					}
				} else if (card[j] == 0) {
					adj[j+1].push_back(i);
					adj[i].push_back(j+1);
					res[j+1][i] = 1;
				} else if (card[j] > 1) {
					adj[i].push_back(j+1);
					adj[j+1].push_back(i);
					res[i][j+1] = card[j]-1;
				}
			}
		}
		cout<<"Case #"<<it<<": "<<max_flow()<<"\n";
	}
	
	return 0;
}
