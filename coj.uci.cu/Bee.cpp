/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=1181
        Name: Bee
        Date: 13/05/2015
*/

#include <bits/stdc++.h>
#define left oiufg3782fdbeiwfdt2389dfa
#define right jsadh93dbh9d3hdgsakhdg973dh
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000003ll
//#define MAXN 5000050

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef vector<int> vi;    typedef vector<ii> vii;

ll n, m, t;
vector<ll> DP;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(2); //cerr<<fixed<<setprecision(10); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	DP.push_back(0);
	DP.push_back(1);
	i = 2;
	while (DP[i-1]+DP[i-2] <= (1ll<<32ll)) {
		DP.push_back(DP[i-1]+DP[i-2]);
		i++;
	}
	for (i=1; i<DP.size(); i++) DP[i] += DP[i-1];
	while (cin>>n, n!=-1) cout<<DP[n]<<" "<<DP[n+1]<<"\n";
	
	return 0;
}
