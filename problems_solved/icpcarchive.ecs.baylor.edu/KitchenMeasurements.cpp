/*
	By: facug91
	From: https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&Itemid=99999999&page=show_problem&category=706&problem=5376&mosmsg=Submission+received+with+ID+1954567
	Name: Kitchen Measurements
	Date: 10/05/2016
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
//#define MOD 1000000000ll
//#define MAXN 30015

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, c[5], val, t, lim, sum;
unordered_set<int> vis;
unordered_map<int, int> dis;

int dijkstra (int origin) {
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(0, origin));
	dis.clear();
	dis[origin] = 0;
	vis.clear();
	ii u;
	int cc[5], aux, v, sumaux;
	while (pq.size()) {
		u = pq.top(); pq.pop();
		if (vis.find(u.S) != vis.end()) continue;
		vis.insert(u.S);
		
		aux = u.S;
		sumaux = 0;
		for (int i=1; i<n-1; i++) {
			cc[n-i-1] = aux & ((1 << 6) - 1);
			sumaux += cc[n-i-1];
			aux >>= 6;
		}
		cc[0] = aux;
		sumaux += cc[0];
		cc[n-1] = sum - sumaux;
		
		if (cc[0] == val) return dis[u.S];
		
		for (int i=0; i<n; i++) for (int j=0; j<n; j++) if (i != j) {
			aux = min(cc[i], c[j]-cc[j]);
			cc[i] -= aux;
			cc[j] += aux;
			v = cc[0];
			for (int k=1; k<n-1; k++) v = (v << 6) + cc[k];
			
			if (dis.find(v) == dis.end()) dis[v] = INF;
			if (dis[v] > dis[u.S] + aux) {
				dis[v] = dis[u.S] + aux;
				pq.push(ii(dis[v], v));
			} 
			
			cc[i] += aux;
			cc[j] -= aux;
		}
		
	}
	return INF;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(2); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1;
	
	while (cin>>n) {
		for (int i=0; i<n; i++) cin>>c[i];
		sum = c[0];
		cin>>val;
		int u = c[0];
		for (int i=1; i<n-1; i++) u = (u << 6);
		int ans = dijkstra(u);
		if (ans == INF) cout<<"impossible\n";
		else cout<<ans<<"\n";
	}
	
	return 0;
}
