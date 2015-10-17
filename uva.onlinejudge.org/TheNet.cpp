/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=568
        Name: The Net
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

int n, q, idu, idv, u, v, idn, adj[305][305], f[305][305];
unordered_map<int, int> id_to_idx, idx_to_id;
string s;
char c;

bool first;
void print_path (int i, int j) {
	if (i != j) print_path(i, f[i][j]);
	if (first) first = false;
	else cout<<" ";
	cout<<idx_to_id[j];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j, k, tc;
	
	while (cin>>n) {
		id_to_idx.clear();
		idx_to_id.clear();
		for (i=0; i<305; i++) {
			for (j=0; j<305; j++) {
				adj[i][j] = INF;
				f[i][j] = i;
			}
			adj[i][i] = 0;
		}
		idn = 0;
		for (i=0; i<n; i++) {
			cin>>idu;
			if (id_to_idx.find(idu) == id_to_idx.end()) {
				id_to_idx[idu] = idn;
				idx_to_id[idn++] = idu;
			}
			u = id_to_idx[idu];
			getline(cin, s);
			stringstream ss(s);
			while (ss>>c>>idv) {
				if (id_to_idx.find(idv) == id_to_idx.end()) {
					id_to_idx[idv] = idn;
					idx_to_id[idn++] = idv;
				}
				v = id_to_idx[idv];
				adj[u][v] = 1;
			}
		}
		for (k=0; k<n; k++) {
			for (i=0; i<n; i++) {
				for (j=0; j<n; j++) {
					if (adj[i][k] + adj[k][j] < adj[i][j]) {
						adj[i][j] = adj[i][k] + adj[k][j];
						f[i][j] = f[k][j];
					}
				}
			}
		}
		cin>>q;
		cout<<"-----"<<endl;
		while (q--) {
			cin>>idu>>idv;
			u = id_to_idx[idu];
			v = id_to_idx[idv];
			if (adj[u][v] == INF) {
				cout<<"connection impossible"<<endl;
				continue;
			}
			first = true;
			print_path(u, v);
			cout<<endl;
		}
	}
	
	return 0;
}
