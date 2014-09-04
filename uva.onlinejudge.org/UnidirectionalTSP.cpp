/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=52
        Name: Unidirectional TSP
        Number: 116
        Date: 22/08/2014
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
#define MAXN 30005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, m, matrix[11][101], next[11][101], DP[11][101];
ii move[3];

struct cmp {
	bool operator() (const ii &a, const ii &b) {
		if (DP[a.first][b.second] == DP[b.first][b.second])
			return a.first < b.first;
		return DP[a.first][b.second] < DP[b.first][b.second];
	}
}myCmp;

void dp () {
	int i, j;
	for (i=0; i<n; i++) {
		next[i][m-1] = i;
		DP[i][m-1] = matrix[i][m-1];
	}
	for (j=m-2; j>=0; j--) {
		for (i=0; i<n; i++) {
			move[0].first = (i+n-1)%n; move[0].second = j+1;
			move[1].first = i; move[1].second = j+1;
			move[2].first = (i+1)%n; move[2].second = j+1;
			sort(move, move+3, myCmp);
			next[i][j] = move[0].first;
			DP[i][j] = matrix[i][j] + DP[move[0].first][move[0].second];
		}
	}
}

void print () {
	int i, j, mn = MAX_INT, first;
	for (i=0; i<n; i++) {
		if (DP[i][0] < mn) {
			mn = DP[i][0];
			first = i;
		}
	}
	cout<<first+1;
	i = first;
	for (j=0; j<m-1; j++) {
		i = next[i][j];
		cout<<" "<<i+1;
	}
	cout<<endl;
	cout<<mn<<endl;
}

int main () {
	//ios_base::sync_with_stdio(0);
	int i, j;
	
	while (cin>>n>>m) {
		for (i=0; i<n; i++)
			for (j=0; j<m; j++)
				cin>>matrix[i][j];
		dp();
		print();
	}
	
	return 0;
}
