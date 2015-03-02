/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=3025
        Name: PROSJEK
        Date: 18/02/2015
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
#define find asjkldhakjsdbsakjdb
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n;
ll a, b[105], sum;

int main () {
	ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j;
	
	cin>>n;
	sum = 0;
	bool first = true;
	for (i=1; i<=n; i++) {
		cin>>b[i];
		a = b[i] * (ll)i - sum;
		sum += a;
		if (first) first = false;
		else cout<<" ";
		cout<<a;
	}
	cout<<endl;
	
	return 0;
}
