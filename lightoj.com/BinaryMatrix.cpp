/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1330
        Name: Binary Matrix
        Date: 14/05/2015
*/
 
#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
#define MOD 1000000007ll
#define MAXN 10000100
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, m, s, t, u, v, r[55], c[55], res[202][202], level[202], sumr, sumc, mf, mfaux;
vi adj[202];
bool inuse[202][202];

bool bfs () {
	queue<int> q; q.push(s);
	memset(level, -1, sizeof level);
	level[s] = 0;
	int u, v, i;
	while (q.size()) {
		u = q.front(); q.pop();
		for (i=0; i<adj[u].size(); i++) if (inuse[u][v=adj[u][i]]) {
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
	int v, i, faux, fsum = 0;
	for (i=0; i<adj[u].size(); i++) if (inuse[u][v=adj[u][i]]) {
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
	while (bfs()) mf += dfs(s, INT_MAX);
	return mf;
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(4); cerr<<fixed<<setprecision(10); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>n>>m;
		sumr = sumc = 0;
		for (i=0; i<n; i++) {
			cin>>r[i];
			sumr += r[i];
		}
		for (j=0; j<m; j++) {
			cin>>c[j];
			sumc += c[j];
		}
		if (sumr != sumc) cout<<"Case "<<it<<": impossible\n";
		else {
			memset(inuse, 0, sizeof inuse);
			memset(res, 0, sizeof res);
			for (i=0; i<202; i++) adj[i].clear();
			s = 200; t = 201; mf = 0;
			for (i=0; i<n; i++) for (j=0; j<m; j++) {
				u = i; v = j+n;
				adj[u].push_back(v);
				adj[v].push_back(u);
				res[u][v] = 1;
				res[v][u] = 0;
				inuse[u][v] = inuse[v][u] = true;
			}
			for (i=0; i<n; i++) {
				adj[s].push_back(i);
				adj[i].push_back(s);
				res[s][i] = r[i];
				res[i][s] = 0;
				inuse[s][i] = inuse[i][s] = true;
			}
			for (j=0; j<m; j++) {
				v = j+n;
				adj[v].push_back(t);
				adj[t].push_back(v);
				res[v][t] = c[j];
				res[t][v] = 0;
				inuse[v][t] = inuse[t][v] = true;
			}
			if (max_flow() != sumc) cout<<"Case "<<it<<": impossible\n";
			else {
				cout<<"Case "<<it<<":\n";
				for (i=0; i<n; i++) {
					for (j=0; j<m; j++) {
						u = i; v = j+n;
						if (res[v][u] > 0) {
							mfaux = mf;
							mf--;
							inuse[u][v] = inuse[v][u] = false;
							res[t][v]--;
							res[v][t]++;
							res[u][s]--;
							res[s][u]++;
							if (max_flow() == mfaux) {
								cout<<'0';
							} else {
								res[s][u]--;
								res[v][t]--;
								cout<<'1';
							}
						} else {
							inuse[u][v] = inuse[v][u] = false;
							cout<<'0';
						}
					}
					cout<<"\n";
				}
			}
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
