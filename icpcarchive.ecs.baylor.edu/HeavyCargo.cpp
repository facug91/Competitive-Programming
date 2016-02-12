/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=485
        Name: Heavy Cargo
        Date: 17/10/2015
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
//#define MOD 1000000007ll
//#define MAXN 1100000000000000ll
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, r, u, v, s, t, w, adj[205][205], nidx;
map<string, int> to_idx;
string su, sv;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j, k;
	
	while (cin>>n>>r, n || r) {
		nidx = 0;
		memset(adj, -1, sizeof adj);
		while (r--) {
			cin>>su>>sv>>w;
			if (to_idx.find(su) == to_idx.end()) to_idx[su] = nidx++;
			if (to_idx.find(sv) == to_idx.end()) to_idx[sv] = nidx++;
			u = to_idx[su]; v = to_idx[sv];
			if (adj[u][v] < w) adj[u][v] = adj[v][u] = w;
		}
		cin>>su>>sv;
		s = to_idx[su]; t = to_idx[sv];
		for (k=0; k<n; k++)
			for (i=0; i<n; i++)
				for (j=0; j<n; j++) 
						adj[i][j] = max(adj[i][j], min(adj[i][k], adj[k][j]));
		cout<<"Scenario #"<<tc++<<endl;
		cout<<adj[s][t]<<" tons"<<endl;
		cout<<endl;
	}
	
	return 0;
}
