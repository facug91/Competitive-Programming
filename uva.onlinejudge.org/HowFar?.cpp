/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1407
        Name: How Far?
        Date: 12/11/2015
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

point translate (const point& p, const point& v) {
	return point(p.x+v.x, p.y+v.y);
}

double dist_point (const point& a, const point& b) {
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

point rotate (const point& p, double theta) {
	return point(p.x*cos(theta) - p.y*sin(theta), p.x*sin(theta) + p.y*cos(theta));
}

int n;
double T, b[55], t[55], r;
point u, v;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	cout<<fixed<<setprecision(4); cerr<<fixed<<setprecision(4); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j, k;
	
	while (cin>>n>>T) {
		for (i=0; i<n; i++) cin>>b[i]>>t[i];
		v = point();
		for (i=0; i<n; i++) {
			if (i > 0) cout<<" ";
			u = v;
			v = point(b[i], 0.0);
			r = T*2.0*M_PI/t[i];
			v = translate(rotate(v, r), u);
			cout<<dist_point(point(), v);
		}
		cout<<endl;
	}
	
	return 0;
}
