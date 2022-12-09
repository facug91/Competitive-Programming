/*
        By: facug91
        From: http://lightoj.com/volume_showproblem.php?problem=1418
        Name: Trees on My Island
        Number: 1418
        Date: 09/10/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 131071
//#define MAXN 10000010

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

struct point {
	ll x, y;
	point () {x = y = 0ll;}
	point (int _x, int _y) : x(_x), y(_y) {};
};

int n;
ll x, y;
vector<point> pol;

ll polygon_area () {
	ll ans = 0ll;
	for (int i=0; i<(int)pol.size(); i++) {
		ans += (pol[i].x * pol[(i+1)%(int)pol.size()].y - pol[i].y * pol[(i+1)%(int)pol.size()].x);
	}
	return abs(ans)/2;
}
ll gcd (ll a, ll b) {
	if (a == 0ll) return b;
	return gcd(b%a, a);
}
ll count_lattice_points () {
	ll ans = 0ll;
	for (int i=0; i<(int)pol.size(); i++) {
		ans += gcd(abs(pol[i].x-pol[(i+1)%(int)pol.size()].x), abs(pol[i].y-pol[(i+1)%(int)pol.size()].y));
	}
	return ans;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	for (int it=1; it<=TC; it++) {
		cin>>n;
		for (i=0; i<n; i++) {
			cin>>x>>y;
			pol.push_back(point(x, y));
		}
		cout<<"Case "<<it<<": "<<(polygon_area()-(count_lattice_points()/2ll)+1ll)<<endl;
		
		pol.clear();
	}
	
	return 0;
}
