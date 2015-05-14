/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2375
        Name: Down Went The Titanic
        Date: 07/05/2015
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

int n, m, p, s, t, res[2005][2005], level[2005], dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
string board[35];
vi adj[2005];

bool bfs () {
    queue<int> q; q.push(s);
    memset(level, -1, sizeof level);
    level[s] = 0;
    int u, v;
    while (!q.empty()) {
        u = q.front(); q.pop();
        for (int i=0; i<(int)adj[u].size(); i++) {
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
    for (int i=0; i<(int)adj[u].size(); i++) {
        v = adj[u][i];
        if (res[u][v] > 0 && level[v] == level[u] + 1) {
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
	//cout<<fixed<<setprecision(4); cerr<<fixed<<setprecision(10); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j, k, w, z;
	
	s = 2000; t = 2001;
	while (cin>>n>>m>>p) {
		for (i=0; i<2005; i++) adj[i].clear();
		memset(res, 0, sizeof res);
		for (i=0; i<n; i++) cin>>board[i];
		for (i=0; i<n; i++) for (j=0; j<m; j++) {
			int in = i*m+j, out = i*m+j+(n*m);
			if (board[i][j] == '~') continue;
			if (board[i][j] == '*') {
				adj[s].push_back(in);
				adj[in].push_back(s);
				res[s][in] = 1;
				adj[in].push_back(out);
				adj[out].push_back(in);
				res[in][out] = 1;
			} else if (board[i][j] == '#') {
				adj[out].push_back(t);
				adj[t].push_back(out);
				res[out][t] = p;
				adj[in].push_back(out);
				adj[out].push_back(in);
				res[in][out] = INF;
			} else if (board[i][j] == '.') {
				adj[in].push_back(out);
				adj[out].push_back(in);
				res[in][out] = 1;
			} else if (board[i][j] == '@') {
				adj[in].push_back(out);
				adj[out].push_back(in);
				res[in][out] = INF;
			}
			for (k=0; k<4; k++) {
				w = i+dx[k]; z = j+dy[k];
				if (w >= 0 && w < n && z >= 0 && z < m && board[w][z] != '~' && board[w][z] != '*') {
					adj[out].push_back(m*w+z);
					adj[m*w+z].push_back(out);
					res[out][m*w+z] = INF;
				}
			}
		}
		cout<<max_flow()<<"\n";
	}
	
	return 0;
}
