/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2423
        Name: Cubes
        Date: 27/02/2016
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
#define MAXN 10005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, X[10005], Y[10005], x, y, d;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	for (i=0; i<MAXN; i++) Y[i] = INF;
	for (y=0; y<60; y++) for (x=0; x<60; x++) {
		d = x*x*x - y*y*y;
		if (d >= 0 && d < MAXN && Y[d] == INF) Y[d] = y, X[d] = x;
	}
	while (cin>>n, n) {
		if (Y[n] == INF) cout<<"No solution"<<endl;
		else cout<<X[n]<<" "<<Y[n]<<endl;
	}
	
	return 0;
}
