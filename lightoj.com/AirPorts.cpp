/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1059
	Name: Air Ports
	Number: 1059
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

int n, m, a, p[10005], rank[10005], cost, num, x, y, c;
vector<pair<int, pair<int, int> > > edges;
 
int find_set (int i) {return (p[i] == i) ? i : (p[i] = find_set(p[i]));}
 
void union_set (int i, int j, int c) {
    int x = find_set(i);
    int y = find_set(j);
    if (x != y) {
        cost += c; num--;
        if (rank[x] > rank[y]) {
            p[y] = x;
        } else {
            p[x] = y;
            if (rank[y] == rank[x]) rank[y]++;
        }
    }
}
 
int main() {
    int t, i, j;
   
    scanf("%d", &t);
    for (int it=1; it<=t; it++) {
        edges.clear();
        scanf("%d %d %d", &n, &m, &a);
        for (i=0; i<m; i++) {
            scanf("%d %d %d", &x, &y, &c);
            edges.push_back(make_pair(c, make_pair(x, y)));
        }
        for (i=0; i<=n; i++) {
            p[i] = i;
            rank[i] = 0;
        }
        sort(edges.begin(), edges.end());
        cost = 0; num = n;
        for (i=0; (i<(int)edges.size()) && (edges[i].first<a); i++)
            union_set(edges[i].second.first, edges[i].second.second, edges[i].first);
        cost += (num*a);
        printf("Case %d: %d %d\n", it, cost, num);
    }
   
    return 0;
}
