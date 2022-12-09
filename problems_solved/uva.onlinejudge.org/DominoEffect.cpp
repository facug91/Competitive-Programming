/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=254
        Name: Domino Effect
        Date: 27/01/2015
*/

#include <bits/stdc++.h>
#define endl "\n"
#define EPS 1e-2
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, m, u, v, w, adj[505][505], dis[505][505];

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	cout<<fixed<<setprecision(1); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j, k;
	
	while (cin>>n>>m, n || m) {
		for (i=0; i<n; i++) {
			for (j=0; j<n; j++) adj[i][j] = INF;
			adj[i][i] = 0;
		}
		while (m--) {
			cin>>u>>v>>w; u--; v--;
			adj[u][v] = adj[v][u] = w;
		}
		for (i=0; i<n; i++) for (j=0; j<n; j++) dis[i][j] = adj[i][j];
		for (k=0; k<n; k++)
			for (i=0; i<n; i++)
				for (j=0; j<n; j++)
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
		double maxdis = 0, aux; 
		int ans1 = 0, ans2 = 0;
		for (i=0; i<n; i++) {
			if ((double)dis[0][i] >= maxdis) {
				maxdis = (double)dis[0][i];
				ans1 = ans2 = i;
			}
			for (j=0; j<n; j++) if (i != j && adj[i][j] < INF) {
				if (dis[0][i] <= dis[0][j]) {
					if (dis[0][i] + adj[i][j] > dis[0][j]) {
						aux = dis[0][j] + (adj[i][j]-(dis[0][j]-dis[0][i]))/2.0;
						if (aux > maxdis) {
							maxdis = aux;
							ans1 = i;
							ans2 = j;
						}
					}
				}
			}
		}
		if (ans1 > ans2) swap(ans1, ans2);
		cout<<"System #"<<tc++<<endl;
		if (ans1 == ans2) cout<<"The last domino falls after "<<maxdis<<" seconds, at key domino "<<ans1+1<<"."<<endl;
		else cout<<"The last domino falls after "<<maxdis<<" seconds, between key dominoes "<<ans1+1<<" and "<<ans2+1<<"."<<endl;
		cout<<endl;
	}
	
	return 0;
}
