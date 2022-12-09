/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=3077
        Name: Luka is Parking
        Date: 13/02/2015
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int price[4], l, r, t[105], ans;

int main () {
	ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(2);
	int TC, i, j, k;
	
	cin>>price[1]>>price[2]>>price[3];
	price[2] *= 2; price[3] *= 3;
	memset(t, 0, sizeof t);
	for (i=0; i<3; i++) {
		cin>>l>>r;
		for (j=l; j<r; j++) t[j]++;
	}
	ans = 0;
	for (i=0; i<105; i++) ans += price[t[i]];
	cout<<ans<<endl;
	
	return 0;
}
