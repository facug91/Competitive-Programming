/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2108
        Name: Monkeys in the Emei Mountain
        Date: 04/05/2015
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

int n, m, a, b, s, t, res[505][505], level[505], total, mf;
vi adj[505], start;
bool mark[50005];
iii monkey[105];
vii interval, ans, aux;

bool bfs () {
	queue<int> q; q.push(s);
	memset(level, -1, sizeof level);
	level[s] = 0;
	int u, v;
	while (q.size()) {
		u = q.front(); q.pop();
		for (int i=0; i<adj[u].size(); i++) {
			v = adj[u][i];
			if (level[v] == -1 && res[u][v] > 0) {
				level[v] = level[u] + 1;
				q.push(v);
				if (v == t) return true;
			}
		}
	}
	return false;
}

int dfs (int u, int min_edge) {
	if (u == t) return min_edge;
	int v, faux, fsum = 0;
	for (int i=0; i<adj[u].size(); i++) {
		v = adj[u][i];
		if (level[v] == level[u] + 1 && res[u][v] > 0) {
			faux = dfs(v, min(min_edge, res[u][v]));
			if (faux) {
				fsum += faux;
				res[u][v] -= faux;
				res[v][u] += faux;
				min_edge -= faux;
				if (min_edge == 0) break;
			}
		}
	}
	return fsum;
}

int max_flow () {
	int mf = 0;
	while (bfs()) mf += dfs(s, INT_MAX);
	return mf;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(4); cerr<<fixed<<setprecision(10); //cout.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j;
	
	while (cin>>n, n) {
		cin>>m;
		memset(mark, 0, sizeof mark);
		memset(res, 0, sizeof res);
		s = 0; t = 500;
		total = 0;
		for (i=s; i<=t; i++) adj[i].clear();
		for (i=1; i<=n; i++) {
			cin>>monkey[i].first>>monkey[i].second.first>>monkey[i].second.second;
			adj[s].push_back(i);
			adj[i].push_back(s);
			res[s][i] = monkey[i].first;
			total += monkey[i].first;
			mark[monkey[i].second.first] = mark[monkey[i].second.second] = true;
		}
		int prev = 0; interval.clear(); start.clear();
		for (i=1; i<50005; i++) {
			if (mark[i]) {
				interval.push_back(ii(prev, i));
				start.push_back(prev);
				adj[interval.size()+n].push_back(t);
				adj[t].push_back(interval.size()+n);
				res[interval.size()+n][t] = (interval.back().second-interval.back().first)*m;
				prev = i;
			}
		}
		for (i=0; i<interval.size(); i++) {
			for (j=1; j<=n; j++) {
				if (interval[i].first >= monkey[j].second.first && interval[i].second <= monkey[j].second.second) {
					adj[j].push_back(i+n+1);
					adj[i+n+1].push_back(j);
					res[j][i+n+1] = interval[i].second-interval[i].first;
				}
			}
		}
		mf = max_flow();
		if (mf != total) cout<<"Case "<<tc++<<": No\n";
		else {
			cout<<"Case "<<tc++<<": Yes\n";
			for (i=1; i<=n; i++) {
				aux.clear();
				for (j=n+1; j<t; j++) {
					if (res[j][i] > 0) {
						aux.push_back(ii(start[j-n-1], min(interval[j-n-1].second, start[j-n-1]+res[j][i])));
						if (start[j-n-1]+res[j][i] == interval[j-n-1].second) {
							start[j-n-1] = interval[j-n-1].first;
						} else if (start[j-n-1]+res[j][i] > interval[j-n-1].second) {
							start[j-n-1] = interval[j-n-1].first+(start[j-n-1]+res[j][i] - interval[j-n-1].second);
							aux.push_back(ii(interval[j-n-1].first, start[j-n-1]));
						} else {
							start[j-n-1] = start[j-n-1]+res[j][i];
						}
					}
				}
				sort(aux.begin(), aux.end());
				ans.clear();
				prev = aux[0].first;
				for (j=1; j<aux.size(); j++) {
					if (aux[j].first != aux[j-1].second) {
						ans.push_back(ii(prev, aux[j-1].second));
						prev = aux[j].first;
					}
				}
				ans.push_back(ii(prev, aux.back().second));
				cout<<ans.size();
				for (j=0; j<ans.size(); j++) cout<<" ("<<ans[j].first<<","<<ans[j].second<<")";
				cout<<"\n";
			}
		}
	}
	
	return 0;
}
