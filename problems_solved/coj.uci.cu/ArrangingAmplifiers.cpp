/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1009
	Name: Arranging Amplifiers
	Number: 1009
	Date: 01/06/2014
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

struct cmp {
	bool operator () (int a, int b) {
		if ((a == 2) && (b == 3)) return false;
		if ((a == 3) && (b == 2)) return true;
		return (a < b);
	}
};

int t, ni, n, ones, first;
priority_queue<int, vector<int>, cmp> q;

int main() {
	
	scanf("%d", &t);
	
	while (t--) {
		
		scanf("%d", &ni);
		
		ones = 0;
		while (ni--) {
			scanf("%d", &n);
			if (n == 1) ones++;
			else q.push(n);
		}
		
		first = true;
		
		if (ones) {
			printf("1");
			ones--;
			first = false;
			while (ones--) printf(" 1");
		}
		
		if (!q.empty()) {
			if (first) {
				printf("%d", q.top());
				q.pop();
			}
			while (!q.empty()) {
				printf(" %d", q.top());
				q.pop();
			}
		}
		printf("\n");
	}
	
} 
