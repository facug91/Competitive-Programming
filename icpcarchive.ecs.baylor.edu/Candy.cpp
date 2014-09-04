/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2213
        Name: Candy
        Number: 4212
        Date: 26/08/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007
//#define MAXN N

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, m, c, arr[100005], DP_row[100005];
vector<int> mat[100005], DP[100005];

int dp_row (int i, int j) {
	if (j >= m) return 0;
	if (DP[i][j] != -1) return DP[i][j];
	return DP[i][j] = mat[i][j] + max(dp_row(i, j+2), dp_row(i, j+3));
}

int dp_column (int i) {
	if (i >= n) return 0;
	if (DP_row[i] != -1) return DP_row[i];
	return DP_row[i] = arr[i] + max(dp_column(i+2), dp_column(i+3));
}

int dp () {
	int i, j;
	for (i=0; i<n; i++)
		arr[i] = max(dp_row(i, 0), dp_row(i, 1));
	return max(dp_column(0), dp_column(1));
}

int main () {
	ios_base::sync_with_stdio(0);
	int i, j;
	
	while (cin>>n>>m, n || m) {
		for (i=0; i<n; i++) {
			mat[i].clear();
			DP[i].clear();
			DP_row[i] = -1;
			for (j=0; j<m; j++) {
				cin>>c;
				mat[i].push_back(c);
				DP[i].push_back(-1);
			}
		}
		cout<<dp()<<endl;
	}
	
	return 0;
}

