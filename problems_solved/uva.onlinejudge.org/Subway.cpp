/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1330
        Name: Subway
        Date: 18/10/2015
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
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 1100000000000000ll
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<int, ii> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iii> viii; typedef vector<iiii> viiii;

int n;
double x, y, adj[210][210];
vector<pair<double, double> > coor;
string line;

double dist (int i, int j) {
	return hypot(coor[i].F-coor[j].F, coor[i].S-coor[j].S);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j, k;
	
	cin>>tc;
	while (tc--) {
		coor.clear();
		cin>>x>>y;
		coor.push_back(MP(x, y));
		cin>>x>>y;
		coor.push_back(MP(x, y));
		getline(cin, line);
		n = 2;
		for (i=0; i<205; i++) for (j=0; j<205; j++) adj[i][j] = 0.0;
		while (getline(cin, line) && line.length()) {
			stringstream ss(line);
			ss>>x>>y;
			coor.push_back(MP(x, y));
			n++;
			while (ss>>x>>y, x != -1 || y != -1) {
				coor.push_back(MP(x, y));
				adj[n][n-1] = adj[n-1][n] = dist(n, n-1);
				n++;
			}
		}
		for (i=0; i<n; i++) for (j=i+1; j<n; j++) if (adj[i][j] == 0.0) adj[i][j] = adj[j][i] = dist(i, j) * 4.0;
		for (k=0; k<n; k++)	
			for (i=0; i<n; i++)
				for (j=0; j<n; j++)
					adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
		cout<<(ll)round(adj[0][1] * 3.0 / 2000.0)<<endl;
		if (tc != 0) cout<<endl;
	}
	
	return 0;
}
