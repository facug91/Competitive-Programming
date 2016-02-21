/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2510
        Name: Cranes
        Date: 16/02/2016
*/

#include <bits/stdc++.h>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
#define MOD 1000000007ll
//#define MAXN 10005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

ll n, x[20], y[20], r[20], ans;

void dfs (ll u, int bm, ll area) {
	if (u == n) return;
	bool intersect = false;
	for (ll v=0ll; v<u; v++) if ((bm&(1ll<<v)) != 0ll)
		if ((x[v]-x[u])*(x[v]-x[u])+(y[v]-y[u])*(y[v]-y[u]) <= (r[v]+r[u])*(r[v]+r[u])) intersect = true;
	if (!intersect) {
		ans = max(ans, area+(r[u]*r[u]));
		dfs(u+1, bm|(1<<u), area+(r[u]*r[u]));
	}
	dfs(u+1, bm, area);
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>n;
		for (i=0; i<n; i++) cin>>x[i]>>y[i]>>r[i];
		ans = 0ll;
		dfs(0ll, 0, 0ll);
		cout<<ans<<endl;
	}
	
	return 0;
}
