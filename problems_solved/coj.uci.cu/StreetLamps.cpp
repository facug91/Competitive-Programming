/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2396
        Name: Street Lamps
        Date: 02/03/2016
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

int n, bm, dis[1<<20];
string state;

void bfs (int bm) {
	queue<int> q; q.push(bm);
	dis[bm] = 0;
	int u, v;
	while (q.size()) {
		u = q.front(); q.pop();
		for (int i=0; i<n; i++) {
			v = u ^ (1<<i);
			if (i > 0) v ^= (1<<(i-1));
			if (i < n-1) v ^= (1<<(i+1));
			if (dis[v] == -1) {
				dis[v] = dis[u] + 1;
				q.push(v);
				if (v == ((1<<n)-1)) return;
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
	
	cin>>tc;
	while (tc--) {
		cin>>n>>state;
		bm = 0;
		for (i=0; i<n; i++) bm |= ((state[i]-'0')<<(n-i-1));
		memset(dis, -1, sizeof dis);
		bfs(bm);
		cout<<dis[(1<<n)-1]<<endl;
	}
	
	return 0;
}
