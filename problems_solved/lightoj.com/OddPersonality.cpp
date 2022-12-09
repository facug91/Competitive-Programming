/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1300
        Name: Odd Personality
        Date: 03/09/2015
*/
 
#include <bits/stdc++.h>
#define y1 		nd03dnqwuidg1odbnw9uddu0132d
#define clock 	asoudh219udhjdgausdhs9udy433
#define left	dfgag34gsfaf342rf23fgwrf42ff
#define middle	lk78k6ujkj76kjk88kkummnhh456
#define right	apidwcojbl213f80sjb3y8efjfas
#define move	df53y5fgsf43fdsfsdtg4j6hfdg4
#define count	nkwdfj111afbjdfsbj32r8yfwejb
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 4294967296ll
#define MAXN 10005
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, m, u, v, dfstime, dfsnum[MAXN], dfslow[MAXN], ncomp, comp[MAXN], father[MAXN], sizeComp[MAXN], color[MAXN];
bool isBipartite[MAXN], visComp[MAXN];
stack<int> stk;
vi adj[MAXN];

void scc (int u) {
  int i, v, w;
  dfsnum[u] = dfstime;
  dfslow[u] = dfstime++;
  stk.push(u);
  for (i = 0; i < adj[u].size(); i++) {
    v = adj[u][i];
    if (v == father[u]) continue;
    if (dfsnum[v] < 0) {
		father[v] = u;
		scc(v); 
		dfslow[u] = min(dfslow[u], dfslow[v]);
    } else if (comp[v] < 0) dfslow[u] = min(dfslow[u], dfsnum[v]);
  }
  if (dfsnum[u] == dfslow[u]) {
    do {
      v = stk.top(); stk.pop();
      comp[v] = ncomp;
      sizeComp[ncomp]++;
    } while (v != u);
    ncomp++;
  }
}

bool bicoloring (int u) {
	int i, j, v;
	for (i=0; i<adj[u].size(); i++) {
		v = adj[u][i];
		if (comp[u] != comp[v]) continue;
		if (color[v] != -1) {
			if (color[v] == color[u]) return false;
		} else {
			color[v] = (color[u]+1)%2;
			if (!bicoloring(v)) return false;
		}
	}
	return true;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>n>>m;
		for (i=0; i<MAXN; i++) adj[i].clear();
		while (m--) {
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		memset(comp, -1, sizeof comp);
		memset(dfsnum, -1, sizeof dfsnum);
		memset(dfslow, -1, sizeof dfslow);
		memset(sizeComp, 0, sizeof sizeComp);
		ncomp = dfstime = 0;
		for (int i = 0; i < n; i++) if (dfsnum[i] < 0) {
			father[i] = -1;
			scc(i);
		}
		memset(isBipartite, 0, sizeof isBipartite);
		memset(visComp, 0, sizeof visComp);
		memset(color, -1, sizeof color);
		for (i=0; i<n; i++) if (!visComp[comp[i]]) {
			color[i] = 0;
			visComp[comp[i]] = true;
			isBipartite[comp[i]] = bicoloring(i);
		}
		int ans = 0;
		for (i=0; i<ncomp; i++) if (sizeComp[i] > 2 && !isBipartite[i]) ans += sizeComp[i];
		cout<<"Case "<<it<<": "<<ans<<endl;
	}
	
	return 0;
}
