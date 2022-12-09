/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=195
        Name: Software Allocation
        Date: 18/02/2015
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
#define find asjkldhakjsdbsakjdb
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int res[50][50], level[50], s, t, mf, p;
string str;
vi adj[50];

bool bfs () {
	queue<int> q; q.push(s);
	memset(level, -1, sizeof level);
	level[s] = 0;
	int u, v, i;
	while (q.size()) {
		u = q.front(); q.pop();
		for (i=0; i<adj[u].size(); i++) {
			v = adj[u][i];
			if (level[v] == -1 && res[u][v] > 0) {
				level[v] = level[u] + 1;
				if (v == t) return true;
				q.push(v);
			}
		}
	}
	return false;
}

int dfs (int u, int min_edge) {
	if (u == t) return min_edge;
	int v, i, fsum = 0, faux;
	for (i=0; i<adj[u].size(); i++) {
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
	mf = 0;
	while (bfs()) mf += dfs(s, MAX_INT);
	return mf;
}

void bfs_test () {
	bool vis[50];
	memset(vis, 0, sizeof vis);
	vis[s] = true;
	queue<int> q; q.push(s);
	cerr<<endl;
	while (q.size()) {
		int u = q.front(); q.pop();
		cerr<<"u "<<u<<":";
		for (int i=0; i<adj[u].size(); i++) {
			int v = adj[u][i];
			if (!vis[v]) {
				vis[v] = true;
				q.push(v);
			}
			cerr<<" ("<<v<<","<<res[u][v]<<")";
		}
		cerr<<endl;
	}
	cerr<<endl;
}

int main () {
	ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j;
    
    while (getline(cin, str)) {
		memset(res, 0, sizeof res);
		for (i=0; i<50; i++) adj[i].clear();
		s = 0; t = 1;
		
		for (i=2; i<12; i++) {
			res[s][i] = 1;
			adj[s].push_back(i);
			adj[i].push_back(s);
		}
		
		p = 0;
		do {
			if (str.empty()) break;
			p += (str[1]-'0');
			for (i=3; str[i]!=';'; i++) {
				res[str[i]-'0'+2][str[0]-'A'+12] = 1;
				adj[str[i]-'0'+2].push_back(str[0]-'A'+12);
				adj[str[0]-'A'+12].push_back(str[i]-'0'+2);
			}
			res[str[0]-'A'+12][t] = str[1]-'0';
			adj[str[0]-'A'+12].push_back(t);
			adj[t].push_back(str[0]-'A'+12);
		} while (getline(cin, str));
		
		//test bfs
		//bfs_test();
		
		max_flow();
		
		//test bfs
		//bfs_test();
		
		if (mf != p) cout<<"!"<<endl;
		else {
			for (i=2; i<12; i++) {
				bool printed = false;
				for (j=1; j<adj[i].size(); j++) {
					if (res[i][adj[i][j]] == 0) {
						cout<<(char)(adj[i][j]-12+'A');
						printed = true;
						break;
					}
				}
				if (!printed) cout<<"_";
			}
			cout<<endl;
		}
		
	}
    
	return 0;
}
