/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=3076
        Name: The Nikola Game
        Date: 11/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, DP[1005][1005], fee[1005];

int dp (int idx, int prev) {
	if (idx == n-1) return fee[n-1];
	if (idx < 0 || idx >= n) return INF;
	if (DP[idx][prev] != -1) return DP[idx][prev];
	return DP[idx][prev] = min(dp(idx+prev+1, prev+1), dp(idx-prev, prev))+fee[idx];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin>>n;
	for (int i=0; i<n; i++) cin>>fee[i];
	memset(DP, -1, sizeof DP);
	cout<<dp(1, 1)<<"\n";
	
	return 0;
}
