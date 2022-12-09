/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3615
        Name: IP-TV
        Date: 11/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, m, w, p[2005], ans;
string idx_name[2005], s1, s2;
map<string, int> name_idx;
vector<iii> edges;

int find_set (int i) {return (i == p[i]) ? i : (p[i] = find_set(p[i]));}

void union_set (int i, int j, int w) {
	int x = find_set(i);
	int y = find_set(j);
	if (x != y) {
		ans += w;
		p[y] = x;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int TC, i, j, k;
	
	cin>>TC;
	while (TC--) {
		cin>>n>>m;
		name_idx.clear();
		edges.clear();
		k = 0;
		for (i=0; i<m; i++) {
			cin>>s1>>s2>>w;
			if (name_idx.find(s1) == name_idx.end()) {
				name_idx[s1] = k;
				idx_name[k++] = s1;
			}
			if (name_idx.find(s2) == name_idx.end()) {
				name_idx[s2] = k;
				idx_name[k++] = s2;
			}
			edges.push_back(iii(w, ii(name_idx[s1], name_idx[s2])));
		}
		sort(edges.begin(), edges.end());
		for (i=0; i<n; i++) p[i] = i;
		ans = 0;
		for (i=0; i<edges.size(); i++) union_set(edges[i].second.first, edges[i].second.second, edges[i].first);
		cout<<ans<<"\n";
		if (TC) cout<<"\n";
	}
	
	return 0;
}
