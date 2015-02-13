/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=658&page=show_problem&problem=4842
        Name: Journey through the kingdom
        Date: 26/12/2014
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

int r, c, n, dis[505][505];
ii provinces[10];
pair<int, ii> kingdom[505][505];

ii obj;
struct cmp {
	bool operator() (const pair<int, ii> &a, const pair<int, ii> &b) {
		return a.first > b.first;
	}
};

int dijkstra (int from, int to) {
	if (provinces[from].first == provinces[to].first && provinces[from].second == provinces[to].second)
		return 0;
	for (int i=0; i<r; i++)
		for (int j=0; j<c; j++)
			dis[i][j] = INF;
	obj = provinces[to];
	priority_queue<pair<int, ii>, vector<pair<int, ii> >, cmp> q;
	q.push(make_pair(0, ii(provinces[from].first, provinces[from].second)));
	dis[provinces[from].first][provinces[from].second] = 0;
	pair<int, ii> act;
	while (!q.empty()) {
		if (q.top().first == dis[provinces[to].first][provinces[to].second]) return dis[provinces[to].first][provinces[to].second];
		act = q.top();
		q.pop();
		int d = act.first;
		int x = act.second.first;
		int y = act.second.second;
		int rfrom = max(0, x - kingdom[x][y].second.first);
		int rto = min(r-1, x + kingdom[x][y].second.first);
		int cfrom = max(0, y - kingdom[x][y].second.second);
		int cto = min(c-1, y + kingdom[x][y].second.second);
		
		for (int w=rfrom; w<=rto; w++) {
			for (int z=cfrom; z<=cto; z++) {
				if (dis[w][z] > d + kingdom[x][y].first) {
					dis[w][z] = d + kingdom[x][y].first;
					q.push(make_pair(dis[w][z], ii(w, z)));
				}
			}
		}
	}
	
	return -1;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j, f;
	
	while (cin>>r>>c>>n) {
		
		for (i=0; i<r; i++)
			for (j=0; j<c; j++)
				cin>>kingdom[i][j].first;
		
		for (i=0; i<r; i++)
			for (j=0; j<c; j++)
				cin>>kingdom[i][j].second.first;
		
		for (i=0; i<r; i++)
			for (j=0; j<c; j++)
				cin>>kingdom[i][j].second.second;
		
		for (i=0; i<n; i++) {
			cin>>provinces[i].first>>provinces[i].second;
			provinces[i].first--; provinces[i].second--;
		}
		
		for (i=0; i<n-2; i++)
			cout<<dijkstra(i, i+1)<<" ";
		cout<<dijkstra(i, i+1)<<endl;
		
	}
	
	return 0;
}
