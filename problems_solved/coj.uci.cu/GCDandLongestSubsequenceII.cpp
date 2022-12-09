/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2897
        Name: GCD and Longest Subsequence II
        Date: 07/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl;
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, a, factor[105], DP[105][1<<9], primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};

int dp (int idx, int bitmask) {
	if (idx == n) return 0;
	if (DP[idx][bitmask] != -1) return DP[idx][bitmask];
	if ((bitmask & factor[idx]) == 0) return DP[idx][bitmask] = max(dp(idx+1, bitmask), dp(idx+1, bitmask|factor[idx])+1);
	else return DP[idx][bitmask] = dp(idx+1, bitmask);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int i, j;
	
	cin>>n;
	for (i=0; i<n; i++) {
		cin>>a;
		factor[i] = 0;
		for (j=0; j<9; j++)
			if (a % primes[j] == 0)
				factor[i] |= (1<<j);
	}
	memset(DP, -1, sizeof DP);
	cout<<dp(0, 0)<<endl;
	
	return 0;
}
