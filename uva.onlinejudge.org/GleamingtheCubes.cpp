/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=678
        Name: Gleaming the Cubes
        Date: 28/01/2015
*/

#include <bits/stdc++.h>
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
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, x, y, z, v;
ii setx[1005], sety[1005], setz[1005], ansx, ansy, ansz;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j;
	
	while (cin>>n, n) {
		for (i=0; i<n; i++) {
			cin>>x>>y>>z>>v;
			if (v > 0) {
				setx[i] = ii(x, x+v);
				sety[i] = ii(y, y+v);
				setz[i] = ii(z, z+v);
			} else {
				setx[i] = ii(x+v, x);
				sety[i] = ii(y+v, y);
				setz[i] = ii(z+v, z);
			}
		}
		ansx = setx[0];
		ansy = sety[0];
		ansz = setz[0];
		for (i=1; i<n; i++) {
			ansx.first = max(ansx.first, setx[i].first);
			ansx.second = min(ansx.second, setx[i].second);
			ansy.first = max(ansy.first, sety[i].first);
			ansy.second = min(ansy.second, sety[i].second);
			ansz.first = max(ansz.first, setz[i].first);
			ansz.second = min(ansz.second, setz[i].second);
		}
		if (ansx.first >= ansx.second || ansy.first >= ansy.second || ansz.first >= ansz.second) cout<<0<<endl;
		else cout<<(ansx.second-ansx.first)*(ansy.second-ansy.first)*(ansz.second-ansz.first)<<endl;
	}
	
	return 0;
}
