/*
	By: facug91
	From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3907
	Name: Speed Racer
	Date: 29/04/2016
*/

#include <bits/stdc++.h>
#define endl "\n"
#define next sbjkdfh329re9fdshfd98fyh
#define EPS 1e-6
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
//#define MOD 1000000007ll
#define MAXN 100000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

double a, b, c, d, m, t, base;

double f (double v) {
	double v2 = v * v;
	return a * v2 * v2 + b * v2 * v + c * v2 + d * v;
}

double ternary_search () {
	double lo = 0.0, hi = 1000.0, mid1, mid2, val1, val2;
	while (fabs(lo-hi) > EPS) {
		mid1 = lo + (hi - lo) / 3.0;
		mid2 = lo + (hi - lo) * 2.0 / 3.0;
		val1 = f(mid1);
		val2 = f(mid2);
		if (val1 < val2) hi = mid2-EPS;
		else lo = mid1+EPS;
	}
	return lo;
}

double binary_search () {
	double lo = base, hi = 1000.0, v, gas, time;
	while (fabs(lo-hi) > EPS) {
		v = (lo + hi) / 2.0;
		gas = f(v);
		time = m / v;
		if (gas * time >= t) hi = v - EPS;
		else lo = v + EPS;
	}
	return lo;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	cout<<fixed<<setprecision(2); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	while (cin>>a>>b>>c>>d>>m>>t) {
		base = ternary_search();
		cout<<floor(binary_search()*100.0)/100.0<<endl;
	}
	
	return 0;
}
