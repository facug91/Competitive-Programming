/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1040
	Name: Donation
	Number: 1040
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

int n, p[55], size_set[55], v, don;
vector<iii> edges;

int find_set (int i) {return (p[i] == i) ? i : (p[i] = find_set(p[i]));}

void union_set (int i, int j, int w) {
	int x = find_set(i);
	int y = find_set(j);
	if (x != y) {
		p[y] = x;
		size_set[x] += size_set[y];
	} else don += w;
	
}

int main() {
	int t, i, j;
	
	scanf("%d", &t);
	for (int it=1; it<=t; it++) {
		edges.clear();
		scanf("%d", &n);
		for (i=0; i<n; i++) {
			p[i] = i; size_set[i] = 1;
			for (j=0; j<n; j++) {
				scanf("%d", &v);
				edges.push_back(make_pair(v, make_pair(i, j)));
			}
		}
		sort(edges.begin(), edges.end());
		don = 0;
		for (i=0; (i<(int)edges.size()) && (edges[i].first==0); i++);
		for (; i<(int)edges.size(); i++)
			union_set(edges[i].second.first, edges[i].second.second, edges[i].first);
		if (size_set[find_set(0)] == n) printf("Case %d: %d\n", it, don);
		else printf("Case %d: -1\n", it);
	}
	
	return 0;
} 
