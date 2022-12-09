/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5217
        Name: Cake cut
        Date: 16/11/2015
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
	ll x, y;
	point() {x = y = 0.0;}
	point(double x, double y) : x(x), y(y) {}
};

int n;
ll x, y, t, ans;
vector<point> p;

ll cross (const point& a, const point& b) {
	return a.x * b.y - a.y * b.x;
}

ll area () {
	ll ans = 0;
	for (int i=0; i<p.size()-1; i++) {
		ans += cross(p[i], p[i+1]);
	}
	return fabs(ans);
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j, k, l;
	
	while (cin>>n) {
		p.clear();
		for (i=0; i<n; i++) {
			cin>>x>>y;
			p.push_back(point(x, y));
		}
		p.push_back(p.front());
		t = area();
		p.pop_back();
		int a = 0, b = 2;
		ll act = cross(p[0], p[1]) + cross(p[1], p[2]) + cross(p[2], p[0]), aux;
		ans = 0;
		for (; a<n; a++) {
			b++;
			aux = act - cross(p[(b-1)%n], p[a]) + cross(p[(b-1)%n], p[b%n]) + cross(p[b%n], p[a]);
			while ((b+1)%n != a && max(abs(t-abs(aux)), aux) < max(abs(t-abs(act)), act)) {
				act = aux;
				b++;
				aux = act - cross(p[(b-1)%n], p[a]) + cross(p[(b-1)%n], p[b%n]) + cross(p[b%n], p[a]);
			}
			b--;
			if ((b-1)%n == a) {
				b++;
				aux = act - cross(p[(b-1)%n], p[a]) + cross(p[(b-1)%n], p[b%n]) + cross(p[b%n], p[a]);
				act = aux;
			}
			ans = max(ans, max(abs(t-abs(act)), act));
			act = act - cross(p[b%n], p[a]) - cross(p[a], p[(a+1)%n]) + cross(p[b%n], p[(a+1)%n]);
		}
		cout<<ans<<" "<<t-ans<<endl;
	}
	
	return 0;
}
