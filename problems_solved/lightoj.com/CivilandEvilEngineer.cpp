/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1029
	Name: Civil and Evil Engineer
	Number: 1029
	Date: 22/07/2014
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

int n, u, v, w, p[101], ans[2];
vector<pair<int, pair<int, int> > > edges;

int find_set (int i) {return (p[i] == i) ? i : (p[i] = find_set(p[i]));}

void union_set (int i, int j, int w, int idx) {
	int x = find_set(i);
	int y = find_set(j);
	if (x != y) {
		ans[idx] += w;
		p[y] = x;
	}
}

int main() {
	int t, i, j;
	
	scanf("%d", &t);
	for (int it=1; it<=t; it++) {
		scanf("%d", &n);
		edges.clear();
		
		while (scanf("%d %d %d", &u, &v, &w), u || v || w)
			edges.push_back(make_pair(w, make_pair(u, v)));
		
		sort(edges.begin(), edges.end());
		
		ans[0] = 0;
		for (i=0; i<=n; i++) p[i] = i;
		for (i=0; i<edges.size(); i++)
			union_set(edges[i].second.first, edges[i].second.second, edges[i].first, 0);
		
		ans[1] = 0;
		for (i=0; i<=n; i++) p[i] = i;
		for (i=edges.size()-1; i>=0; i--)
			union_set(edges[i].second.first, edges[i].second.second, edges[i].first, 1);
		
		if ((ans[0]+ans[1]) % 2 == 0) printf("Case %d: %d\n", it, (ans[0]+ans[1])/2);
		else printf("Case %d: %d/2\n", it, ans[0]+ans[1]);
	}
	
	return 0;
} 
