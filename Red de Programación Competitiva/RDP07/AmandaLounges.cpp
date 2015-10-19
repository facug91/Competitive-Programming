/*
        By: facug91
        From: https://acm.javeriana.edu.co/maratones/2015/07
        Name: Amanda Lounges
        Date: 08/08/2015
*/

#include <bits/stdc++.h>
#define DB(x) cerr<<#x<<": " << x<<endl;

using namespace std;
#define prev d392rhbcdgausidhdsadasda

typedef long long ll;

int n, m, u, v, t, colour[200005], ans;
vector<int> adj[200005];
bool ok, vis[200005], vis2[200005];

bool colouring (int u) {
	vis[u] = true;
	for (int i=0; i<adj[u].size(); i++) {
		int v = adj[u][i];
		if (colour[v] == -1) {
			colour[v] = (colour[u]+1)%2;
			if (!colouring(v)) return false;
		} else if (colour[v] == colour[u]) {
			return false;
		} else if (!vis[v]) {
			if (!colouring(v)) return false;
		}
	}
	return true;
}

int sum (int u) {
	vis2[u] = true;
	int ans = colour[u];
	for (int i=0; i<adj[u].size(); i++) {
		int v = adj[u][i];
		if (!vis2[v]) ans += sum(v);
	}
	return ans;
}

pair<int, int> bicolouring (int u) {
	vis2[u] = true;
	pair<int, int> ans = make_pair(colour[u]==0, colour[u]==1), aux;
	for (int i=0; i<adj[u].size(); i++) {
		int v = adj[u][i];
		if (colour[v] == -1) {
			colour[v] = (colour[u]+1)%2;
			aux = bicolouring(v);
			if (!ok) return ans;
			ans.first += aux.first;
			ans.second += aux.second;
		} else if (colour[v] == colour[u]) {
			ok = false;
			return ans;
		}
	}
	return ans;
}

int main() {
	int i, j;
	
	memset(colour, -1, sizeof colour);
	cin>>n>>m;
	ok = true;
	for (i=0; i<m; i++) {
		cin>>u>>v>>t; u--; v--;
		if (t == 0) {
			if (colour[u] == 1 || colour[v] == 1) ok = false;
			else colour[u] = colour[v] = 0;
		} else if (t == 2) {
			if (colour[u] == 0 || colour[v] == 0) ok = false;
			else colour[u] = colour[v] = 1;
		} else {
			if (colour[u] != -1 && colour[v] != -1) {
				continue;
			} else if (colour[u] != -1) {
				colour[v] = (colour[u]+1) % 2;
				if (colour[v]) ans++;
			} else if (colour[v] != -1) {
				colour[u] = (colour[v]+1) % 2;
				if (colour[u]) ans++;
			} else {
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
		}
	}
	if (!ok) cout<<"impossible\n";
	else {
		memset(vis, 0, sizeof vis);
		for (i=0; i<n; i++) if (colour[i] != -1) if (!vis[i] && colour[i] != -1) if(!colouring(i)) ok = false;
		if (!ok) cout<<"impossible\n";
		else {
			ans = 0;
			memset(vis2, 0, sizeof vis2);
			for (i=0; i<n; i++) {
				if (vis[i]) {
					if (!vis2[i]) {
						ans += sum(i);
					}
				} else {
					if (!vis2[i]) {
						colour[i] = 0;
						pair<int, int> aux = bicolouring(i);
						ans += min(aux.first, aux.second);
					}
				}
			}
			if (!ok) cout<<"impossible\n";
			else cout<<ans<<"\n";
		}
	}
	
}

