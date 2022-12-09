/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=272
        Name: A Node Too Far
        Number: 336
        Date: 10/10/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 131071
//#define MAXN 10000010

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int nc, cant, graph[35][35], u, v, start, s, ttl, ans;
map<int, int> vertex;

void floyd_warshall () {
	for (int k=0; k<cant; k++) {
		for (int i=0; i<cant; i++) {
			for (int j=0; j<cant; j++) {
				if (graph[i][j] > graph[i][k] + graph[k][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC = 1, i, j;
	
	while (cin>>nc, nc) {
		
		for (i=0; i<35; i++) {
			for (j=0; j<35; j++) {
				graph[i][j] = INF;
			}
			graph[i][i] = 0;
		}
		cant = 0;
		vertex.clear();
		
		for (i=0; i<nc; i++) {
			cin>>u>>v;
			if (vertex.find(u) == vertex.end()) {
				vertex[u] = cant++;
			}
			if (vertex.find(v) == vertex.end()) {
				vertex[v] = cant++;
			}
			if (u != v) {
				graph[vertex[u]][vertex[v]] = graph[vertex[v]][vertex[u]] = 1;
			}
		}
		
		floyd_warshall();
		
		while (cin>>start>>ttl, start || ttl) {
			if (vertex.find(start) != vertex.end()) {
				ans = 0;
				s = vertex[start];
				for (i=0; i<cant; i++) {
					if (graph[s][i] > ttl) {
						ans++;
					}
				}
			} else ans = cant++;
			cout<<"Case "<<TC++<<": "<<ans<<" nodes not reachable from node "<<start<<" with TTL = "<<ttl<<"."<<endl;
		}
	}
	
	return 0;
}
