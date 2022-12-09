/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1186
        Name: The Closest Pair Problem
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
	point() { x = y = 0.0;}
	point(double x, double y) : x(x), y(y) {}
};


int n;
double x, y, dis;
vector<point> p;

struct cmp1 {
	bool operator() (const point& a, const point& b) {
		return a.x < b.x;
	}
};

struct cmp2 {
	bool operator() (const point& a, const point& b) {
		if (fabs(a.y-b.y) < EPS) return a.x < b.x;
		return a.y < b.y;
	}
};
set<point, cmp2> acty;
queue<int> actx;

double dist_point (const point& a, const point& b) {
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	cout<<fixed<<setprecision(4); cerr<<fixed<<setprecision(4); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j, k, l;
	
	while (cin>>n, n) {
		p.clear();
		for (i=0; i<n; i++) {
			cin>>x>>y;
			p.push_back(point(x, y));
		}
		sort(p.begin(), p.end(), cmp1());
		acty.clear();
		while (actx.size()) actx.pop();
		dis = DBL_MAX;
		for (i=0; i<n; i++) {
			while (actx.size() && (p[i].x-p[actx.front()].x) > dis) {
				acty.erase(p[actx.front()]);
				actx.pop();
			}
			auto itr = acty.lower_bound(point(p[i].x, p[i].y-dis));
			while (itr != acty.end() && p[i].y+dis > (*itr).y) {
				dis = min(dis, dist_point(p[i], (*itr)));
				itr++;
			}
			acty.insert(p[i]);
			actx.push(i);
		}
		if (dis >= 10000.0) cout<<"INFINITY"<<endl;
		else cout<<dis<<endl;
	}
	
	return 0;
}
