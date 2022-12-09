/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1330
        Name: Binary Matrix
        Date: 15/05/2015
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

int n, m, s, t, u, v, r[55], c[55], sumr, sumc, mf, mfaux, p[202], res[202][202];
vi adj[202];
bool inuse[202][202];

bool bfs () {
	queue<int> q; q.push(s);
	memset(p, -1, sizeof p);
	int u, v, c, rev;
	bool sink = false;
	while (q.size()) {
		u = q.front(); q.pop();
		if (u == t) {
			sink = true;
			continue;
		}
		for (int i=0; i<adj[u].size(); i++) {
			v = adj[u][i];
			if (!inuse[u][v]) continue;
			if (p[v] == -1 && res[u][v] > 0) {
				p[v] = u;
				q.push(v);
			}
		}
	}
	return sink;
}

int dfs (int u, int min_edge) {
	if (u == s) return min_edge;
	else if (p[u] != -1) {
		if (res[p[u]][u] > 0) {
			int f = dfs(p[u], min(min_edge, res[p[u]][u]));
			if (f) {
				res[p[u]][u] -= f;
				res[u][p[u]] += f;
			}
			return f;
		} else return 0;
	} else return 0;
}

int max_flow () {
	int i, v;
	while (bfs()) {
		for (i=0; i<adj[t].size(); i++) {
			v = adj[t][i];
			if (!inuse[t][v]) continue;
			if (res[v][t] > 0) {
				p[t] = v;
				mf += dfs(t, res[v][t]);
			}
		}
	}
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
