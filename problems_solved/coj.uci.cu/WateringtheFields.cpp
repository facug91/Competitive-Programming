/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2759
        Name: Watering the Fields
        Date: 27/12/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, c, x, y, p[2005], ans, number_sets;
vector<ii> points;
vector<pair<int, ii> > edges;

int dist_point (ii a, ii b) {
	return (a.first-b.first) * (a.first-b.first) + (a.second-b.second) * (a.second-b.second);
}

int find_set (int i) {
	return (p[i] == i) ? i : (p[i] = find_set(p[i]));
}

void union_set (int i, int j, int w) {
	int x = find_set(i);
	int y = find_set(j);
	if (y != x) {
		number_sets--;
		ans += w;
		p[y] = x;
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>n>>c;
	for (i=0; i<n; i++) {
		cin>>x>>y;
		points.push_back(ii(x, y));
	}
	
	for (i=0; i<(int)points.size()-1; i++) {
		for (j=i+1; j<(int)points.size(); j++) {
			int d = dist_point(points[i], points[j]);
			if (d >= c)	edges.push_back(make_pair(d, ii(i, j)));
		}
	}
	
	sort(edges.begin(), edges.end());
	
	for (i=0; i<n; i++)
		p[i] = i;
	ans = 0;
	number_sets = n;
	for (i=0; i<(int)edges.size(); i++)
		union_set(edges[i].second.first, edges[i].second.second, edges[i].first);
	
	if (number_sets == 1) {
		cout<<ans<<endl;
	} else {
		cout<<"-1"<<endl;
	}
	
	return 0;
}
