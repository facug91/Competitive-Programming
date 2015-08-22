/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1266
        Name: Points in Rectangle
        Date: 08/07/2015
*/
 
#include <bits/stdc++.h>
#define y1 nd03dnqwuidg1odbnw9uddu0132d
#define EPS 1e-9
#define MP make_pair
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
#define MOD 1000000007ll
#define MAXN 1001
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

int q, ft[1005][1005], op, x1, y1, x2, y2;
bool marked[1005][1005];

void update (int x, int y) {
	x++; y++;
	int y1;
	while (x <= MAXN) {
		y1 = y;
		while (y1 <= MAXN) {
			ft[x][y1] += 1;
			y1 += (y1 & (-y1));
		}
		x += (x & (-x));
	}
}

int query (int x, int y) {
	x++; y++;
	int y1, ans = 0;
	while (x > 0) {
		y1 = y;
		while (y1 > 0) {
			ans += ft[x][y1];
			y1 -= (y1 & (-y1));
		}
		x -= (x & (-x));
	}
	return ans;
}

int query (int x1, int y1, int x2, int y2) {
	return query(x2, y2) + query(x1-1, y1-1) - query(x1-1, y2) - query(x2, y1-1);
}

int main () {
	int tc, i, j;
	
	scanf("%d", &tc);
	for (int it=1; it<=tc; it++) {
		memset(ft, 0, sizeof ft);
		memset(marked, 0, sizeof marked);
		scanf("%d", &q);
		printf("Case %d:\n", it);
		while (q--) {
			scanf("%d", &op);
			if (op == 0) {
				scanf("%d %d", &x1, &y1);
				if (marked[x1][y1]) continue;
				update(x1, y1);
				marked[x1][y1] = true;
			} else { //op == 1
				scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
				printf("%d\n", query(x1, y1, x2, y2));
			}
		}
	}
	
	return 0;
}
