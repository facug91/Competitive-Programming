/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=209
        Name: Jack Straws
        Date: 26/02/2016
*/

#include <bits/stdc++.h>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
#define MOD 1000000007ll
//#define MAXN 10005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

struct point {
	int x, y;
	point() { x = y = 0; }
	point(int x, int y) : x(x) , y(y) {}
};

int n, a, b, comp[15];
pair<point, point> seg[15];
vi adj[15];

point to_vec (point a, point b) {
	return point(b.x-a.x, b.y-a.y);
}

int cross (point a, point b) {
	return a.x*b.y - a.y*b.x;
}

bool inside (const point &p, const point &q, const point &r) {
	return min(p.x, q.x) <= r.x && r.x <= max(p.x, q.x) && min(p.y, q.y) <= r.y && r.y <= max(p.y, q.y);
}

bool segment_intersect (const point &p1, const point &p2, const point &p3, const point &p4) {
	int d1 = cross(to_vec(p1, p2), to_vec(p1, p3));
	int d2 = cross(to_vec(p1, p2), to_vec(p1, p4));
	int d3 = cross(to_vec(p3, p4), to_vec(p3, p1));
	int d4 = cross(to_vec(p3, p4), to_vec(p3, p2));
	if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) &&
	   ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))) return true;
	if ((d1 == 0 && inside(p1, p2, p3)) || (d2 == 0 && inside(p1, p2, p4)) ||
	   (d3 == 0 && inside(p3, p4, p1)) || (d4 == 0 && inside(p3, p4, p2))) return true;
	return false;
}

void dfs (int u, int c) {
	comp[u] = c;
	for (int v : adj[u]) if (comp[v] == -1) dfs(v, c);
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>n;
		for (i=0; i<n; i++) {
			cin>>seg[i].F.x>>seg[i].F.y>>seg[i].S.x>>seg[i].S.y;
			adj[i].clear();
			comp[i] = -1;
		}
		for (i=0; i<n; i++) for (j=i+1; j<n; j++) if (segment_intersect(seg[i].F, seg[i].S, seg[j].F, seg[j].S)) {
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
		memset(comp, -1, sizeof comp);
		for (i=0; i<n; i++) if (comp[i] == -1) dfs(i, i);
		while (cin>>a>>b, a || b) {
			a--; b--;
			if (comp[a] == comp[b]) cout<<"CONNECTED"<<endl;
			else cout<<"NOT CONNECTED"<<endl;
		}
		if (tc) cout<<endl;
	}
	
	return 0;
}
