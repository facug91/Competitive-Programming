/*
	By: facug91
	From: http://www.lightoj.com/volume_showproblem.php?problem=1234
	Name: Harmonic Number
	Date: 27/05/2016
*/

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
//#define MOD 100000007
#define MAXN 10000005

using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, int> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int n;
double hn[1000005], ans;

int main () {
	//#ifdef ONLINE_JUDGE
		//ios_base::sync_with_stdio(0); cin.tie(0);
	//#endif
	//cout<<fixed<<setprecision(10); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j;
   
	hn[0] = 0.0;
	for (i=1; i<1000001; i++) {
		hn[i] = hn[i-1];
		for (j=(i-1)*100+1; j<=i*100; j++)
			hn[i] += 1.0/j;
	}
	scanf("%d", &tc);
	for (int it=1; it<=tc; it++) {
		scanf("%d", &n);
		ans = hn[n/100];
		for (i=n/100*100+1; i<=n; i++) ans += 1.0/i;
		printf("Case %d: %.10lf\n", it, ans);
	}
	
	return 0;
}
