/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=849
        Name: Re-connecting Computer Sites
        Date: 10/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, m, k, a, b, p[MAXN], rank[MAXN];
ll c, ori, ans;
vector<pair<ll, ii> > edges;

int find_set (int i) {return (i == p[i]) ? i : (p[i] = find_set(p[i]));}

void union_set (int i, int j, ll w) {
	int x = find_set(i);
	int y = find_set(j);
	if (y != x) {
		ans += w;
		if (rank[y] > rank[x]) p[x] = y;
		else {
			p[y] = x;
			if (rank[x] == rank[y]) rank[x]++;
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int i, j; bool first = true;
	
	while (cin>>n) {
		if (first) first = false;
		else cout<<"\n";
		edges.clear();
		ori = 0;
		for (i=0; i<n-1; i++) {
			cin>>a>>b>>c;
			ori += c;
		}
		cin>>k;
		for (i=0; i<k; i++) {
			cin>>a>>b>>c; a--; b--;
			edges.push_back(pair<ll, ii>(c, ii(a, b)));
		}
		cin>>m;
		for (i=0; i<m; i++) {
			cin>>a>>b>>c; a--; b--;
			edges.push_back(pair<ll, ii>(c, ii(a, b)));
		}
		sort(edges.begin(), edges.end());
		for (i=0; i<n; i++) p[i] = i, rank[i] = 0;
		ans = 0;
		for (i=0; i<edges.size(); i++) union_set(edges[i].second.first, edges[i].second.second, edges[i].first);
		cout<<ori<<"\n"<<ans<<"\n";
	}
	
	return 0;
}
