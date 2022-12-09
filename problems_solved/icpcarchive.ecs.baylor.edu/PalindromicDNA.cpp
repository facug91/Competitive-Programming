/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2959
        Name: Palindromic DNA
        Date: 23/09/2015
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

int n, t, l, m, subset[10005];
char s[10005];
vi adj[40040];
unordered_map<char, int> alphabet;

void force (int i, int val) {
	int u = i * 2 + val;
	adj[u^1].emplace_back(u);
	//cerr<<"u "<<u<<" val "<<val<<endl;
}

void addOR (int i, int v1, int j, int v2) {
	int u = i * 2 + v1, v = j * 2 + v2;
	//cerr<<"u "<<u<<" val "<<v1<<endl;
	adj[u^1].emplace_back(v);
	//cerr<<"v "<<v<<" val "<<v2<<endl;
	adj[v^1].emplace_back(u);
}

void addEqual (int i, int j) {
	addOR(i, 1, j, 0);
	addOR(i, 0, j, 1);
}

void addDistinct (int i, int j) {
	addOR(i, 0, j, 0);
	addOR(i, 1, j, 1);
}

int dfstime, dfsnum[40040], dfslow[40040], ncomp, comp[40040];
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
	
	alphabet['A'] = 0;
	alphabet['G'] = 1;
	alphabet['T'] = 2;
	alphabet['C'] = 3;
	
	while (scanf("%d %d", &n, &t), n || t) {
		scanf("%s", s);
		for (i=0; i<n*4; i++) adj[i].clear();
		for (i=1; i<n; i++) addOR(i, 0, i-1, 0);
		while (t--) {
			scanf("%d:", &l);
			for (i=0; i<l; i++) scanf("%d", &subset[i]);
			i = 0; j = l - 1;
			while (i < j) {
				int idxi = subset[i], idxj = subset[j];
				assert(idxi >= 0 && idxi < n && idxj >= 0 && idxj < n);
				int dif = abs(alphabet[s[idxi]]-alphabet[s[idxj]]);
				int dis = min(dif, 4-dif);
				assert(dis >= 0 && dis < 4);
				if (dis == 0) {
					addEqual(idxi, idxj);
					addEqual(idxi+n, idxj+n);
				} else if (dis == 1) {
					addDistinct(idxi, idxj);
					if (alphabet[s[idxi]]+1 == alphabet[s[idxj]] || (alphabet[s[idxi]] == 3 && alphabet[s[idxj]] == 0)) {
						addOR(idxi, 1, idxj+n, 0);
						addOR(idxj, 1, idxi+n, 1);
					} else {
						addOR(idxi, 1, idxj+n, 1);
						addOR(idxj, 1, idxi+n, 0);
					}
				} else if (dis == 2) {
					force(idxi, 1); force(idxj, 1);
					addDistinct(idxi+n, idxj+n);
				}
				i++; j--;
			}
		}
		memset(comp, -1, sizeof comp);
		memset(dfsnum, -1, sizeof dfsnum);
		ncomp = dfstime = 0;
		for (i=0; i<n*4; i++) if (dfsnum[i] < 0) scc(i);
		bool ok = true;
		for (i=0; i<n*4; i+=2) if (comp[i] == comp[i+1]) ok = false;
		if (ok) printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
}
