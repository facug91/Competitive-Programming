/*
	By: facug91
	From: http://www.lightoj.com/volume_showproblem.php?problem=1232
	Name: Coin Change (II)
	Date: 20/05/2016
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

int n, k, a[101], DP[10001];

int dp () {
	memset(DP, 0, sizeof DP);
	DP[0] = 1;
	sort(a, a+n);
	for (int i=0; i<n; i++) for (int j=a[i]; j<=k; j++) DP[j] = (DP[j] + DP[j-a[i]]) % MOD;
	return DP[k];
}

int main () {
	//#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	//#endif
	//cout<<fixed<<setprecision(9); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>n>>k;
		for (i=0; i<n; i++) cin>>a[i];
		cout<<"Case "<<it<<": "<<dp()<<endl;
	}
	
	return 0;
}
