/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3676
        Name: Anti Brute Force Lock
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

int n, ans, p[505];
string keys[505];
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
		cin>>n;
		for (i=0; i<n; i++) cin>>keys[i];
		edges.clear();
		int aux;
		for (i=0; i<n; i++) for (j=i+1; j<n; j++) {
			aux = 0;
			for (k=0; k<4; k++) aux += min(abs(keys[i][k]-keys[j][k]), 10-abs(keys[i][k]-keys[j][k]));
			edges.push_back(iii(aux, ii(i, j)));
		}
		sort(edges.begin(), edges.end());
		for (i=0; i<n; i++) p[i] = i;
		ans = 0;
		for (i=0; i<edges.size(); i++) union_set(edges[i].second.first, edges[i].second.second, edges[i].first);
		int mn = INT_MAX;
		for (i=0; i<n; i++) {
			aux = 0;
			for (k=0; k<4; k++) aux += min(keys[i][k]-'0', 10-(keys[i][k]-'0'));
			if (aux < mn) mn = aux;
		}
		ans += mn;
		cout<<ans<<"\n";
	}
	
	return 0;
}
