/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1204
        Name: Railway
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
#define MAXN 10005
#define LOGN 14
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<int, ii> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iii> viii; typedef vector<iiii> viiii;

struct point {
	double x, y;
	point () {x = y = 0.0;}
	point (double x, double y) : x(x) , y(y) {}
};

point to_vec (const point& a, const point& b) {
	return point(b.x-a.x, b.y-a.y);
}

point scale (const point& v, const double& s) {
	return point(v.x*s, v.y*s);
}

point translate (const point& p, const point& v) {
	return point(p.x+v.x, p.y+v.y);
}

double dot (const point& a, const point& b) {
	return a.x * b.x + a.y * b.y;
}

double norm_sq (point v) {
	return v.x * v.x + v.y * v.y;
}

double dist_point (const point& a, const point& b) {
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

double dist_to_line_segment (const point& p, const point& a, const point& b, point& c) {
	point ap = to_vec(a, p), ab = to_vec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	if (u < 0.0) {
		c = a;
		return dist_point(p, a);
	}
	if (u > 1.0) {
		c = b;
		return dist_point(p, b);
	}
	c = translate(a, scale(ab, u));
	return dist_point(p, c);
}

int n;
point m, a, b, c, ans;
double dis, aux;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	cout<<fixed<<setprecision(4); cerr<<fixed<<setprecision(4); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j, k;
	
	while (cin>>m.x>>m.y) {
		cin>>n;
		n = (n*2+2)/2;
		cin>>b.x>>b.y;
		dis = DBL_MAX;
		for (i=1; i<n; i++) {
			a = b;
			cin>>b.x>>b.y;
			aux = dist_to_line_segment(m, a, b, c);
			if (aux < dis) {
				dis = aux;
				ans = c;
			}
		}
		cout<<ans.x<<endl<<ans.y<<endl;
	}
	
	return 0;
}
