/*
        By: facug91
        From: https://www.facebook.com/hackercup/problem/881509321917182/
        Name: The Price is Correct
        Date: 10/01/2015
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

ll n, p, b[100005], a, f, ans;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j, k;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>n>>p;
		for (i=0; i<n; i++) cin>>b[i];
		a = f = ans = 0;
		for (i=0; i<n; i++) {
			a += b[i];
			while (a > p) a -= b[f++];
			ans += ((ll)i - f + 1ll);
		}
		cout<<"Case #"<<it<<": "<<ans<<endl;
	}
	
	return 0;
}
