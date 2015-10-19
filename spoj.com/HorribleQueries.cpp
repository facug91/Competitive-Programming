/*
	By: facug91
	From: http://www.spoj.com/problems/HORRIBLE/
	Name: Horrible Queries
	Number: 8002
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

int n, c, op, p, q;
ll ft1[100005], ft2[100005], v;

ll rsq (ll *ft, int b) {
	ll sum = 0;
	for (; b; b-=(b&(-b)))
		sum += ft[b];
	return sum;
}
ll rsq (int b) {
	return rsq(ft1, b) * b - rsq(ft2, b);
}
ll rsq (int a, int b) {
	return rsq(b) - rsq(a-1);
}

void update (ll *ft, int k, ll v) {
	for (; k<=n; k+=(k&(-k)))
		ft[k] += v;
}
void update_range (int a, int b, ll v) {
	update(ft1, a, v);
	update(ft1, b+1, -v);
	update(ft2, a, v*(a-1));
	update(ft2, b+1, (-v)*b);
}

int main() {
	int t, i, j;
	
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &c);
		for (i=0; i<=n; i++)
			ft1[i] = ft2[i] = 0;
		for (i=0; i<c; i++) {
			scanf("%d %d %d", &op, &p, &q);
			if (op == 0) {
				scanf("%lld", &v);
				update_range(p, q, v);
			} else {
				printf("%lld\n", rsq(p, q));
			}
		}
		
	}
	
	return 0;
} 
