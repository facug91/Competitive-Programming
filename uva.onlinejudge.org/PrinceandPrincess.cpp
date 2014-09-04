/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1576
        Name: Prince and Princess
        Number: 10635
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
#define MAXN 250*250+1

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, p, q, a, order[MAXN], seq[MAXN];
set<int> LIS;
set<int>::iterator itr;

int lis () {
	LIS.clear();
	for (int i=1; i<=q; i++) {
		if (order[seq[i]] != 0) {
			itr = LIS.upper_bound(order[seq[i]]);
			if (itr == LIS.end()) LIS.insert(order[seq[i]]);
			else {
				LIS.erase(itr);
				LIS.insert(order[seq[i]]);
			}
		}
	}
	return (int)LIS.size();
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	scanf("%d", &TC);
	for (int it=1; it<=TC; it++) {
		scanf("%d %d %d", &n, &p, &q);
		memset(order, 0, sizeof order);
		p++; q++;
		for (i=1; i<=p; i++) {
			scanf("%d", &a);
			order[a] = i;
		}
		for (i=1; i<=q; i++)
			scanf("%d", seq+i);
		printf("Case %d: %d\n", it, lis());
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

