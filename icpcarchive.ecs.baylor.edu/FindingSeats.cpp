/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=294&page=show_problem&problem=1933
        Name: Finding Seats
        Date: 01/04/2016
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
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int r, c, m, RSQ[305][305], ans;
string mat[305];

inline int rsq (int i, int j, int k, int l) {
	return RSQ[k][l] - RSQ[k][j-1] - RSQ[i-1][l] + RSQ[i-1][j-1];
}

int binary_search (int i, int j, int k) {
	int lo = i, hi = r, mid;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		if (rsq(i, j, mid, k) >= m) hi = mid;
		else lo = mid + 1;
	}
	return lo;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j, k;
	
	while (cin>>r>>c>>m, r || c || m) {
		for (i=0; i<r; i++) cin>>mat[i];
		for (i=0; i<r; i++) RSQ[i][0] = 0;
		for (j=0; j<c; j++) RSQ[0][j] = 0;
		for (i=1; i<=r; i++) for (j=1; j<=c; j++)
			RSQ[i][j] = RSQ[i-1][j] + RSQ[i][j-1] - RSQ[i-1][j-1] + (mat[i-1][j-1] == '.');
		ans = INF;
		for (i=1; i<=r; i++) for (j=1; j<=c; j++) for (k=j; k<=c; k++) {
			if (rsq(i, j, r, k) < m) continue;
			ans = min(ans, (binary_search(i, j, k)-i+1)*(k-j+1));
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
