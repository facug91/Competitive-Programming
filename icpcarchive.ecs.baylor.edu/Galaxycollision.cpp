/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4839
        Name: Galaxy collision
        Date: 17/12/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

struct point {
	int x, y;
	point () {x = y = 0;}
	point (int _x, int _y) {x = _x; y = _y;}
	bool operator== (point o) const {
		return (o.x==x && o.y==y);
	}
	bool operator!= (point o) const {
		return !(o == *this);
	}
};

struct cmp {
	bool operator() (const point &a, const point &b) {
		if (a.x == b.x) return a.y < b.y;
		return a.x < b.x;
	}
};

int n, x, y, ans, cont[3], vis[50005];
map<point, int, cmp> points;
vector<int> graph[50005];

double dist_point (point a, point b) {
	return hypot((double)b.x-a.x, (double)b.y-a.y);
}

void dfs (int idx, int v) {
	vis[idx] = v;
	cont[v]++;
	v = (v == 1) ? 2 : 1;
	for (int i=0; i<(int)graph[idx].size(); i++)
		if (!vis[graph[idx][i]])
			dfs(graph[idx][i], v);
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j, k;
	
	while (cin>>n) {
		ans = 0;
		points.clear();
		for (i=0; i<n; i++) {
			cin>>x>>y;
			points.insert(make_pair(point(x, y), i));
			graph[i].clear();
		}
		for (map<point, int>::iterator itr=points.begin(); itr!=points.end(); itr++) {
			for (x=(*itr).first.x-5; x<=(*itr).first.x+5; x++) {
				for (y=(*itr).first.y-5; y<=(*itr).first.y+5; y++) {
					point p = point(x, y);
					if (((*itr).first != p) && (dist_point((*itr).first, p) - 5.0 < EPS)) {
						map<point, int>::iterator ret = points.find(p);
						if ((ret != points.end()) && ((*ret).second > (*itr).second)) {
							graph[(*itr).second].push_back((*ret).second);
							graph[(*ret).second].push_back((*itr).second);
						}
					}
				}
			}
		}
		memset(vis, 0, sizeof vis);
		for (i=0; i<n; i++) {
			if (!vis[i]) {
				cont[1] = cont[2] = 0;
				dfs(i, 1);
				ans += min(cont[1], cont[2]);
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
