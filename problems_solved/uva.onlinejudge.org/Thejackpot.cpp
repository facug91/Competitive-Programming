/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1625
        Name: The jackpot
        Date: 24/02/2015
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

int n, seq[10005], ans, act;

int main () {
	ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j;
	
	while (cin>>n, n) {
		for (i=0; i<n; i++) cin>>seq[i];
		ans = -INF; act = 0;
		for (i=0; i<n; i++) {
			act = max(act+seq[i], 0);
			if (act > ans) ans = act;
		}
		if (ans > 0) cout<<"The maximum winning streak is "<<ans<<"."<<endl;
		else cout<<"Losing streak."<<endl;
	}
	
	return 0;
}
