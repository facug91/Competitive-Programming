/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1764
        Name: Of Circles and Squares
        Date: 15/02/2016
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
#define MOD 1000000007ll
//#define MAXN 10005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, p, t[105], x[105], y[105], l[105], r[105], g[105], b[105], xx, yy, rr, gg, bb, m;
string ot;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		if (it > 1) cout<<endl;
		cin>>n>>p;
		for (i=0; i<n; i++) {
			cin>>ot>>x[i]>>y[i]>>l[i]>>r[i]>>g[i]>>b[i];
			t[i] = (ot[0] == 'S');
		}
		cout<<"Case "<<it<<":"<<endl;
		for (i=0; i<p; i++) {
			cin>>xx>>yy;
			m = rr = gg = bb = 0;
			for (j=0; j<n; j++) {
				if (t[j] == 0) {
					if ((xx-x[j])*(xx-x[j])+(yy-y[j])*(yy-y[j]) == l[j]*l[j]) {
						rr = gg = bb = 0;
						m = 1;
						break;
					} else if ((xx-x[j])*(xx-x[j])+(yy-y[j])*(yy-y[j]) < l[j]*l[j]) {
						m++;
						rr += r[j];
						gg += g[j];
						bb += b[j];
					}
				} else {
					if (((xx == x[j] || xx == x[j]+l[j]) && y[j] <= yy && yy <= y[j]+l[j]) ||
						((yy == y[j] || yy == y[j]+l[j]) && x[j] <= xx && xx <= x[j]+l[j])) {
						rr = gg = bb = 0;
						m = 1;
						break;
					} else if (y[j] < yy && yy < y[j]+l[j] && x[j] < xx && xx < x[j]+l[j]) {
						m++;
						rr += r[j];
						gg += g[j];
						bb += b[j];
					}
				}
			}
			if (m == 0) cout<<"(255, 255, 255)"<<endl;
			else cout<<"("<<(int)round(rr/(double)m)<<", "<<(int)round(gg/(double)m)<<", "<<(int)round(bb/(double)m)<<")"<<endl;
		}
	}
	
	return 0;
}
