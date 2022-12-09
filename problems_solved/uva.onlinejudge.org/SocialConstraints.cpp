/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2842
	Name: Social Constraints
	Number: 11742
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
//
using namespace std;

int n, m, ans, a, b, c, p[8];
bool used[8];
pair<pair<int, int>, int> cons[21];

bool check () {
	for (int i=0; i<m; i++) {
		for (a=0; p[a] != cons[i].first.first; a++);
		for (b=0; p[b] != cons[i].first.second; b++);
		if (a < b) a ^= b ^= a ^= b; //swap()
		c = cons[i].second;
		
		if (c > 0) {
			if (a-b > c) return false;
		} else {
			if (a-b < -c) return false;
		}
	}
	return true;
}

int main() {
	
	int i, j;
	
	while (scanf("%d %d", &n, &m), n) {
		
		for (i=0; i<m; i++)
			scanf("%d %d %d", &cons[i].first.first, &cons[i].first.second, &cons[i].second);
		
		for (i=0; i<n; i++) p[i] = i;
		ans = 0;
		
		do {
			for (i=0; i<n; i++) 
				cout<<p[i]<<" ";
			cout<<endl;
			if (check()) ans++;
		} while (next_permutation(p, p+n));
		
		printf("%d\n", ans);
		
	}
	
} 
