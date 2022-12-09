/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4794
        Name: Triangles
        Date: 08/01/2015
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, l[3], DP[3005], ans, act[3005];
double v, values[3005];
ii brother[3005];
vector<int> graph[3005];
vector<pair<double, int> > nodes[1000005];

int dp (int idx) {
	if (DP[idx] != -1) return DP[idx];
	int ans = 0, aux;
	for (int i=0; i<graph[idx].size(); i++) {
		aux = max(dp(brother[graph[idx][i]].first), dp(brother[graph[idx][i]].second));
		if (aux+1 > ans)
			ans = aux+1;
	}
	return DP[idx] = ans;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j, k;
	
	while (cin>>n) {
		
		for (i=0; i<1000005; i++)
			nodes[i].clear();
		for (i=0; i<n*3; i++)
			graph[i].clear();
		
		for (i=0; i<n; i++) {
			cin>>l[0]>>l[1]>>l[2]>>v;
			for (j=0; j<3; j++) {
				act[i*3+j] = l[j];
				brother[i*3+j].first = i*3+((j+1)%3);
				brother[i*3+j].second = i*3+((j+2)%3);
				values[i*3+j] = v;
				nodes[l[j]].push_back(make_pair(v, i*3+j));
			}
		}
		
		for (i=0; i<n*3; i++)
			for (j=0; j<nodes[act[i]].size(); j++)
				if (nodes[act[i]][j].first > values[i])
					graph[i].push_back(nodes[act[i]][j].second);
		
		memset(DP, -1, sizeof DP);
		ans = -1;
		for (i=0; i<n*3; i++) {
			if (dp(i) > ans) {
				ans = dp(i);
			}
		}
		printf("%d\n", ans+1);
	}
	
	return 0;
}
