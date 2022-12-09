/*
	By: facug91
	From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3910
	Name: Tree Count
	Date: 30/04/2016
*/

#include <bits/stdc++.h>
#define endl "\n"
#define next sbjkdfh329re9fdshfd98fyh
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
#define MOD 1000000000ll
#define MAXN 100000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

ll n, DP[1430][20];

ll dp (ll n, ll h) {
	if (h == -1) return (n == 0);
	if (h == 0) return (n == 1);
	if (n == 1) return (h == 0);
	if (DP[n][h] != -1) return DP[n][h];
	ll ans = 0;
	int nn = n - 1;
	for (int i=0; i<=nn; i++)
		ans = (ans + dp(i, h-1) * dp(nn-i, h-1)
				   + dp(i, h-2) * dp(nn-i, h-1)
				   + dp(i, h-1) * dp(nn-i, h-2)) % MOD;
	return DP[n][h] = ans;
} 

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(2); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); 
	
	int tc = 1, i, j;
	
	while (cin>>n) {
		memset(DP, -1, sizeof DP);
		ll ans = 0;
		for (i=0; i<20; i++) ans = (ans + dp(n, i)) % MOD;
		cout<<setfill('0')<<setw(9)<<ans<<endl;
	}
	
	return 0;
}
