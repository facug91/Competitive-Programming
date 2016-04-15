/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5249
        Name: Wheel of Numbers
        Date: 15/04/2016
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
#define MAXN 100000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

ll n, m, d, x, y, z, a[105], win, ten;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	cin>>tc;
	while (tc--) {
		win = 0;
		cin>>n>>m;
		x = 0;
		for (i=0; i<m; i++) {
			cin>>d;
			x = x * 10ll + d;
		}
		y = 0;
		for (i=0; i<m; i++) {
			cin>>d;
			y = y * 10ll + d;
		}
		for (i=0; i<n; i++) cin>>a[i];
		z = 0;
		ten = 1;
		for (i=0; i<m; i++) {
			z = z * 10ll + a[i];
			ten *= 10ll;
		}
		ten /= 10ll;
		if (x <= z && z <= y) win++;
		for (i=1; i<n; i++) {
			z = (z - a[i-1] * ten) * 10ll + a[(i+m-1)%n];
			if (x <= z && z <= y) win++;
		}
		cout<<win<<endl;
	}
	
	return 0;
}
