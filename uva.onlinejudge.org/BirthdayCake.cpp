/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1108
        Name: Birthday Cake
        Date: 11/02/2016
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

int n, side;
ii p[105], ori, curr;
bool ok;

int cross (ii a, ii b) {
	return a.F * b.S - a.S * b.F;
}

bool ccw (ii p, ii q, ii r) {
	return cross(ii(q.F-p.F, q.S-p.S), ii(r.F-p.F, r.S-p.S)) > 0;
}

bool collinear (ii p, ii q, ii r) {
	return cross(ii(q.F-p.F, q.S-p.S), ii(r.F-p.F, r.S-p.S)) == 0;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j, k;
	
	ori = ii(0, 0);
	while (cin>>n, n) {
		for (i=0; i<n*2; i++) cin>>p[i].F>>p[i].S;
		bool done = false;
		for (i=0; i<=500 && !done; i++) for (j=-500; j<=500 && !done; j++) {
			side = 0;
			curr = ii(i, j);
			for (k=0; k<n*2; k++) {
				if (collinear(ori, curr, p[k])) {
					side = 0;
					break;
				}
				if (ccw(ori, curr, p[k])) side++;
			}
			if (side == n) {
				cout<<j<<" "<<-i<<endl;
				done = true;
			}
		}
	}
	
	return 0;
}
