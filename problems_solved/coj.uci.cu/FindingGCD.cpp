/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2857
        Name: Finding GCD
        Date: 04/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, a, con[1000005], ans, k;

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	memset(con, 0, sizeof con);
	while (cin>>n) con[n]++;
	for (i=1; i<=1000000; i++) {
		k = 0;
		for (j=i; j<=1000000; j+=i) k += con[j];
		if (k > 1) ans = i;
	}
	cout<<ans<<endl;
	
	return 0;
}
