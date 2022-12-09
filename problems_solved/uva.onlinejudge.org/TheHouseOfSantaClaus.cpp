/*
	By: facug91
	From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=227
	Name: The House Of Santa Claus
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

bool adj[6][6];
vi ans;

void dfs (int u) {
	ans.push_back(u);
	if (ans.size() == 9) {
		for (int i=0; i<9; i++) cout<<ans[i];
		cout<<endl;
	} else {
		for (int v=1; v<=5; v++) if (u != v && adj[u][v]) {
			adj[u][v] = adj[v][u] = false;
			dfs(v);
			adj[u][v] = adj[v][u] = true;
		}
	}
	ans.pop_back();
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(9); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j;
	
	memset(adj, 0, sizeof adj);
	adj[1][2] = adj[1][3] = adj[1][5] = true;
	adj[2][1] = adj[2][3] = adj[2][5] = true;
	adj[5][1] = adj[5][2] = adj[5][3] = adj[5][4] = true;
	adj[3][1] = adj[3][2] = adj[3][4] = adj[3][5] = true;
	adj[4][3] = adj[4][5] = true;
	dfs(1);
	
	return 0;
}
