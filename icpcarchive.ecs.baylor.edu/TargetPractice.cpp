/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1971
        Name: Target Practice
        Date: 03/11/2014
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
	int x, y, z;
	point () {x = y = z = 0;}
	point (int _x, int _y, int _z) : x(_x), y(_y), z(_z) {};
	bool operator==(point &other) const {
		return (x == other.x && y == other.y && z == other.z);
	}
};

int n, x, y, z, ans;
vector<point> points;
vector<ll> line; //used points in this line (more than 2)
set<pair<int, ll> > vis;
bool used[55][55];

point to_vec (const point &a, const point &b) {
	return point(b.x-a.x, b.y-a.y, b.z-a.z);
}
bool cross (const point &a, const point &b) {
	return ((a.y*b.z-a.z*b.y) == 0) && ((a.z*b.x-a.x*b.z) == 0) && ((a.x*b.y-a.y*b.x) == 0);
}
bool collinear (const point &p, const point &q, const point &r) {
	return cross(to_vec(p, q), to_vec(p, r));
}

void make_lines () {
	int i, j, k;
	ll l;
	line.clear();
	bool w;
	memset(used, 0, sizeof used);
	for (i=0; i<n-2; i++) {
		for (j=i+1; j<n-1; j++) {
			if (!used[i][j]) {
				l = (1ll<<i) | (1ll<<j);
				w = false;
				for (k=j+1; k<n; k++) {
					if (collinear(points[i], points[j], points[k])) {
						used[j][k] = true;
						l |= (1ll<<k);
						w = true;
					}
				}
				if (w) line.push_back(l);
			}
		}
	}
}

void search (int idx, ll bitmask, int cant) {
	if (vis.find(make_pair(idx, bitmask)) != vis.end()) return;
	if (idx == (int)line.size()) {
		int aux = 0;
		for (int i=0; i<n; i++)
			if (bitmask & (1ll<<i))
				aux++;
		aux = cant + ((n - aux) / 2) + ((n - aux) % 2);
		if (aux < ans) ans = aux;
		return;
	}
	search(idx+1, bitmask, cant);
	search(idx+1, bitmask|line[idx], cant+1);
	vis.insert(make_pair(idx, bitmask));
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC = 1, i, j;
	
	while (scanf("%d", &n), n) {
		points.clear();
		for (i=0; i<n; i++) {
			scanf("%d %d %d", &x, &y, &z);
			points.push_back(point(x, y, z));
		}
		make_lines();
		ans = MAX_INT;
		vis.clear();
		search(0, 0ll, 0);
		printf("Target set %d can be cleared using only %d shots.\n", TC++, ans);
	}
	
	return 0;
}
