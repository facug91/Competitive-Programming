/*
        By: facug91
        From: http://www.spoj.com/problems/BUGLIFE/
        Name: A Bug’s Life
        Date: 22/09/2015
*/
 
#include <bits/stdc++.h>
#define y1		nd03dnqwuidg1odbnw9uddu0132d
#define clock	asoudh219udhjdgausdhs9udy433
#define left	dfgag34gsfaf342rf23fgwrf42ff
#define middle	lk78k6ujkj76kjk88kkummnhh456
#define right	apidwcojbl213f80sjb3y8efjfas
#define move	df53y5fgsf43fdsfsdtg4j6hfdg4
#define count	nkwdfj111afbjdfsbj32r8yfwejb
#define prev	asdnklgbgbjfasdbhksdva4t9jds
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 4294967296ll
//#define MAXN 10005
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, m, u, v;
vi adj[4010];

void addOR (int u, int v) {
	adj[u^1].emplace_back(v);
	adj[v^1].emplace_back(u);
}

int dfstime, dfsnum[4010], dfslow[4010], ncomp, comp[4010];
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
	int i, j, tc;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>n>>m;
		for (i=0; i<n*2; i++) adj[i].clear();
		while (m--) {
			cin>>u>>v; u--; v--;
			addOR(u*2, v*2);
			addOR((u*2)^1, (v*2)^1);
		}
		memset(comp, -1, sizeof comp);
		memset(dfsnum, -1, sizeof dfsnum);
		memset(dfslow, -1, sizeof dfslow);
		ncomp = dfstime = 0;
		for (int i=0; i<n*2; i++) if (dfsnum[i] < 0) scc(i);
		bool ok = true;
		for (i=0; i<n*2; i+=2) if (comp[i] == comp[i^1]) ok = false;
		cout<<"Scenario #"<<it<<":"<<endl;
		if (ok) cout<<"No suspicious bugs found!"<<endl;
		else cout<<"Suspicious bugs found!"<<endl;
	}
	
	return 0;
}
