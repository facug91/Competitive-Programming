/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=1690
        Name: Bad Cowtractors
        Date: 20/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
#define MP make_pair
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, m, a, b, c, p[1005], number_sets, ans;
vector<iii> edges;

int find_set (int i) {return (i == p[i]) ? i : (p[i] = find_set(p[i]));}

void union_set (int i, int j, int w) {
	int x = find_set(i);
	int y = find_set(j);
	if (x != y) {
		ans += w;
		p[y] = x;
		number_sets--;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int i, j;
	
	cin>>n>>m;
	for (i=0; i<m; i++) {
		cin>>a>>b>>c;
		edges.push_back(MP(c, MP(a, b)));
	}
	sort(edges.begin(), edges.end(), greater<iii>());
	for (i=1; i<=n; i++) p[i] = i;
	number_sets = n; ans = 0;
	for (i=0; i<edges.size(); i++) union_set(edges[i].second.first, edges[i].second.second, edges[i].first);
	if (number_sets == 1) cout<<ans<<"\n";
	else cout<<"-1\n";
	
	return 0;
}
