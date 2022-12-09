/*
	By: facug91
	From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2808
	Name: Cocircular Points
	Date: 19/10/2015
*/

#include <bits/stdc++.h>
#define next asjkdbg1238dv8ydf38gy832gf8yd
#define prev asjkdbuiqdg783gdiu3dg79832dui
#define EPS 1e-7
#define MP make_pair
#define DB(x) cerr << "#" << (#x) << ": " << (x) << " "
#define DBL(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MINUSINF -10000000000000ll// -10^13
#define MOD 1000000007ll
//#define MAXN 10000100

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi; typedef vector<ii> vii;		   typedef vector<iii> viii;

struct point {
	double x, y;
	point() {x = y = 0.0;}
	point (double _x, double _y) {
		x = _x;
		y = _y;
	}
};

int n;
vector<point> pts;
double x, y;

double dist (const point& a, const point& b) {
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

bool circum_circle (const point& p1, const point& p2, const point& p3, point& ctr, double& r){ 
	double a = p2.x - p1.x, b = p2.y - p1.y; 
	double c = p3.x - p1.x, d = p3.y - p1.y; 
	double e = a * (p1.x + p2.x) + b * (p1.y + p2.y); 
	double f = c * (p1.x + p3.x) + d * (p1.y + p3.y); 
	double g = 2.0 * (a * (p3.y - p2.y) - b * (p3.x - p2.x)); 
	if (fabs(g) < EPS) return false; 
	ctr.x = (d*e - b*f) / g; 
	ctr.y = (a*f - c*e) / g; 
	r = dist(p1, ctr); 
	return true;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j, k, l;
	
	while (cin>>n, n) {
		pts.clear();
		for (i=0; i<n; i++) {
			cin>>x>>y;
			pts.push_back(point(x, y));
		}
		double r;
		point c;
		int ans = 2, cnt;
		for (i=0; i<n-2; i++) {
			for (j=i+1; j<n-1; j++) {
				for (k=j+1; k<n; k++) {
					if (!circum_circle(pts[i], pts[j], pts[k], c, r)) continue;
					cnt = 3;
					for (l=k+1; l<n; l++) if (fabs(dist(pts[l], c) - r) < EPS) cnt++;
					ans = max(ans, cnt);
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
