/*
	By: facug91
	From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1070
	Name: Play on Words
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

int in[300], out[300], n, same, inmore, outmore, total;
string s;
vi adj[300];
bool vis[300];

void mark (int u) {
	vis[u] = true;
	for (int v : adj[u]) if (!vis[v]) mark(v);
}

bool is_connected () {
	int comp = 0;
	memset(vis, 0, sizeof vis);
	for (int i=0; i<300; i++) if ((in[i] || out[i]) && !vis[i]) {
		mark(i);
		comp++;
	}
	return comp == 1;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(9); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j;
	
	cin>>tc;
	while (tc--) {
		memset(in, 0, sizeof in);
		memset(out, 0, sizeof out);
		for (i=0; i<300; i++) adj[i].clear();
		cin>>n;
		for (i=0; i<n; i++) {
			cin>>s;
			out[s.front()]++;
			in[s.back()]++;
			adj[s.front()].push_back(s.back());
			adj[s.back()].push_back(s.front());
		}
		same = inmore = outmore = total = 0;
		for (i=0; i<300; i++) if (in[i] || out[i]) {
			if (in[i] == out[i]) same++;
			if (in[i]+1 == out[i]) inmore++;
			if (in[i]-1 == out[i]) outmore++;
			total++;
		}
		if (is_connected() && (same == total || (same == total-2 && inmore == 1 && outmore == 1))) cout<<"Ordering is possible."<<endl;
		else cout<<"The door cannot be opened."<<endl;
	}
	
	return 0;
}
