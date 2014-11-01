/*
        By: facug91
        From: http://www.spoj.com/problems/PIZZALOC/
        Name: Pizza Location
        Date: 01/11/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

struct point {
	int x, y;
	point () {x = y = 0;}
	point(int _x, int _y) : x(_x), y(_y) {};
};

int k, r, m, s, x, y, people[105];
vector<point> location, solitair;
pair<ll, ll> DP[25];

double dist_point (const point &a, const point &b) {
	return hypot((double)a.x-b.x, (double)a.y-b.y);
}
void dp () {
	int i, j, size = min(s, 64);
	for (i=0; i<m; i++) {
		DP[i].first = DP[i].second = 0ll;
		for (j=0; j<size; j++)
			if (dist_point(location[i], solitair[j]) <= (double)r)
				DP[i].first |= (1ll<<((ll)j));
		for (j=size; j<s; j++)
			if (dist_point(location[i], solitair[j]) <= (double)r)
				DP[i].second |= (1ll<<((ll)j-size));
	}
}

int solve () {
	int i, j, n = (1<<m)-1, x = n, ans = 0, aux, size;
	pair<ll, ll> act;
	while (x) {
		if (__builtin_popcount(x) == k) {
			act.first = act.second = 0;
			for (i=0; i<m; i++) {
				if (x & (1<<i)) {
					act.first |= DP[i].first;
					act.second |= DP[i].second;
				}
			}
			aux = 0;
			size = min(s, 64);
			for (i=0; i<size; i++) {
				if (act.first & (1ll<<((ll)i))) {
					aux += people[i];
				}
			}
			for (i=size; i<s; i++) {
				if (act.second & (1ll<<((ll)i-size))) {
					aux += people[i];
				}
			}
			if (aux > ans) ans = aux;
		}
		x = (x-1) & n;
	}
	return ans;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>k>>r;
	
	cin>>m;
	for (i=0; i<m; i++) {
		cin>>x>>y;
		location.push_back(point(x, y));
	}
	
	cin>>s;
	for (i=0; i<s; i++) {
		cin>>x>>y>>people[i];
		solitair.push_back(point(x, y));
	}
	
	dp();
	
	cout<<solve()<<endl;
	
	return 0;
}
