/*
        By: facug91
        From: 
        Name: Numeric Center I
        Date: 09/06/2015
*/
 
#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10000100
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

int n, DP[1000005];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j;
	
	for (ll act=2ll; act<1000005ll; act++) {
		ll sum = (act*(act-1ll))+act;
		ll n = (ll)((-1.0 + sqrt(1+sum*8.0))/2.0);
		if ((n*(n+1ll))/2ll == sum && n < 1000005ll) DP[n] = 1;
	}
	for (i=1; i<1000005; i++) DP[i] += DP[i-1];
	while (cin>>n, n) cout<<DP[n]<<"\n";
	
	return 0;
}
