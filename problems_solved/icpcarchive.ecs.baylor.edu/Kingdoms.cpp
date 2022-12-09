/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=4266
        Name: Kingdoms
        Date: 11/07/2015
*/
 
#include <bits/stdc++.h>
#define y1 nd03dnqwuidg1odbnw9uddu0132d
#define EPS 1e-9
#define MP make_pair
#define DEB(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

int n, mat[20][20], survivor[20], money[20];
bool vis[1<<20];

void search (int bitmask) {
	if (bitmask == 0 || vis[bitmask]) return;
	vis[bitmask] = true;
	for (int i=0; i<n; i++) if ((bitmask & (1<<i)) != 0) {
		if (money[i] > 0) {
			for (int j=0; j<n; j++) money[j] += mat[i][j];
			search(bitmask&(~(1<<i)));
			for (int j=0; j<n; j++) money[j] -= mat[i][j];
		} else if ((bitmask&(bitmask-1)) == 0) survivor[i] = true;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tc, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>n;
		for (i=0; i<n; i++) {
			money[i] = 0;
			for (j=0; j<n; j++) {
				cin>>mat[i][j];
				money[i] += mat[i][j];
			}
		}
		memset(survivor, 0, sizeof survivor);
		memset(vis, 0, sizeof vis);
		search((1<<n)-1);
		bool first = true;
		for (i=0; i<n; i++) {
			if (survivor[i]) {
				if (first) first = false;
				else cout<<" ";
				cout<<i+1;
			}
		}
		if (first) cout<<0;
		cout<<"\n";
	}
	
}

