/*
	By: facug91
	From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=995
	Name: The Necklace
	Date: 24/06/2016
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define prev bjasdbi132ge79qwgdi
#define next usayhkdgisaydgiy212
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
//#define MOD 100000007
//#define MAXN 10000005

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, int> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; //insert, find_by_order, order_of_key, erase

int m, u, v, degree[55], adj[55][55];
stack<int> tour, current;
bool vis[55];

void mark (int u) {
	vis[u] = true;
	for (int v=0; v<55; v++) if (adj[u][v] && !vis[v]) mark(v);
}

bool is_connected () {
	memset(vis, 0, sizeof vis);
	int comp = 0;
	for (int i=0; i<55; i++) if (degree[i] && !vis[i]) {
		mark(i);
		comp++;
	}
	return comp == 1;
}

void dfs (int u) {
	current.push(u);
	while (current.size()) {
		u = current.top();
		bool has_next = false;
		if (adj[u][u]) {
			current.push(u);
			adj[u][u] -= 2;
			has_next = true;
		}
		for (int v=0; v<55 && !has_next; v++) if (adj[u][v]) {
			current.push(v);
			adj[u][v]--; adj[v][u]--;
			has_next = true;
		}
		if (!has_next) {
			current.pop();
			tour.push(u);
		}
	}
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(9); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		if (it != 1) cout<<endl;
		memset(adj, 0, sizeof adj);
		memset(degree, 0, sizeof degree);
		cin>>m;
		for (i=0; i<m; i++) {
			cin>>u>>v;
			adj[u][v]++;
			adj[v][u]++;
			degree[u]++;
			degree[v]++;
		}
		bool eulerian = is_connected();
		for (i=0; i<55; i++) if (degree[i] & 1) eulerian = false;
		cout<<"Case #"<<it<<endl;
		if (!eulerian) cout<<"some beads may be lost"<<endl;
		else {
			while (tour.size()) tour.pop();
			while (current.size()) current.pop();
			for (i=0; i<55; i++) if (degree[i]) {
				dfs(i);
				break;
			}
			j = tour.top(); tour.pop();
			while (tour.size()) {
				i = j;
				j = tour.top(); tour.pop();
				cout<<i<<" "<<j<<endl;
			}
		}
	}
	
	return 0;
}
