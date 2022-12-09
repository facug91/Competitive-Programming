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
bool grid[55][55];
char c, point[55][55];
vector<string> ans;
string aux;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j, k, l;
	
	while (cin>>n, n) {
		memset(grid, 0, sizeof grid);
		for (i=0; i<n; i++) {
			cin>>c>>x>>y;
			grid[x][y] = true;
			point[x][y] = c;
		}
		ans.clear();
		for (i=0; i<50; i++) for (j=0; j<50; j++) 
			if (grid[i][j])
				for (k=1; i+k<50; k++) for (l=1; j+l<50; l++)
					if (grid[i+k][j] && grid[i][j+l] && grid[i+k][j+l]) {
						aux = "";
						aux += point[i][j+l];
						aux += point[i+k][j+l];
						aux += point[i+k][j];
						aux += point[i][j];
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
