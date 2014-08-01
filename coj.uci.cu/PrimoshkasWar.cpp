/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2971
	Name: Primoshkas War
	Number: 2971
	Date: 16/07/2014
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
#define MOD 1000000007LL

using namespace std;

struct Matrix {long long mat[12][12];};

int n, s, c, a, b;
double t[30], h[30], e[30], te[30], act, aux;
vector<int> graph[30];

int main () {
	int i, j, k;
	
	while (scanf("%d %d", &n, &s) != EOF) {
		
		for (i=0; i<n; i++)
			graph[i].clear();
		
		for (i=0; i<n; i++) {
			scanf("%d %d", &a, &b);
			t[i] = ((double) a) / 100.0;
			h[i] = ((double) b) / 100.0;
			e[i] = 1.0-t[i]-h[i];
			te[i] = 0.0;
		}
		
		scanf("%d", &c);
		
		for (i=0; i<c; i++) {
			scanf("%d %d", &a, &b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		
		for (k=0; k<1500; k++) {
			for (i=0; i<n; i++) {
				act = 0.0;
				for (j=0; j<graph[i].size(); j++) {
					aux = e[i] * (t[graph[i][j]]+te[graph[i][j]]);
					if (aux > act) act = aux;
				}
				if (te[i] < act) te[i] = act;
			}
		}
		
		printf("%.6lf\n", t[s]+te[s]);
		
	}
	
	return 0;
}
