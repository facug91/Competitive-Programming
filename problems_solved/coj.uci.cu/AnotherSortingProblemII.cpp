/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=3019
        Name: Another Sorting Problem II
        Date: 01/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 10
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, a, ans;

int main () {
	ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j, l;
	
	cin>>TC;
	while (TC--) {
		cin>>n;
		ans = 0;
		for (i=1; i<=n; i++) {
			cin>>a;
			if (a != i) ans += abs(a-i);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
