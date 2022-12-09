/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=3026
        Name: KLOPKA
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

int n, l, r, t, b, x, y;

int main () {
	//ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j, l;
	
	cin>>n;
	l = b = INT_MAX;
	r = t = 0;
	while (n--) {
		cin>>x>>y;
		l = min(l, x);
		r = max(r, x);
		b = min(b, y);
		t = max(t, y);
	}
	cout<<max((r-l), (t-b))*max((r-l), (t-b))<<endl;
	
	return 0;
}
