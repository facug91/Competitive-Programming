/*
	By: facug91
	From: http://www.codechef.com/problems/RRSUM/
	Name: Sum Queries
	Number: RRSUM
	Date: 20/07/2014
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
//const long double PI = 2*acos(0);

#define INF 1000000000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

ll n, m, q;

int main() {
	int t, i, j;
	
	scanf("%lld %lld", &n, &m);
	
	while (m--) {
		scanf("%lld", &q);
		if (q <= n+1) printf("0\n");
		else {
			if (q > n*2+1) q -= ((q-(n*2+1))*2);
			printf("%lld\n", q-(n+1));
		}
	}
	
	return 0;
} 
