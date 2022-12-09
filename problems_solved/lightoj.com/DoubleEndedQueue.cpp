/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1212
	Name: Double Ended Queue
	Number: 1212
	Date: 26/07/2014
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

int n, m, x;
deque<int> dq;
char com[25];

int main () {
	int t, i, j;
	
	scanf("%d", &t);
	for (int it=1; it<=t; it++) {
		dq.clear();
		scanf("%d %d", &n, &m);
		printf("Case %d:\n", it);
		for (i=0; i<m; i++) {
			scanf("%s", com);
			if (com[1] == 'u') {
				scanf("%d", &x);
				if (dq.size() < n) {
					if (com[4] == 'R') {
						dq.push_back(x);
						printf("Pushed in right: %d\n", x);
					} else {
						dq.push_front(x);
						printf("Pushed in left: %d\n", x);
					}
				} else printf("The queue is full\n");
			} else {
				if (dq.empty()) printf("The queue is empty\n");
				else {
					if (com[3] == 'R') {
						x = dq.back();
						dq.pop_back();
						printf("Popped from right: %d\n", x);
					} else {
						x = dq.front();
						dq.pop_front();
						printf("Popped from left: %d\n", x);
					}
				}
			}
		}
	}
	
	return 0;
}
