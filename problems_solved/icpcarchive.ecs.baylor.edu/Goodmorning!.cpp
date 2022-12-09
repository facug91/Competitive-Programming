/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=653&page=show_problem&problem=4946
        Name: Good morning!
        Date: 21/02/2015
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int k, g[4][3];
set<int> DP;
set<int>::iterator itr0, itr1;

void dp (int i, int j, int n) {
	if (i < 4 && j < 3 && g[i][j] != -1 && n < 300) {
		if (n == 0 && g[i][j] == 0) return;
		dp(i+1, j, n);
		dp(i, j+1, n);
		n = n * 10 + g[i][j];
		DP.insert(n);
		dp(i, j, n);
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j;
	
	for (i=0; i<3; i++)
		for (j=0; j<3; j++)
			g[i][j] = 3*i+j+1;
	g[3][0] = g[3][2] = -1;
	g[3][1] = 0;
	
	DP.insert(0);
	dp(0, 0, 0);
	
	cin>>TC;
	while (TC--) {
		cin>>k;
		itr0 = DP.lower_bound(k);
		itr1 = itr0;
		itr0--;
		if (abs((*itr0)-k) < abs((*itr1)-k)) cout<<(*itr0)<<endl;
		else cout<<(*itr1)<<endl;
	}
	
	return 0;
}
