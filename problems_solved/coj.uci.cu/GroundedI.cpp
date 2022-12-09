/*
        By: facug91
        From: http://coj.uci.cu/contest/cproblem.xhtml?pid=3279&cid=1453
        Name: Grounded I
        Date: 06/06/2015
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

int n, k, ans;
 
void dfs (int idx, int act) {
	if (idx == (1<<n)) {
		if (act == 0) {if (k == 0) ans++;}
		else if (__builtin_popcount(act) == k) ans++;
		return;
	}
	dfs(idx+1, act^idx);
	dfs(idx+1, act);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(9); //cerr<<fixed<<setprecision(10); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j;
	
	while (cin>>n>>k) {
		ans = 0;
		dfs(0, 0);
		cout<<ans<<"\n";
	}
	
	return 0;
}
