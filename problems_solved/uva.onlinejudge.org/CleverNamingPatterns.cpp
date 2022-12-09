/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=9
        Name: Clever Naming Patterns
        Date: 17/02/2015
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
#define find asjkldhakjsdbsakjdb
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, m, dist[100], match[100];
string s;
vector<int> adj[100];
vector<string> words[100];

bool bfs () {
	queue<int> q;
	int i, j, u, v;
	for (i=1; i<=n+n; i++)
		if (!match[i]) dist[i] = 0, q.push(i);
		else dist[i] = -1;
	dist[0] = -1;
	while (q.size()) {
		u = q.front(); q.pop();
		for (i=0; i<adj[u].size(); i++) {
			v = adj[u][i];
			if (dist[match[v]] == -1) {
				dist[match[v]] = dist[u] + 1;
				q.push(match[v]);
			}
		}
	}
	return dist[0] != -1;
}

bool dfs (int u) {
	if (u == 0) return true;
	int v, i;
	for (i=0; i<adj[u].size(); i++) {
		v = adj[u][i];
		if (dist[match[v]] == dist[u] + 1 && dfs(match[v])) {
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	dist[u] = -1;
	return false;
}

void max_matching () {
	memset(match, 0, sizeof match);
	while (bfs())
		for (int i=1; i<=n+n; i++)
			if (!match[i]) dfs(i);
} 

int main () {
    ios_base::sync_with_stdio(0);
    int TC, i, j, k;
    
    cin>>TC;
    for (int it=1; it<=TC; it++) {
		cin>>n;
		for (i=1; i<=n; i++) adj[i].clear();
		for (i=n+1; i<=n+n; i++) {
			adj[i].clear();
			words[i].clear();
			cin>>m;
			for (j=0; j<m; j++) {
				cin>>s;
				if (tolower(s[0])-'a'+1 <= n) {
					words[i].push_back(s);
					adj[tolower(s[0])-'a'+1].push_back(i);
					adj[i].push_back(tolower(s[0])-'a'+1);
				}
			}
		}
		max_matching();
		cout<<"Case #"<<it<<":"<<endl;
		for (i=1; i<=n; i++) {
			for (j=0; j<words[match[i]].size(); j++) {
				if (tolower(words[match[i]][j][0])-'a'+1 == i) {
					s = toupper(words[match[i]][j][0]);
					for (k=1; k<words[match[i]][j].length(); k++) s += tolower(words[match[i]][j][k]);
					break;
				}
			}
			cout<<s<<endl;
		}
	}
    
    return 0;
}
