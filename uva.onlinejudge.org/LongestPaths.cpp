/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=941
        Name: Longest Paths
        Number: 10000
        Date: 09/10/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 131071
//#define MAXN 10000010

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, s, p, q;
vector<int> graph[105];
ii DP[105], ans;

ii dp (int idx) {
	if (DP[idx].first != -1) return DP[idx];
	ii ans = ii(0, idx), aux;
	for (int i=0; i<(int)graph[idx].size(); i++) {
		aux = dp(graph[idx][i]);
		aux.first++;
		if (aux.first > ans.first) {
			ans = aux;
		} else if (aux.first == ans.first) {
			if (aux.second < ans.second) {
				ans.second = aux.second;
			}
		}
	}
	return DP[idx] = ans;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC = 1, i, j;
	
	while (cin>>n, n) {
		for (i=1; i<=n; i++) {
			graph[i].clear();
		}
		cin>>s;
		while (cin>>p>>q, p || q) {
			graph[p].push_back(q);
		}
		for (i=1; i<=n; i++) {
			DP[i].first = -1;
		}
		ans = dp(s);
		cout<<"Case "<<TC++<<": The longest path from "<<s<<" has length "<<ans.first<<", finishing at "<<ans.second<<"."<<endl<<endl;
	}
	
	return 0;
}
