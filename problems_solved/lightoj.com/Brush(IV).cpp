/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1018
        Name: Brush (IV)
        Number: 1018
        Date: 19/08/2014
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
	int x, y;
	point() {x = y = 0;}
	point(int _x, int _y) : x(_x), y(_y) {};
};

int n, DP[(1<<16)], limit;
point p[20];

point to_vec (point a, point b) {
	return point(b.x-a.x, b.y-a.y); }
int cross (point a, point b) {
	return (a.x*b.y - a.y*b.x); }
bool collinear (point p, point q, point r) {
	return cross(to_vec(p, q), to_vec(p, r)) == 0; }

int dp (int bitmask) {
	if (bitmask == limit) return 0;
	if (DP[bitmask] != -1) return DP[bitmask];
	int act, ans;
	for (act=0; (bitmask&(1<<act))!=0; act++);
	ans = dp(bitmask|(1<<act))+1;
	int aux, bm = bitmask, i, j;
	for (i=act+1; i<n; i++) {
		if ((bm&(1<<i)) == 0) {
			aux = bitmask|(1<<act)|(1<<i);
			for (j=i+1; j<n; j++) {
				if (((bm&(1<<j)) == 0) && (collinear(p[act], p[i], p[j]))) {
					aux |= (1<<j);
					bm |= (1<<j);
				}
			}
			ans = min(ans, dp(aux)+1);
		}
	}
	return DP[bitmask] = ans;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	for (int it=1; it<=TC; it++) {
		cin>>n;
		for (i=0; i<n; i++)
			cin>>p[i].x>>p[i].y;
		limit = (1<<n)-1;
		memset(DP, -1, sizeof DP);
		cout<<"Case "<<it<<": "<<dp(0)<<"\n";
	}
	
	return 0;
}
