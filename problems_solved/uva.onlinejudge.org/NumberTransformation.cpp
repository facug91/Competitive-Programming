/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2830
        Name: Number Transformation
        Date: 01/03/2016
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
#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int s, t, sieve[1005], dis[105][1005];
vi adj[1005];
queue<int> q;
bool vis[1005];

void bfs (int idx) {
	memset(vis, 0, sizeof vis);
	vis[idx] = true;
	q.push(idx);
	dis[idx][idx] = 0;
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int v : adj[u]) {
			if (!vis[v]) {
				q.push(v);
				vis[v] = true;
				dis[idx][v] = dis[idx][u] + 1;
			}
		}
	}
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	for (i=2; i<1005; i++) sieve[i] = i;
	for (i=2; i<35; i++) if (sieve[i] == i)
		for (j=i*i; j<1005; j+=i)
			sieve[j] = i;
	for (i=2; i<1005; i++) {
		if (sieve[i] == i) continue;
		int n = i, factor;
		while (n != 1) {
			factor = sieve[n];
			if (i+factor < 1005) adj[i].push_back(i+factor);
			while (n % factor == 0) n /= factor;
		}
	}
	memset(dis, -1, sizeof dis);
	for (int i=1; i<105; i++) bfs(i);
	while (cin>>s>>t, s || t) cout<<"Case "<<tc++<<": "<<dis[s][t]<<endl;
	
	return 0;
}
