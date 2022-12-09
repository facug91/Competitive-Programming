/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2514
        Name: Logo 2
        Date: 10/11/2015
*/

#include <bits/stdc++.h>
#define endl "\n"
#define EPS 1e-2
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
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

struct point {
	double x, y;
	point () {x = y = 0.0;}
	point (double x, double y) : x(x) , y(y) {}
};

int n, pos;
double mov[1005];
point curr, tr;
bool dis;
string op[1005], num;

point rotate (const point& p, double theta) {
	return point(p.x * cos(theta) - p.y * sin(theta), p.x * sin(theta) + p.y * cos(theta));
}

double dist_point (const point& a, const point& b) {
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

point scale (const point& v, double s) {
	return point(v.x * s, v.y * s);
}

point translate (const point& p, const point& v) {
	return point(p.x+v.x, p.y+v.y);
}

bool check_angle (double theta) {
	curr = point();
	tr = point(1.0, 0.0);
	mov[pos] = theta;
	for (int i=0; i<n; i++) {
		if (op[i][1] == 't') {
			if (op[i][0] == 'r') tr = rotate(tr, 2.0*M_PI-mov[i]);
			else tr = rotate(tr, mov[i]);
		} else {
			if (op[i][0] == 'b') curr = translate(curr, scale(rotate(tr, M_PI), mov[i]));
			else curr = translate(curr, scale(tr, mov[i]));
		}
	}
	return fabs(curr.x) < EPS && fabs(curr.y) < EPS;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j;
	
	cin>>tc;
	while (tc--) {
		curr = point();
		tr = point(1.0, 0.0);
		cin>>n;
		for (i=0; i<n; i++) {
			cin>>op[i]>>num;
			if (num[0] == '?') {
				if (op[i][1] == 't') {
					pos = i;
					dis = false;
				} else dis = true;
			} else {
				mov[i] = stoi(num);
				if (op[i][1] == 't') {
					mov[i] = mov[i] * M_PI / 180.0;
					if (op[i][0] == 'r') tr = rotate(tr, 2.0*M_PI-mov[i]);
					else tr = rotate(tr, mov[i]);
				} else {
					if (op[i][0] == 'b') curr = translate(curr, scale(rotate(tr, M_PI), mov[i]));
					else curr = translate(curr, scale(tr, mov[i]));
				}
			}
		}
		if (dis) cout<<(int)round(dist_point(curr, point()))<<endl;
		else {
			for (i=0; i<360; i++) if (check_angle(i * M_PI / 180.0)) {
				cout<<i<<endl;
				break;
			}
		}
	}
	
	return 0;
}
