/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4802
        Name: Chaos Management
        Date: 14/01/2015
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 205

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, m, h1, h2, m1, m2, dist[405], match[405];
vector<int> ady[405];
vector<ii> employee_time, job_time;

bool is_inside (const ii &e, const ii &j) {
	return e.first <= j.first && j.second <= e.second;
}

bool bfs () {
	int u, v, i;
	queue<int> q;
	for (i=1; i<=n; i++)
		if (!match[i]) dist[i] = 0, q.push(i);
		else dist[i] = -1;
	dist[0] = -1;
	while (!q.empty()) {
		u = q.front(); q.pop();
		if (u != 0) {
			for (i=0; i<(int)ady[u].size(); i++) {
				v = ady[u][i];
				if (dist[match[v]] == -1) {
					dist[match[v]] = dist[u] + 1;
					q.push(match[v]);
				}
			}
		}
	}
	return dist[0] != -1;
}

bool dfs (int u) {
	if (u == 0) return true;
	int v, i;
	for (i=0; i<(int)ady[u].size(); i++) {
		v = ady[u][i];
		if (dist[match[v]] == dist[u] + 1 && dfs(match[v])) {
			match[u] = v;
			match[v] = u;
			return true;
		}
	}
	dist[u] = -1;
	return false;
}

int max_matching () {
	memset(match, 0, sizeof match);
	int mm = 0;
	while (bfs())
		for (int i=1; i<=n; i++)
			if (!match[i] && dfs(i))
				mm++;
	return mm;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d %d", &n, &m);
		for (i=0; i<n+m+1; i++)
			ady[i].clear();
		employee_time.clear();
		for (i=0; i<n; i++) {
			scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
			employee_time.push_back(ii(h1*60+m1, h2*60+m2));
		}
		job_time.clear();
		for (j=0; j<m; j++) {
			scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
			job_time.push_back(ii(h1*60+m1, h2*60+m2));
		}
		for (i=0; i<n; i++)
			for (j=0; j<m; j++)
				if (is_inside(employee_time[i], job_time[j]))
					ady[i+1].push_back(j+1+n);
		cout<<max_matching()<<endl;
	}
	
	return 0;
}
