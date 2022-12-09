/*
	By: facug91
	From: http://www.lightoj.com/volume_showproblem.php?problem=1307
	Name: Counting Triangles
	Date: 24/05/2016
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
#define MOD 100000007
//#define MAXN 30015

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, t[2005], ans;

int main () {
	//#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	//#endif
	//cout<<fixed<<setprecision(9); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j, k;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>n;
		for (i=0; i<n; i++) cin>>t[i];
		sort(t, t+n);
		ans = 0;
		for (j=1; j<n-1; j++) {
			k = n-1;
			for (i=j-1; i>=0; i--) {
				while (t[i]+t[j] <= t[k] && j < k) k--;
				ans += k-j;
			}
		}
		cout<<"Case "<<it<<": "<<ans<<endl;
	}
	
	return 0;
}
