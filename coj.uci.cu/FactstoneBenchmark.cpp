/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=3171
        Name: Factstone Benchmark
        Date: 28/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, DP[] = {3, 5, 8, 12, 20, 34, 57, 98, 170, 300, 536, 966, 1754, 3210, 5910, 10944, 20366, 38064, 71421, 134480, 254016};

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	while (cin>>n, n) cout<<DP[(n/10)-196]<<"\n";
	
	return 0;
}
