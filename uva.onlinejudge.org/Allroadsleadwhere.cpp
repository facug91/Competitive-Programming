/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=950
        Name: All roads lead where
        Date: 14/10/2015
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
//#define MAXN 10005
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, m, q, u, v, adj[30][30], f[30][30];
string s, t;

void print_path (int i, int j) {
	if (i != j) print_path(i, f[i][j]);
	cout<<(char)(j+'A');
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j, k, tc;
	
	cin>>tc;
	while (tc--) {
		cin>>m>>q;
		n = 26;
		for (i=0; i<n; i++) {
			for (j=0; j<n; j++) {
				adj[i][j] = INF;
				f[i][j] = i;
			}
			adj[i][j] = 0;
		}
		while (m--) {
			cin>>s>>t;
			adj[s[0]-'A'][t[0]-'A']  = adj[t[0]-'A'][s[0]-'A'] = 1;
		}
		for (k=0; k<n; k++) {
			for (i=0; i<n; i++) {
				for (j=0; j<n; j++) {
					if (adj[i][j] > adj[i][k] + adj[k][j]) {
						adj[i][j] = adj[i][k] + adj[k][j];
						f[i][j] = f[k][j];
					}
				}
			}
		}
		while (q--) {
			cin>>s>>t;
			print_path(s[0]-'A', t[0]-'A');
			cout<<endl;
		}
		if (tc != 0) cout<<endl;
	}
	
	return 0;
}
