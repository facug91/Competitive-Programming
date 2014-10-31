/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2299
        Name: Elevator Trouble
        Date: 21/10/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007
//#define MAXN 3000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int f, s, g, u, d;
int graph[1000005];
queue<int> q;

bool check_pos (int idx) {
	return (idx >= 1) && (idx <= f);
}

void bfs () {
	memset(graph, -1, sizeof graph);
	q.push(s);
	graph[s] = 0;
	int act;
	while (!q.empty()) {
		act = q.front();
		q.pop();
		if (check_pos(act-d) && graph[act-d] == -1) {
			graph[act-d] = graph[act] + 1;
			q.push(act-d);
		}
		if (check_pos(act+u) && graph[act+u] == -1) {
			graph[act+u] = graph[act] + 1;
			q.push(act+u);
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>f>>s>>g>>u>>d;
	bfs();
	if (graph[g] == -1) cout<<"use the stairs"<<endl;
	else cout<<graph[g]<<endl;
	
	return 0;
}
