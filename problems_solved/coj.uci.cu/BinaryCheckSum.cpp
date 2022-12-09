/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2380
	Name: BinaryCheckSum
	Number: 2380
	Date: 30/06/2014
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
#define _log2(x) log(x) * 1.44269504088896340736
//const long double PI = 2*acos(0);

#define INF 1000000000
//
using namespace std;

int n, k, ans;

int main() {
	
	scanf("%d", &n);
	ans = 0;
	while (n--) {
		scanf("%d", &k);
		while (k) {
			ans += (k&1);
			k >>= 1;
		}
	}
	printf("%d\n", ans);
	
	return 0;
}
