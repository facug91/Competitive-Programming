/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=694
        Name: A Plug for UNIX
        Date: 16/05/2015
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

int n, m, k, r, u, v, s, t, receptacle[105], device[105], p[500], pa[500], to_vertex[500];
ii adapter[105];
map<string, int> to_idx;
viii adj[500];
string a, b;

bool bfs () {
	queue<int> q; q.push(s);
	memset(p, -1, sizeof p);
	memset(pa, -1, sizeof pa);
	int u, v, c, rev;
	bool sink = false;
	while (q.size()) {
		u = q.front(); q.pop();
		if (u == t) {
			sink = true;
			continue;
		}
		for (int i=0; i<adj[u].size(); i++) {
			v = adj[u][i].first;
			c = adj[u][i].second.first;
			rev = adj[u][i].second.second;
			if (p[v] == -1 && c > 0) {
				p[v] = u;
				pa[v] = rev;
				q.push(v);
			}
		}
	}
	return sink;
}

int dfs (int u, int min_edge) {
	if (u == s) return min_edge;
	else if (p[u] != -1) {
		int rev = adj[u][pa[u]].second.second;
		int cr = adj[p[u]][rev].second.first;
		if (cr > 0) {
			int f = dfs(p[u], min(min_edge, cr));
			if (f) {
				adj[p[u]][rev].second.first -= f;
				adj[u][pa[u]].second.first += f;
			}
			return f;
		} else return 0;
	} else return 0;
}

int max_flow () {
	int mf = 0, i, v, cr, rev;
	while (bfs()) {
		for (i=0; i<adj[t].size(); i++) {
			v = adj[t][i].first;
			rev = adj[t][i].second.second;
			cr = adj[v][rev].second.first;
			if (cr > 0) {
				p[t] = v;
				pa[t] = i;
				mf += dfs(t, cr);
			}
		}
	}
	return mf;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(4); cerr<<fixed<<setprecision(10); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j, l;
	map<string, int>::iterator itr, jtr;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		if (it != 1) cout<<"\n";
		to_idx.clear();
		for (i=0; i<500; i++) adj[i].clear();
		r = 0;
		cin>>n;
		for (i=0; i<n; i++) {
			cin>>a;
			receptacle[i] = r;
			to_idx[a] = r++;
		}
		cin>>m;
		for (i=0; i<m; i++) {
			cin>>a>>b;
			if (to_idx.find(b) == to_idx.end()) to_idx[b] = r++;
			device[i] = to_idx[b];
		}
		cin>>k;
		for (i=0; i<k; i++) {
			cin>>a>>b;
			if (to_idx.find(a) == to_idx.end()) to_idx[a] = r++;
			if (to_idx.find(b) == to_idx.end()) to_idx[b] = r++;
			adapter[i] = ii(to_idx[a], to_idx[b]);
		}
		s = 498; t = 499;
		itr = to_idx.begin(); j = m; 
		while (itr!=to_idx.end()) {
			to_vertex[(*itr).second] = j;
			j++; itr++;
		}
		for (i=0; i<m; i++) {
			adj[s].push_back(iii(i, ii(1, adj[i].size())));
			adj[i].push_back(iii(s, ii(0, adj[s].size()-1)));
			u = i; v = to_vertex[device[i]];
			adj[u].push_back(iii(v, ii(1, adj[v].size())));
			adj[v].push_back(iii(u, ii(0, adj[u].size()-1)));
		}
		
		for (i=0; i<n; i++) {
			u = to_vertex[receptacle[i]];
			adj[u].push_back(iii(t, ii(1, adj[t].size())));
			adj[t].push_back(iii(u, ii(0, adj[u].size()-1)));
		}
		for (i=0; i<k; i++) {
			u = to_vertex[adapter[i].first]; v = to_vertex[adapter[i].second];
			adj[u].push_back(iii(v, ii(INF, adj[v].size())));
			adj[v].push_back(iii(u, ii(0, adj[u].size()-1)));
		}
		cout<<m-max_flow()<<"\n";
	}
	
	return 0;
}
