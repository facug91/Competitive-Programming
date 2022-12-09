/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2678
        Name: Dark roads
        Date: 10/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, m, a, b, c, p[200005], rank[200005], total, used;
vector<iii> edges;

int find_set (int i) {return (i == p[i]) ? i : (p[i] = find_set(p[i]));}

void union_set (int i, int j, int w) {
	int x = find_set(i);
	int y = find_set(j);
	if (x != y) {
		used += w;
		if (rank[y] > rank[x]) p[x] = y;
		else {
			p[y] = x;
			if (rank[y] == rank[x]) rank[x]++;
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int TC, i, j;
	
	while (cin>>n>>m, n || m) {
		edges.clear();
		total = 0;
		for (i=0; i<m; i++) {
			cin>>a>>b>>c;
			edges.push_back(iii(c, ii(a, b)));
			total += c;
		}
		sort(edges.begin(), edges.end());
		for (i=0; i<n; i++) p[i] = i, rank[i] = 0;
		used = 0;
		for (i=0; i<m; i++) union_set(edges[i].second.first, edges[i].second.second, edges[i].first);
		cout<<(total-used)<<"\n";
	}
	
	return 0;
}
