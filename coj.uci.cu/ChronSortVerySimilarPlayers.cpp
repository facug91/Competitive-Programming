/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2470
	Name: ChronSort Very Similar Players
	Number: 2470
	Date: 02/08/2014
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
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;

int n, k, name[300005], len;
queue<int> prev[25];
char s[25];
ll ans;

int main () {
	int t, i, j;
	
	scanf("%d %d", &n, &k);
	getchar();
	for (i=0; i<n; i++) {
		gets(s);
		name[i] = strlen(s);
	}
	ans = 0;
	for (i=0; i<n; i++) {
		len = name[i];
		while ((!prev[len].empty()) && (i - prev[len].front() > k)) prev[len].pop();
		ans += ((ll) prev[len].size());
		prev[len].push(i);
	}
	printf("%lld\n", ans);
	
	return 0;
}
