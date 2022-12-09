/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1003
        Name: Drunk
        Date: 12/05/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, m, in[20020];
vi adj[20020];
map<string, int> to_idx;
string a, b;

bool topological_sort () {
	int i, j, u, v, size = n;
	queue<int> q;
	for (i=0; i<n; i++) if (in[i] == 0) q.push(i);
	while (q.size()) {
		u = q.front(); q.pop();
		size--;
		for (i=0; i<adj[u].size(); i++) {
			v = adj[u][i];
			in[v]--;
			if (in[v] == 0) q.push(v);
		}
	}
	return (size == 0);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(4); cerr<<fixed<<setprecision(10); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>m; n = 0;
		to_idx.clear();
		for (i=0; i<20020; i++) {
			adj[i].clear();
			in[i] = 0;
		}
		for (i=0; i<m; i++) {
			cin>>a>>b;
			if (to_idx.find(a) == to_idx.end()) to_idx[a] = n++;
			if (to_idx.find(b) == to_idx.end()) to_idx[b] = n++;
			adj[to_idx[a]].push_back(to_idx[b]);
			in[to_idx[b]]++;
		}
		if (topological_sort()) cout<<"Case "<<it<<": Yes\n";
		else cout<<"Case "<<it<<": No\n";
	}
	
	return 0;
}
