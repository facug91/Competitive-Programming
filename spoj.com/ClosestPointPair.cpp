/*
        By: facug91
        From: http://www.spoj.com/problems/CLOPPAIR/
        Name: Closest Point Pair
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
	point(double x, double y) : x(x) , y(y) {}
};

int n, p1, p2;
double x, y, ans, aux;
vector<pair<point, int> > p;

struct cmp1 {
	bool operator() (const pair<point, int>& a, const pair<point, int>& b) {
		return a.F.x < b.F.x;
	}
};

struct cmp2 {
	bool operator() (const pair<point, int>& a, const pair<point, int>& b) {
		if (a.S == b.S) return false;
		return a.F.y < b.F.y;
	}
};
set<pair<point, int>, cmp2> acty;
queue<int> actx;

double dist_point (const point& a, const point& b) {
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	cout<<fixed<<setprecision(6); cerr<<fixed<<setprecision(6); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j, k, l;
	
	cin>>n;
	for (i=0; i<n; i++) {
		cin>>x>>y;
		p.push_back(MP(point(x, y), i));
	}
	sort(p.begin(), p.end(), cmp1());
	ans = (double)INF;
	for (i=0; i<n; i++) {
		while (actx.size() && p[actx.front()].F.x-p[i].F.x > ans) {
			acty.erase(MP(p[actx.front()].F, actx.front()));
			actx.pop();
		}
		auto itr = acty.lower_bound(MP(point(0.0, p[i].F.y-ans), -1));
		while (itr != acty.end() && (*itr).F.y < p[i].F.y+ans) {
			aux = dist_point((*itr).F, p[i].F);
			if (ans > aux) {
				ans = aux;
				p1 = i;
				p2 = (*itr).S;
			}
			itr++;
		}
		acty.insert(MP(p[i].F, i));
		actx.push(i);
	}
	cout<<min(p[p1].S, p[p2].S)<<" "<<max(p[p1].S, p[p2].S)<<" "<<ans<<endl;
	
	return 0;
}
