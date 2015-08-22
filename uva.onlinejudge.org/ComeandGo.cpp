/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2938
        Name: Come and Go
        Date: 16/08/2015
*/
 
#include <bits/stdc++.h>
#define y1 		nd03dnqwuidg1odbnw9uddu0132d
#define clock 	asoudh219udhjdgausdhs9udy433
#define left	dfgag34gsfaf342rf23fgwrf42ff
#define middle	lk78k6ujkj76kjk88kkummnhh456
#define right	apidwcojbl213f80sjb3y8efjfas
#define EPS 1e-9
#define MP make_pair
#define DEB(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 4294967296ll
#define MAXN 1001
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

int n, m, u, v, t;
vi adj[2005];

int dfstime, dfsnum[2005], dfslow[2005], ncomp, comp[2005];
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

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j;
	
	while (cin>>n>>m, n || m) {
		for (i=0; i<n; i++) adj[i].clear();
		for (i=0; i<m; i++) {
			cin>>u>>v>>t; u--; v--;
			adj[u].push_back(v);
			if (t == 2) adj[v].push_back(u);
		}
		memset(comp, -1, sizeof comp);
		memset(dfsnum, -1, sizeof dfsnum);
		memset(dfslow, -1, sizeof dfslow);
		ncomp = dfstime = 0;
		for (i=0; i<n; i++) if (dfsnum[i] < 0) scc(i);
		bool ok = true;
		for (i=1; i<n; i++) if (comp[i] != comp[i-1]) ok = false;
		if (ok) cout<<"1\n";
		else cout<<"0\n";
	}
	
	return 0;
}
