/*
	By: facug91
	From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5244
	Name: Path
	Date: 26/04/2016
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
//#define MOD 1000000007ll
#define MAXN 100000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

struct point {
	ll x, y;
	point () {x = y = 0;}
	point (int x, int y) : x(x), y(y) {}
};

struct point_s {
	point p;
	bool bbx;
	int idx;
	point_s () {bbx = idx = 0;}
	point_s (point p, bool bbx, int idx) : p(p), bbx(bbx), idx(idx) {}
};

int n, m;
ll x, y, k, d;
double dis[100005], ans;
vector<point> v, s;
vector<point_s> setp, curr;

bool cmp (const point_s& a, const point_s& b) {
	if (a.p.x == b.p.x) {
		if (a.bbx && b.bbx) return a.idx > b.idx;
		else if (a.idx == b.idx) return b.bbx;
		else return a.idx > b.idx;
	}
	return a.p.x < b.p.x;
}

point to_vec (point a, point b) {
	return point(b.x-a.x, b.y-a.y);
}

ll cross (point a, point b) {
	return a.x*b.y - a.y*b.x;
}

bool ccw (point p, point q, point r) {
	return cross(to_vec(p, q), to_vec(p, r)) < 0;
}

double point_distance (point a, point b) {
	return sqrt((double)((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}

point_s ternary_search (point p) {
	int lo = 0, hi = curr.size()-1, mid1, mid2;
	ll cp1, cp2;
	while (lo != hi) {
		mid1 = lo+(hi-lo)/3;
		mid2 = lo+(hi-lo)*2/3;
		if (mid1 == mid2) mid2++;
		if (!ccw(curr[mid1].p, curr[mid2].p, p)) lo = mid1+(mid1==lo);
		else hi = mid2-(mid2==hi);
	}
	return curr[lo];
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	cout<<fixed<<setprecision(1); //cerr<<fixed<<setprecision(1); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	cin>>tc;
	while (tc--) {
		setp.clear();
		cin>>n;
		v.clear();
		for (i=0; i<n; i++) {
			cin>>x>>y;
			v.push_back(point(x, y));
			if (i != 0) setp.push_back(point_s(v.back(), true, i));
		}
		v.push_back(v[0]);
		setp.push_back(point_s(v.back(), true, n));
		cin>>m;
		s.clear();
		for (i=0; i<m; i++) {
			cin>>k>>d;
			if (v[k].x == v[k+1].x) {
				s.push_back(point(v[k].x, v[k].y+d*((v[k].y<v[k+1].y)?1:-1)));
			} else {
				s.push_back(point(v[k].x+d*((v[k].x<v[k+1].x)?1:-1), v[k].y));
			}
			setp.push_back(point_s(s.back(), false, k));
		}
		sort(setp.begin(), setp.end(), cmp);
		curr.clear();
		curr.push_back(setp[0]);
		dis[curr[0].idx] = 0.0;
		ans = 0.0;
		for (i=1; i<setp.size(); i++) {
			if (setp[i].bbx) {
				while (curr.size() > 1 && ccw(curr[curr.size()-2].p, curr.back().p, setp[i].p)) {
					curr.pop_back();
				}
				dis[setp[i].idx] = dis[curr.back().idx] + point_distance(curr.back().p, setp[i].p);
				curr.push_back(setp[i]);
			} else {
				point_s ps = ternary_search(setp[i].p);
				ans += dis[ps.idx] + point_distance(ps.p, setp[i].p);
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
