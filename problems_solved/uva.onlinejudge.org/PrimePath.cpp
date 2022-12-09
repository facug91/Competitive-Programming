/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3253
        Name: Prime Path
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

int a, b, u, v, dis[10005];
bool sieve[10005];
vi adj[10005];
bool vis[10005];

void bfs (int from, int to) {
	queue<int> q;
	for (int i=1000; i<10000; i++) {
		vis[i] = false;
		dis[i] = -1;
	}
	q.push(from);
	vis[from] = true;
	dis[from] = 0;
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int v : adj[u]) {
			if (!vis[v]) {
				vis[v] = true;
				dis[v] = dis[u] + 1;
				q.push(v);
				if (v == to) return;
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
	
	for (i=0; i<10005; i++) sieve[i] = true;
	for (i=4; i<10005; i+=2) sieve[i] = false;
	for (i=3; i<105; i+=2) 
		if (sieve[i])
			for (j=i*i; j<10005; j+=i+i)
				sieve[j] = false;
	for (u=1000; u<10000; u++) {
		for (i=10; i<=10000; i*=10) {
			for (j=0; j<10; j++) {
				if (j == 0 && i == 10000) continue;
				v = u / i * i + j * i / 10 + (u % (i / 10));
				if (sieve[v]) adj[u].push_back(v);
			}
		}
	}
	cin>>tc;
	while (tc--) {
		cin>>a>>b;
		bfs(a, b);
		if (dis[b] == -1) cout<<"Impossible"<<endl;
		else cout<<dis[b]<<endl;
	}
	
	return 0;
}
