/*
	By: facug91
	From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1141
	Name: Prime Time
	Date: 12/02/2016
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define endl "\n"
#define DB(x) cerr << "#" << (#x) << ": " << (x) << " "
#define DBL(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10000100

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi; typedef vector<ii> vii;		   typedef vector<iii> viii;

int dp[10005], a, b;

bool isPrime (int n) {
	int i = 3;
	if (n % 2 == 0) return false;
	while (i*i <= n) {
		if (n % i == 0) return false;
		i += 2;
	}
	return true;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(4); cerr<<fixed<<setprecision(4); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j;
	
	dp[0] = 1;
	dp[1] = 2;
	for (i=2; i<10005; i++) {
		if (isPrime(i*i+i+41)) dp[i] = 1;
		else dp[i] = 0;
		dp[i] += dp[i-1];
	}
	int ans;
	while (cin>>a>>b) {
		if (b == 0) ans = 1;
		else if (a == 0) ans = dp[b];
		else ans = dp[b]-dp[a-1];
		cout<<fixed<<setprecision(2)<<round(ans/(b-a+1.0)*10000.0)/100.0<<endl;
	}
	
	return 0;
}
