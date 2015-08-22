/*
        By: facug91
        From: https://acm.javeriana.edu.co/maratones/2015/07
        Name: Outing
        Date: 08/08/2015
*/

#include <bits/stdc++.h>
#define DB(x) cerr<<#x<<": " << x<<endl;

using namespace std;
#define prev d392rhbcdgausidhdsadasda
#define INF 1000000000

typedef long long ll;

int n, k, dep[1005], ans, depth[1005], cycle, p[1005], bottom[1005], top[1005];
bool vis[1005], vis2[1005][1005];
vector<int> comp;

int find_set (int i) {
	return (i == p[i]) ? i : (p[i] = find_set(p[i]));
}
void union_set (int i, int j) {
	int x = find_set(i);
	int y = find_set(j);
	if (x != y) {
		p[x] = y;
		bottom[y] = max(bottom[y], bottom[x]);
		top[y] = max(top[y], top[x]);
	}
}

void add_to (int i) {
	int x = find_set(i);
	top[x]++;
}

void ini (int i, int w) {
	bottom[i] = top[i] = w;
}

bool dfs (int u) {
	vis[u] = true;
	if (!vis[dep[u]]) {
		depth[dep[u]] = depth[u] + 1;
		if (dfs(dep[u])) {
			if (depth[cycle] <= depth[u]) {
				union_set(u, dep[u]);
			} else {
				union_set(u, dep[u]);
				add_to(u);
			}
			depth[dep[u]] = INF;
			return true;
		} else {
			union_set(u, dep[u]);
			add_to(u);
			depth[dep[u]] = INF;
			return false;
		}
	} else {
		if (depth[dep[u]] == INF) {
			union_set(u, dep[u]);
			add_to(u);
			return false;
		} else {
			cycle = dep[u];
			ini(u, depth[u]-depth[dep[u]]+1);
			return true;
		}
	}
}

void search (int idx, int sum) {
	if (sum > k) return;
	if (vis2[idx][sum]) return;
	ans = max(ans, sum);
	if (idx < comp.size()) {
		search(idx+1, sum);
		for (int i=bottom[find_set(comp[idx])]; i<=top[find_set(comp[idx])]; i++) search(idx+1, sum+i);
	}
	vis2[idx][sum] = true;
}

int main() {
	int i, j;
	
	cin>>n>>k;
	for (i=0; i<n; i++) {
		cin>>dep[i];
		dep[i]--;
	}
	memset(vis, 0, sizeof vis);
	memset(bottom, 0, sizeof bottom);
	memset(top, 0, sizeof top);
	for (i=0; i<n; i++) {
		p[i] = i;
		depth[i] = INF;
	}
	for (i=0; i<n; i++) if (!vis[i]) {
		depth[i] = 0;
		if (dfs(i)) comp.push_back(i);
		depth[i] = INF;
	}
	memset(vis2, 0, sizeof vis2);
	ans = 0;
	search(0, 0);
	cout<<ans<<endl;
	
}

