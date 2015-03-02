/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4947
        Name: Bricks
        Date: 25/02/2015
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

struct point {
	ll x, y;
	point () {x = y = 0ll;}
	point (ll _x, ll _y) {
		x = _x; y = _y;
	}
};

ll n, dir1, dir2, ans, k;
point p[100005], o, r, act;
char c;

ll cross (const point &a, const point &b) {
	ll aux = a.x * b.y - a.y * b.x;
	if (aux == 0ll) return 0ll;
	if (aux > 0ll) return 1ll;
	else return -1ll;
} 

int main () {
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		cin>>n;
		r = point();
		for (i=0; i<n; i++) {
			cin>>k>>c;
			if (c == 'W') {
				p[i].x = k;
				p[i].y = 0ll;
			} else {
				p[i].x = 0ll;
				p[i].y = k;
			}
			r.x += p[i].x;
			r.y += p[i].y;
		}
		if (r.x == 0ll || r.y == 0ll) cout<<max(r.x, r.y)<<endl;
		else {
			ans = 0ll;
			act = p[0];
			dir1 = cross(r, act);
			for (i=1; i<n; i++) {
				act.x += p[i].x;
				act.y += p[i].y;
				dir2 = cross(r, act);
				if (dir1 != 0ll && dir1 != dir2) {
					if ((p[i].x > 0ll) && ((act.y * r.x) % r.y == 0ll)) ans++;
					if ((p[i].y > 0ll) && ((act.x * r.y) % r.x == 0ll)) ans++;
				}
				dir1 = dir2;
			}
			cout<<ans<<endl;
		}
	}
	
	return 0;
}
