/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=137
        Name: Squares
        Date: 12/02/2016
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

int n, m, x, y, r[10][10], d[10][10];
bool h[10][10], v[10][10];
char op;

int dfsH (int x, int y) {
	if (d[x][y] != 0) return d[x][y];
	if (x < n && v[x][y]) return d[x][y] = dfsH(x+1, y) + 1;
	return 0;
}

int dfsV (int x, int y) {
	if (r[x][y] != 0) return r[x][y];
	if (y < n && h[x][y]) return r[x][y] = dfsV(x, y+1) + 1;
	return 0;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j, k;
	
	while (cin>>n>>m) {
		if (tc > 1) cout<<endl<<"**********************************"<<endl<<endl;
		memset(h, 0, sizeof h);
		memset(v, 0, sizeof v);
		memset(r, 0, sizeof r);
		memset(d, 0, sizeof d);
		for (i=0; i<m; i++) {
			cin>>op>>x>>y; x--; y--;
			if (op == 'H') h[x][y] = true;
			else v[y][x] = true;
		}
		for (i=0; i<n; i++) for (j=0; j<n; j++) {
			dfsH(i, j);
			dfsV(i, j);
		}
		cout<<"Problem #"<<tc++<<endl<<endl;
		bool some = false;
		int ans;
		for (int k=1; k<=n; k++) {
			ans = 0;
			for (i=0; i<n; i++) for (j=0; j<n; j++)
				if (d[i][j] >= k && r[i][j] >= k && r[i+k][j] >= k && d[i][j+k] >= k) ans++;
			if (ans > 0) {
				some = true;
				cout<<ans<<" square (s) of size "<<k<<endl;
			}
		}
		if (!some) cout<<"No completed squares can be found."<<endl;
	}
	
	return 0;
}
