/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2533
        Name: Connecting Cities
        Date: 17/10/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000007
//#define MAXN 3000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, m, c, x, y, pi, p[2005], rank[2005], number_ds, number_dsp, pt, pp;
vector<pair<int, ii> > edges;

int find_set (int i) {
	return (p[i] == i) ? i : (p[i] = find_set(p[i]));
}
void union_set (int i, int j, int pi) {
	int x = find_set(i);
	int y = find_set(j);
	if (x != y) {
		pt += pi;
		number_ds--;
		if (rank[x] > rank[y]) {
			p[y] = x;
		} else {
			p[x] = y;
			if (rank[x] == rank[y]) rank[y]++;
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		cin>>n>>m>>c;
		edges.clear();
		for (i=0; i<m; i++) {
			cin>>x>>y>>pi;
			edges.push_back(pair<int, ii>(pi, ii(x, y)));
		}
		sort(edges.begin(), edges.end());
		for (i=1; i<=n; i++) {
			p[i] = i;
			rank[i] = 0;
		}
		number_ds = n;
		pt = 0;
		for (i=0; (i<(int)edges.size()) && (number_ds != 1) && (edges[i].first <=c); i++) {
			union_set(edges[i].second.first, edges[i].second.second, edges[i].first);
		}
		pp = pt;
		number_dsp = number_ds;
		for (; (i<(int)edges.size()) && (number_ds != 1) && (edges[i].first <=(c*2)); i++) {
			union_set(edges[i].second.first, edges[i].second.second, edges[i].first);
		}
		cout<<((number_ds == 1) ? min(pt, (c * number_dsp + pp)) : (c * number_dsp + pp) )<<endl;
	}
	
	return 0;
}
