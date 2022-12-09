/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1248
        Name: Killing Aliens in Borg Maze
        Date: 01/03/2016
*/

#include <bits/stdc++.h>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
#define MOD 1000000007ll
#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int r, c, n, to_idx[55][55], dis[105][105], dis2[55][55], dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}, p[105], ans;
ii point[105];
string mat[55];
queue<ii> q;
bool vis[55][55];
vector<pair<int, pair<int, int> > > edge;

void bfs (int idx) {
	memset(vis, 0, sizeof vis);
	vis[point[idx].F][point[idx].S] = true;
	dis2[point[idx].F][point[idx].S] = 0;
	dis[idx][idx] = 0;
	q.push(point[idx]);
	ii u, v;
	while (q.size()) {
		u = q.front(); q.pop();
		for (int di=0; di<4; di++) {
			int x = u.F + dx[di];
			int y = u.S + dy[di];
			if (mat[x][y] != '#' && !vis[x][y]) {
				vis[x][y] = true;
				dis2[x][y] = dis2[u.F][u.S] + 1;
				q.push(ii(x, y));
				if (to_idx[x][y] != -1) {
					dis[idx][to_idx[x][y]] = dis2[x][y];
				}
			}
		}
	}
}

int find_set (int i) {
	return (i == p[i]) ? i : (p[i] = find_set(p[i]));
}

void union_set (int i, int j, int w) {
	int x = find_set(i);
	int y = find_set(j);
	if (x != y) {
		ans += w;
		p[x] = y;
	}
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>c>>r;
		getline(cin, mat[0]);
		for (i=0; i<r; i++) getline(cin, mat[i]);
		n = 0;
		memset(to_idx, -1, sizeof to_idx);
		for (i=0; i<r; i++) for (j=0; j<c; j++) {
			if (mat[i][j] == 'A' || mat[i][j] == 'S') {
				point[n] = ii(i, j);
				to_idx[i][j] = n++;
			}
		}
		for (i=0; i<n; i++) bfs(i);
		for (i=0; i<n; i++) p[i] = i;
		edge.clear();
		for (i=0; i<n; i++) for (j=i+1; j<n; j++) edge.push_back(MP(dis[i][j], MP(i, j)));
		sort(edge.begin(), edge.end());
		ans = 0;
		for (i=0; i<edge.size(); i++) union_set(edge[i].S.F, edge[i].S.S, edge[i].F);
		cout<<ans<<endl;
	}
	
	return 0;
}
