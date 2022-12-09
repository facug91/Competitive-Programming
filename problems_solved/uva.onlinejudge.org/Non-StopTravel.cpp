/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=277
        Name: Non-Stop Travel
        Date: 19/11/2015
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

int n, m, u, v, w, s, t, adj[15][15], father[15][15];

void printPath (int i, int j) {
	if (i != j) printPath(i, father[i][j]);
	cout<<" "<<j+1;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(4); //cerr<<fixed<<setprecision(4); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j, k;
	
	while (cin>>n, n) {
		for (i=0; i<n; i++) for (j=0; j<n; j++) {
			adj[i][j] = INF;
			father[i][j] = i;
		}
		for (i=0; i<n; i++) adj[i][i] = 0;
		for (u=0; u<n; u++) {
			cin>>m;
			while (m--) {
				cin>>v>>w; v--;
				adj[u][v] = w;
			}
		}
		cin>>s>>t; s--; t--;
		for (k=0; k<n; k++)
			for (i=0; i<n; i++)
				for (j=0; j<n; j++)
					if (adj[i][j] > adj[i][k] + adj[k][j]) {
						adj[i][j] = adj[i][k] + adj[k][j];
						father[i][j] = father[k][j];
					}
		cout<<"Case "<<tc++<<": Path =";
		printPath(s, t);
		cout<<"; "<<adj[s][t]<<" second delay"<<endl;
	}
	
	return 0;
}
