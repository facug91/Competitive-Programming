/*
        By: facug91
        From: http://coj.uci.cu/contest/cproblem.xhtml?pid=3288&cid=1453
        Name: Pascal's Triangle: Sum of Levels
        Date: 06/06/2015
*/
 
#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
#define MOD 1000007
//#define MAXN 10000100
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

int n, m, DP[1005];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(9); //cerr<<fixed<<setprecision(10); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j;
	
	DP[0] = 1;
	for (i=1; i<1005; i++) DP[i] = (DP[i-1] * 2) % MOD;
	for (i=1; i<1005; i++) DP[i] = (DP[i] + DP[i-1]) % MOD;
	while (cin>>m>>n, n != -1 || m != -1) {
		if (m > 0) cout<<(MOD+DP[n]-DP[m-1])%MOD<<"\n";
		else cout<<DP[n]<<"\n";
	}
	
	return 0;
}
