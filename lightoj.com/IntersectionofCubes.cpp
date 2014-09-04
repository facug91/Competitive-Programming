/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1211
        Name: Intersection of Cubes
        Number: 1211
        Date: 16/08/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;

struct point {
	int x, y, z;
	point() {x = y = z = 0;}
	point(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {};
};

int n;
point p1, p2, pi, pj;

int main () {
	ios_base::sync_with_stdio(0);
	int t, i, j;
	
	cin>>t;
	for (int it=1; it<=t; it++) {
		cin>>n;
		pi.x = pi.y = pi.z = 0;
		pj.x = pj.y = pj.z = 1001;
		for (i=0; i<n; i++) {
			cin>>p1.x>>p1.y>>p1.z>>p2.x>>p2.y>>p2.z;
			pi.x = max(min(p1.x, p2.x), pi.x);
			pj.x = min(max(p1.x, p2.x), pj.x);
			pi.y = max(min(p1.y, p2.y), pi.y);
			pj.y = min(max(p1.y, p2.y), pj.y);
			pi.z = max(min(p1.z, p2.z), pi.z);
			pj.z = min(max(p1.z, p2.z), pj.z);
		}
		if (pi.x >= pj.x || pi.y >= pj.y || pi.z >= pj.z) cout<<"Case "<<it<<": 0\n";
		else cout<<"Case "<<it<<": "<<(pj.x-pi.x)*(pj.y-pi.y)*(pj.z-pi.z)<<endl;
	}
	
	return 0;
}
