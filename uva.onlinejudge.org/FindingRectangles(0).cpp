/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=579
        Name: Finding Rectangles
        Date: 15/02/2016
*/

#include <bits/stdc++.h>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
#define MOD 1000000007ll
//#define MAXN 10005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, x, y;
ii point[30];
vi r[30], d[30];
char id[30];
vector<string> ans;
string aux;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j, k, l;
	
	while (cin>>n, n) {
		for (i=0; i<n; i++) {
			cin>>id[i]>>point[i].F>>point[i].S;
			r[i].clear();
			d[i].clear();
		}
		for (i=0; i<n; i++) for (j=0; j<n; j++) if (i != j) {
			if (point[i].F == point[j].F && point[i].S < point[j].S) d[i].push_back(j);
			if (point[i].S == point[j].S && point[i].F < point[j].F) r[i].push_back(j);
		}
		ans.clear();
		for (i=0; i<n; i++) for (j=0; j<d[i].size(); j++) for (k=0; k<r[i].size(); k++) for (l=0; l<d[r[i][k]].size(); l++) 
			if (point[d[i][j]].F-point[i].F == point[d[r[i][k]][l]].F-point[r[i][k]].F && 
				point[r[i][k]].S-point[i].S == point[d[r[i][k]][l]].S-point[d[i][j]].S) {
				aux = "";
				aux += id[d[i][j]];
				aux += id[d[r[i][k]][l]];
				aux += id[r[i][k]];
				aux += id[i];
				ans.push_back(aux);
			}
		sort(ans.begin(), ans.end());
		if (ans.size()) {
			cout<<"Point set "<<tc++<<":"<<endl;
			i = 0;
			while (i < ans.size()) {
				for (j=i; j<min((int)ans.size(), i+10); j++) cout<<" "<<ans[j];
				cout<<endl;
				i += 10;
			}
		} else cout<<"Point set "<<tc++<<": No rectangles"<<endl;
	}
	
	return 0;
}
