/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=777&page=show_problem&problem=3691
        Name: Robot Challenge
        Date: 08/03/2016
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
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, x[1005], y[1005], p[1005];
double adj[1005][1005], RSQ[1005], DP[1005];

inline double point_dist (int i, int j) {
	return sqrt((double)(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	x[0] = y[0] = p[0] = 0;
	while (cin>>n, n) {
		for (i=1; i<=n; i++) cin>>x[i]>>y[i]>>p[i];
		n++;
		x[n] = y[n] = 100; p[n] = 0;
		for (i=0; i<=n; i++) for (j=i; j<=n; j++) adj[i][j] = point_dist(i, j);
		RSQ[0] = 0;
		for (i=1; i<=n; i++) RSQ[i] = p[i] + RSQ[i-1];
		DP[n] = 0.0;
		for (i=n-1; i>=0; i--) {
			DP[i] = DBL_MAX;
			for (j=i+1; j<=n; j++) DP[i] = min(DP[i], adj[i][j] + (RSQ[j-1] - RSQ[i]) + 1.0 + DP[j]);
		}
		cout<<fixed<<setprecision(3)<<round(DP[0]*1000.0)/1000.<<endl;
	}
	
	return 0;
}
