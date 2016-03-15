/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1266
        Name: The Lottery
        Date: 03/03/2016
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
#define MOD 1000000007ll
#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

ll n, a[15], ans;
int m;

ll gcd (ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

ll lcm (ll a, ll b) {
	return a / gcd(a, b) * b;
}

void dfs (int u, ll num, int cnt) {
	if (num > n) return;
	if (u == m) {
		if (cnt == 0) return;
		if (cnt % 2 == 1) ans -= (n / num);
		else 			  ans += (n / num);
		return;
	}
	dfs(u+1, num, cnt);
	dfs(u+1, lcm(num, a[u]), cnt+1);
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	while (cin>>n>>m) {
		ans = n;
		for (i=0; i<m; i++) cin>>a[i];
		dfs(0, 1ll, 0);
		cout<<ans<<endl;
	}
	
	return 0;
}
