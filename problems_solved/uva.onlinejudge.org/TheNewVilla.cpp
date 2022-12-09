/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=257
        Name: The New Villa
        Date: 25/04/2015
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

int r, d, s, u, v, dis[10][1<<10], room[1<<10];
bool adj[10][10], vis[10][1<<10], turn[10][10];
ii father[10][1<<10];

void bfs () {
	int i, j;
	memset(vis, 0, sizeof vis);
	memset(dis, -1, sizeof dis);
	vis[0][1] = true;
	dis[0][1] = 0;
	father[0][1] = ii(-1, -1);
	queue<ii> q; q.push(ii(0, 1));
	ii act;
	while (q.size()) {
		act = q.front(); q.pop();
		for (i=0; i<r; i++) if (act.first != i && turn[act.first][i] && !vis[act.first][act.second^(1<<i)]) {
			vis[act.first][act.second^(1<<i)] = true;
			dis[act.first][act.second^(1<<i)] = dis[act.first][act.second] + 1;
			father[act.first][act.second^(1<<i)] = act;
			q.push(ii(act.first, act.second^(1<<i)));
		}
		for (i=0; i<r; i++) if (adj[act.first][i] && ((act.second & (1<<i)) != 0) && !vis[i][act.second]) {
			vis[i][act.second] = true;
			dis[i][act.second] = dis[act.first][act.second] + 1;
			father[i][act.second] = act;
			q.push(ii(i, act.second));
		}
	}
}

void print (int u, int bm) {
	if (father[u][bm].first != -1) {
		print(father[u][bm].first, father[u][bm].second);
		if (u == father[u][bm].first) {
			if (bm > father[u][bm].second) cout<<"- Switch on light in room "<<room[bm^father[u][bm].second]+1<<".\n";
			else cout<<"- Switch off light in room "<<room[bm^father[u][bm].second]+1<<".\n";
		} else cout<<"- Move to room "<<u+1<<".\n";
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(4); cerr<<fixed<<setprecision(10); //cout.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j;
	
	for (i=0; i<10; i++) room[1<<i] = i;
	while (cin>>r>>d>>s, r || d || s) {
		memset(adj, 0, sizeof adj);
		for (i=0; i<d; i++) {
			cin>>u>>v; u--; v--;
			adj[u][v] = adj[v][u] = true;
		}
		memset(turn, 0, sizeof turn);
		for (i=0; i<s; i++) {
			cin>>u>>v; u--; v--;
			turn[u][v] = true;
		}
		bfs();
		cout<<"Villa #"<<tc++<<"\n";
		if (!vis[r-1][(1<<(r-1))]) cout<<"The problem cannot be solved.\n";
		else {
			cout<<"The problem can be solved in "<<dis[r-1][(1<<(r-1))]<<" steps:\n";
			print(r-1, 1<<(r-1));
		}
		cout<<"\n";
	}
	
	return 0;
}
