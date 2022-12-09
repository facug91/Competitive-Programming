/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1246
        Name: Ordering Tasks
        Date: 13/04/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-12
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, m, u, v, in[105];
vi adj[105], ts;
bool vis[105];
queue<int> q;

void bfs () {
	int i, j, u, v;
	for (i=0; i<n; i++) if (in[i] == 0) q.push(i);
	while (q.size()) {
		u = q.front(); q.pop();
		ts.push_back(u);
		for (i=0; i<adj[u].size(); i++) {
			v = adj[u][i];
			in[v]--;
			if (in[v] == 0) q.push(v);
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(10); cerr<<fixed<<setprecision(10); //cout.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j;
	
	while (cin>>n>>m, n || m) {
		for (i=0; i<n; i++) adj[i].clear(), in[i] = vis[i] = 0;
		for (i=0; i<m; i++) {
			cin>>u>>v; u--; v--;
			adj[u].push_back(v);
			in[v]++;
		}
		ts.clear();
		bfs();
		bool first = true;
		for (i=0; i<ts.size(); i++) {
			if (first) first = false;
			else cout<<" ";
			cout<<ts[i]+1;
		}
		cout<<"\n";
	}
	
	return 0;
}
