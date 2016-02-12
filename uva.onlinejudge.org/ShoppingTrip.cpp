/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2259
        Name: Shopping Trip
        Date: 19/10/2015
*/

#include <bits/stdc++.h>
#define y1		nd03dnqwuidg1odbnw9uddu0132d
#define clock	asoudh219udhjdgausdhs9udy433
#define left	dfgag34gsfaf342rf23fgwrf42ff
#define middle	lk78k6ujkj76kjk88kkummnhh456
#define right	apidwcojbl213f80sjb3y8efjfas
#define move	df53y5fgsf43fdsfsdtg4j6hfdg4
#define count	nkwdfj111afbjdfsbj32r8yfwejb
#define prev	asdnklgbgbjfasdbhksdva4t9jds
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 100000000
//#define MAXN 10005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<int, ii> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iii> viii; typedef vector<iiii> viiii;

int n, m, u, v, p, limit;
double w, adj[55][55], DP[14][1<<14];
pair<int, double> dvd[15];

double dp (int u, int bm) {
	if (bm == limit) return adj[dvd[u].first][0];
	if (DP[u][bm] != DBL_MAX) return DP[u][bm];
	double ans = adj[dvd[u].first][0];
	for (int v=0; v<=p; v++) if ((bm & (1<<v)) == 0) {
		ans = min(ans, dp(v, bm|(1<<v)) + adj[dvd[u].first][dvd[v].first] - dvd[v].second);
	}
	return DP[u][bm] = ans;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout<<fixed<<setprecision(2); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j, k;
	
	cin>>tc;
	while (tc--) {
		cin>>n>>m;
		n++;
		for (i=0; i<n; i++) {
			for (j=0; j<n; j++) adj[i][j] = INF;
			adj[i][i] = 0.0;
		}
		while (m--) {
			cin>>u>>v>>w;
			if (adj[u][v] > w) adj[u][v] = adj[v][u] = w;
		}
		cin>>p;
		dvd[0].F = 0; dvd[0].S = 0.0;
		for (i=1; i<=p; i++) cin>>dvd[i].F>>dvd[i].S;
		for (k=0; k<n; k++)
			for (i=0; i<n; i++)
				for (j=0; j<n; j++)
					adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
		for (i=0; i<=p; i++) for (j=0; j<(1<<(p+1)); j++) DP[i][j] = DBL_MAX;
		limit = (1<<(p+1))-1;
		double ans = dp(0, 1);
		if (fabs(ans) < EPS ) cout<<"Don't leave the house"<<endl;
		else cout<<"Daniel can save $"<<-ans<<endl;
	}
	
	return 0;
}
