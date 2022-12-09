/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1183
        Name: Fourth Point !!
        Date: 20/11/2015
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
#define DB(x) //cerr << " #" << (#x) << ": " << (x)
#define DBL(x) //cerr << " #" << (#x) << ": " << (x) << endl
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
	int x, y;
	point() {x = y = 0.0;}
	point(double x, double y) : x(x), y(y) {}
};

point a, b, c, d;
int aux1, aux2;
char dot;

point to_vec (const point& a, const point& b) {
	return point(b.x-a.x, b.y-a.y);
}

point scale (const point& v, int s) {
	return point(v.x*s, v.y*s);
}

point translate (const point& p, const point& v) {
	return point(p.x+v.x, p.y+v.y);
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j, k;
	
	while (cin>>aux1>>dot>>aux2) {
		a.x = aux1*10000+aux2*10;
		cin>>aux1>>dot>>aux2;
		a.y = aux1*10000+aux2*10;
		
		cin>>aux1>>dot>>aux2;
		b.x = aux1*10000+aux2*10;
		cin>>aux1>>dot>>aux2;
		b.y = aux1*10000+aux2*10;
		
		cin>>aux1>>dot>>aux2;
		c.x = aux1*10000+aux2*10;
		cin>>aux1>>dot>>aux2;
		c.y = aux1*10000+aux2*10;
		
		cin>>aux1>>dot>>aux2;
		d.x = aux1*10000+aux2*10;
		cin>>aux1>>dot>>aux2;
		d.y = aux1*10000+aux2*10;
		
		if (a.x == c.x && a.y == c.y) {
			swap(a.x, b.x); swap(a.y, b.y);
			swap(c.x, d.x); swap(c.y, d.y);
		} else if (a.x == d.x && a.y == d.y) {
			swap(a.x, b.x); swap(a.y, b.y);
		} else if (b.x == c.x && b.y == c.y) {
			swap(c.x, d.x); swap(c.y, d.y);
		}
		
		d.x = (a.x+c.x)/2;
		d.y = (a.y+c.y)/2;
		d = translate(d, scale(to_vec(d, b), -1));
		if (d.x < 0) {
			cout<<"-";
			d.x *= -1;
		}
		cout<<d.x/10000<<"."<<setfill('0')<<setw(3)<<(d.x/10)%1000<<" ";
		if (d.y < 0) {
			cout<<"-";
			d.y *= -1;
		}
		cout<<d.y/10000<<"."<<setfill('0')<<setw(3)<<(d.y/10)%1000<<endl;
	}
	
	return 0;
}
