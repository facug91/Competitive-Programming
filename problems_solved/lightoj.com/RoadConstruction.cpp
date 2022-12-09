/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1041
	Name: Road Construction
	Number: 1041
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
typedef pair<int, pair<int, int> > iii;

int m, cost, w, p[55], size_set[55], idx;
map<string, int> hash;
vector<iii> edges;
string u, v;

int find_set (int i) {return (p[i] == i) ? i : (p[i] = find_set(p[i]));}

void union_set (int i, int j, int w) {
	int x = find_set(i);
	int y = find_set(j);
	if (x != y) {
		cost += w;
		p[y] = x;
		size_set[x] += size_set[y];
	}
}

int main() {
	int t, i, j;
	
	cin>>t;
	for (int it=1; it<=t; it++) {
		hash.clear();
		edges.clear();
		cin>>m; idx = cost = 0;
		for (i=0; i<m; i++) {
			cin>>u>>v>>w;
			if (hash.find(u) == hash.end()) hash.insert(make_pair(u, idx++));
			if (hash.find(v) == hash.end()) hash.insert(make_pair(v, idx++));
			edges.push_back(make_pair(w, make_pair(hash[u], hash[v])));
		}
		sort(edges.begin(), edges.end());
		for (i=0; i<idx; i++) 
			p[i] = i, size_set[i] = 1;
		for (i=0; i<m; i++)
			union_set(edges[i].second.first, edges[i].second.second, edges[i].first);
		if (size_set[find_set(0)] == idx) printf("Case %d: %d\n", it, cost);
		else printf("Case %d: Impossible\n", it);
	}
	
	return 0;
} 
