/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1140
        Name: Tourist Guide
        Date: 01/12/2015
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
#define F first
#define S second
#define DB(x) //cerr << " #" << (#x) << ": " << (x)
#define DBL(x) //cerr << " #" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10005
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<int, ii> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iii> viii; typedef vector<iiii> viiii;

int n, m, u, v, dfstime, dfsnum[105], dfslow[105];
vi adj[105];
unordered_map<string, int> to_idx;
bool art[105];
string name[105], s, t;
vector<string> art_city;

void dfs (int u, int f) {
  int i, v, w, cnt = 0;
  dfsnum[u] = dfstime;
  dfslow[u] = dfstime++;
  for (i = 0; i < adj[u].size(); i++) {
    v = adj[u][i];
    if (dfsnum[v] < 0) {
		dfs(v, u);
		if (dfslow[v] >= dfsnum[u] && f != -1) art[u] = true;
		dfslow[u] = min(dfslow[u], dfslow[v]);
		cnt++;
    } else if (v != f) dfslow[u] = min(dfslow[u], dfsnum[v]);
  }
  if (cnt > 1 && f == -1) art[u] = true;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j, k;
	
	while (cin>>n, n) {
		if (tc != 1) cout<<endl;
		to_idx.clear();
		for (i=0; i<n; i++) {
			adj[i].clear();
			cin>>name[i];
			to_idx[name[i]] = i;
		}
		cin>>m;
		while (m--) {
			cin>>s>>t;
			u = to_idx[s];
			v = to_idx[t];
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		memset(dfsnum, -1, sizeof dfsnum);
		memset(art, 0, sizeof art);
		dfstime = 0;
		for (i=0; i<n; i++) if (dfsnum[i] < 0) dfs(i, -1);
		art_city.clear();
		for (i=0; i<n; i++) if (art[i]) art_city.push_back(name[i]);
		sort(art_city.begin(), art_city.end());
		cout<<"City map #"<<tc++<<": "<<art_city.size()<<" camera(s) found"<<endl;
		for (string s : art_city) cout<<s<<endl;
	}
	
	return 0;
}
