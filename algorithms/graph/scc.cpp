dfstime, dfsnum[MAXN], dfslow[MAXN], ncomp, comp[MAXN];
bool vis[MAXN];
vi adj[MAXN], dag[MAXN];
stack<int> stk;

void scc (int u) {
	int i, v, w;
	dfsnum[u] = dfstime;
	dfslow[u] = dfstime++;
	stk.push(u);
	for (i = 0; i < adj[u].size(); i++) {
		v = adj[u][i];
		if (dfsnum[v] < 0) {
			scc(v); 
			dfslow[u] = min(dfslow[u], dfslow[v]);
		} else if (comp[v] < 0) dfslow[u] = min(dfslow[u], dfsnum[v]);
	}
	if (dfsnum[u] == dfslow[u]) {
		do {
			v = stk.top(); stk.pop();
			comp[v] = ncomp;
		} while (v != u);
		ncomp++;
	}
}

void make_scc_dag (int u) {
	vis[u] = true;
	for (int v : adj[u]) {
		if (comp[u] != comp[v]) dag[comp[u]].push_back(comp[v]);
		if (!vis[v]) make_scc_dag(v);
	}
}

memset(comp, -1, sizeof comp);
memset(dfsnum, -1, sizeof dfsnum);
ncomp = dfstime = 0;
for (i=0; i<n; i++) if (dfsnum[i] < 0) scc(i);

memset(vis, 0, sizeof vis);
for (i=0; i<ncomp; i++) dag[i].clear();
for (i=0; i<n; i++) if (!vis[i]) make_scc_dag(i);
for (i=0; i<ncomp; i++) {
	auto it = unique(dag[i].begin(), dag[i].end());
	dag[i].resize(distance(dag[i].begin(), it));
}
