/*
	By: facug91
	From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2221
	Name: Shrinking Polygons
	Date: 17/10/2015
*/

#include <bits/stdc++.h>
#define next asjkdbg1238dv8ydf38gy832gf8yd
#define prev asjkdbuiqdg783gdiu3dg79832dui
#define EPS 1e-9
#define MP make_pair
#define DB(x) cerr << "#" << (#x) << ": " << (x) << " "
#define DBL(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000007ll
//#define MAXN 10000100

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi; typedef vector<ii> vii;	    typedef vector<iii> viii;

int n, x[10005], sum, len[10005];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	while (cin>>n, n) {
		sum = 0;
		x[0] = 0;
		for (i=1; i<=n; i++) {
			cin>>x[i];
			sum += x[i];
			x[i] = sum;
		}
		bool ok = false;
		int last, ans;
		for (i=n; i>=3; i--) {
			if (sum % i != 0) continue;
			last = 0;
			for (j=1; j<=n; j++) {
				while (x[j]-x[last] > sum/i) last++;
				if (x[j]-x[last] == sum/i) len[j] = len[last] + 1;
				else len[j] = 1;
				if (len[j] == i) {
					ok = true;
					ans = i;
					break;
				}
			}
			if (ok) break;
		}
		if (ok) cout<<n-ans<<endl;
		else cout<<-1<<endl;
	}
	
	return 0;
}
