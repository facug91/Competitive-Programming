/*
	By: facug91
	From: http://www.codechef.com/problems/RRCOPY
	Name: Copy-Paste
	Number: RRCOPY
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

int n, a, ans;
bool used[100005];

int main() {
	int t, i, j;
	
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		ans = 0;
		memset(used, 0, sizeof used);
		for (i=0; i<n; i++){
			scanf("%d", &a);
			if (!used[a]) {
				ans++;
				used[a] = true;
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
} 
