/*
        By: facug91
        From: https://www.facebook.com/hackercup/problem/881509321917182/
        Name: Boomerang Constellations
        Date: 10/01/2015
*/

#include <bits/stdc++.h>
#define endl "\n"
#define EPS 1e-2
#define MP make_pair
#define F first
#define S second
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

int n, x, y, ans, dis[2005][2005];
ii p[2005];
unordered_map<int, int> cont[2005];

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j, k;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>n;
		for (i=0; i<n; i++) cont[i].clear();
		for (i=0; i<n; i++) cin>>p[i].F>>p[i].S;
		for (i=0; i<n; i++) for (j=0; j<n; j++) if (i != j) {
			dis[i][j] = (p[i].F-p[j].F)*(p[i].F-p[j].F)+(p[i].S-p[j].S)*(p[i].S-p[j].S);
			cont[i][dis[i][j]]++;
		}
		ans = 0;
		for (i=0; i<n; i++) for (j=0; j<n; j++) if (i != j) ans += cont[j][dis[i][j]] - 1;
		cout<<"Case #"<<it<<": "<<ans/2<<endl;
	}
	
	return 0;
}
