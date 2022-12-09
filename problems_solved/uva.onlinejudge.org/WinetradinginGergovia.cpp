/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1995
        Name: Wine trading in Gergovia
        Date: 09/04/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000000ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

ll n, a[100005], ant, ans;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int i;
	
	while (cin>>n, n) {
		for (i=0; i<n; i++) cin>>a[i];
		ant = ans = 0;
		for (i=0; i<n; i++) {
			ans += abs(ant);
			ant += a[i];
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
