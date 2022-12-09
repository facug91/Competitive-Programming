/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3391
        Name: Bingo!
        Date: 31/12/2015
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

int n, m, b[100];
bool in[100];

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j;
	
	while (cin>>n>>m, n || m) {
		for (i=0; i<m; i++) cin>>b[i];
		memset(in, 0, sizeof in);
		for (i=0; i<m; i++) for (j=i; j<m; j++) in[abs(b[i]-b[j])] = true;
		bool ans = true;
		for (i=0; i<=n; i++) if (!in[i]) ans = false;
		if (ans) cout<<"Y"<<endl;
		else cout<<"N"<<endl;
	}
	
	return 0;
}
