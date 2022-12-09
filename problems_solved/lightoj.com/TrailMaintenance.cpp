/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1123
	Name: Trail Maintenance
	Number: 1123
	Date: 23/07/2014
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
typedef pair<int, pair<int, int> > iii;

int n, w, p[205], num, length, u, v, l;
set<iii> edges;
set<iii>::iterator itrs, aux;

int find_set (int i) {return (p[i] == i) ? i : (p[i] = find_set(p[i]));}

bool union_set (int i, int j, int l) {
	int x = find_set(i);
	int y = find_set(j);
	if (x != y) {
		length += l; num--;
		p[y] = x;
		return false;
	}
	return true;
}

int main() {
	int t, i, j;
	
	scanf("%d", &t);
	for (int it=1; it<=t; it++) {
		edges.clear();
		scanf("%d %d", &n, &w);
		printf("Case %d:\n", it);
		for (j=0; j<w; j++) {
			scanf("%d %d %d", &u, &v, &l);
			edges.insert(make_pair(l, make_pair(u, v)));
			num = n; length = 0;
			for (i=1; i<=n; i++) p[i] = i;
			itrs=edges.begin();
			while ((itrs!=edges.end()) && (num != 1)) {
				if (union_set((*itrs).second.first, (*itrs).second.second, (*itrs).first)) {
					aux = itrs;
					itrs--;
					edges.erase(aux);
				}
				itrs++;
			}
			if (num == 1) printf("%d\n", length);
			else printf("-1\n");
		}
	}
	
	return 0;
} 
