/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=1035
        Name: Sqrt Log Sin
        Date: 19/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
#define MP make_pair
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000
#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n;
ll DP[MAXN];

void dp () {
	DP[0] = 1;
	for (int i=1; i<MAXN; i++) DP[i] = (DP[(int)floor(i-sqrt(i))] + DP[(int)floor(log(i))] + DP[(int)floor(i*sin(i)*sin(i))]) % MOD;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	dp();
	while (cin>>n, n != -1) cout<<DP[n]<<"\n";
	
	return 0;
}
