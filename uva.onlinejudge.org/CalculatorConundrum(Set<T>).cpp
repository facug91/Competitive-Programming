/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2544
	Name: Calculator Conundrum
	Number: 11549
	Date: 05/07/2014
	Using: set<int>
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

using namespace std;

long long n, k, mod;
set<long long> st;

int main() {
	
	int t;
	
	scanf("%d", &t);
	while (t--) {
		scanf("%lld %lld", &n, &k);
		mod = 1; while (n--) mod *= 10;
		st.insert(k);
		k = k*k;
		while (k >= mod) k /= 10;
		while (st.find(k) == st.end()) {
			st.insert(k);
			k = k*k;
			while (k >= mod) k /= 10;
		}
		printf("%lld\n", *(--(st.end())));
		if (t) st.clear();
	}
	
	return 0;
}
