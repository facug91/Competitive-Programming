/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=503
	Name: Dividing coins
	Number: 562
	Date: 28/07/2014
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <iterator>
#include <utility>
#include <list>
#include <stack>
#include <iomanip>
#include <bitset>

#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;

int n, coin[105], DP[105][100005];

int dp (int idx, int dif) {
	if (idx == n) return dif;
	if (DP[idx][dif] != -1) return DP[idx][dif];
	int aux1 = dp(idx+1, dif-coin[idx])-50000;
	int aux2 = dp(idx+1, dif+coin[idx])-50000;
	if (abs(aux1) > abs(aux2)) return DP[idx][dif] = aux2+50000;
	else return DP[idx][dif] = aux1+50000;
}

int main () {
	int t, i, j;
	
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i=0; i<n; i++)
			scanf("%d", coin+i);
		memset(DP, -1, sizeof DP);
		printf("%d\n", abs(dp(0, 50000)-50000));
	}
	
	
	
	
	
	return 0;
}
