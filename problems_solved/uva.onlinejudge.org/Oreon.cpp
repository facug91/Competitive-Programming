/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3649
        Name: Oreon
        Date: 11/03/2015
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

int n, a, p[30];
vector<iii> edges, tunnel;

int find_set (int i) {return (i == p[i]) ? i : (p[i] = find_set(p[i]));}

void union_set (int i, int j, int w) {
	int x = find_set(i);
	int y = find_set(j);
	if (x != y) {
		if (i < j) tunnel.push_back(iii(w, ii(i, j)));
		else tunnel.push_back(iii(w, ii(j, i)));
		p[y] = x;
	}
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int TC, i, j, k;
	
	scanf("%d", &TC);
	for (int it=1; it<=TC; it++) {
		edges.clear();
		scanf("%d", &n);
		for (i=0; i<n; i++) {
			for (j=0; j<n; j++) {
				scanf("%d, ", &a);
				if (a != 0) edges.push_back(iii(a, ii(i, j)));
			}
		}
		sort(edges.begin(), edges.end());
		for (i=0; i<n; i++) p[i] = i;
		tunnel.clear();
		for (i=0; i<edges.size(); i++) union_set(edges[i].second.first, edges[i].second.second, edges[i].first);
		sort(tunnel.begin(), tunnel.end());
		cout<<"Case "<<it<<":\n";
		for (i=0; i<tunnel.size(); i++) cout<<(char)(tunnel[i].second.first+'A')<<"-"<<(char)(tunnel[i].second.second+'A')<<" "<<tunnel[i].first<<"\n";
	}
	
	return 0;
}
