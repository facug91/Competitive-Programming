/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=774
        Name: Water Falls
        Date: 18/11/2015
*/
 
#include <bits/stdc++.h>
#define y1		nd03dnqwuidg1odbnw9uddu0132d
#define clock	asoudh219udhjdgausdhs9udy433
#define left	dfgag34gsfaf342rf23fgwrf42ff
#define middle	lk78k6ujkj76kjk88kkummnhh456
#define right	apidwcojbl213f80sjb3y8efjfas
#define move	df53y5fgsf43fdsfsdtg4j6hfdg4
#define count	nkwdfj111afbjdfsbj32r8yfwejb
#define prev	asdnklgbgbjfasdbhksdva4t9jds
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10005
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<int, ii> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iii> viii; typedef vector<iiii> viiii;

struct point {
	double x, y;
	point() {x = y = 0.0;}
	point(double x, double y) : x(x), y(y) {}
};

struct segment {
	point p1, p2;
	bool type;
	double a, c;
	segment() {
		p1 = point();
		p2 = point();
		type = true;
		a = c = 1.0;
	}
	segment(point p1, point p2, bool type) : p1(p1), p2(p2), type(type) {
		if (fabs(p1.x-p2.x) >= EPS) {
			a = -(p1.y - p2.y) / (p1.x - p2.x);
			c = -(a * p1.x) - p1.y;
			a = -a;
			c = -c;
		} else {
			a = 0.0;
			c = p1.y;
		}
	}
};

int n, m;
double x1, y1, x2, y2;
vector<segment> seg;
vi adj[100005], DP;

bool cmp1 (const pair<double, int>& s1, const pair<double, int>& s2) {
	if (fabs(s1.F-s2.F) < EPS) return seg[s1.S].type;
	return s1.F < s2.F;
}
vector<pair<double, int> > p;

double x;
struct cmp2 {
	bool operator()(int i, int j)  {
		if (i == j) return false;
		return seg[i].a*x+seg[i].c > seg[j].a*x+seg[j].c;
	}
};
set<int, cmp2> act;

int dp (int u) {
	if (DP[u] != -1) return DP[u];
	if (adj[u].size() == 0) return DP[u] = (int)((seg[u].p1.y < seg[u].p2.y) ? seg[u].p1.x : seg[u].p2.x);
	return DP[u] = dp(adj[u][0]);
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j, k, l;
	
	cin>>tc;
	while (tc--) {
		cin>>n;
		seg.clear();
		p.clear();
		DP.clear();
		for (i=0; i<n; i++) {
			DP.push_back(-1);
			cin>>x1>>y1>>x2>>y2;
			if (x1 < x2) {
				seg.push_back(segment(point(x1, y1), point(x2, y2), true));
				p.push_back(MP(x1, i*2));
				p.push_back(MP(x2, i*2+1));
			} else {
				seg.push_back(segment(point(x2, y2), point(x1, y1), true));
				p.push_back(MP(x2, i*2));
				p.push_back(MP(x1, i*2+1));
			}
		}
		cin>>m;
		for (i=0; i<m; i++) {
			DP.push_back(-1);
			cin>>x1>>y1;
			seg.push_back(segment(point(x1, y1), point(x1, y1), false));
			p.push_back(MP(x1, (i+n)*2));
		}
		for (i=0; i<n+m; i++) adj[i].clear();
		sort(p.begin(), p.end(), cmp1);
		for (i=0; i<p.size(); i++) {
			int u = p[i].second/2;
			if (seg[u].type) {
				if (p[i].second % 2 == 1) {
					x = seg[u].p2.x;
					if (seg[u].p2.y < seg[u].p1.y) {
						auto v = act.upper_bound(u);
						if (v != act.end()) {
							adj[u].push_back(*v);
						}
					}
					act.erase(u);
				} else {
					x = seg[u].p1.x;
					if (seg[u].p1.y < seg[u].p2.y) {
						auto v = act.upper_bound(u);
						if (v != act.end()) adj[u].push_back(*v);
					}
					act.insert(u);
				}
			} else {
				x = seg[u].p1.x;
				auto v = act.upper_bound(u);
				if (v != act.end()) adj[u].push_back(*v);
			}
		}
		for (i=n; i<n+m; i++) cout<<dp(i)<<endl;
		if (tc != 0) cout<<endl;
	}
	
	
	return 0;
}
