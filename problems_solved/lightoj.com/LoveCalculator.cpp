/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1013
	Name: Love Calculator
	Date: 05/07/2016
*/

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define prev bjasdbi132ge79qwgdi
#define next usayhkdgisaydgiy212
#define move sdjifha978dyd9sag89
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
//#define MOD 100000007
//#define MAXN 10000005

using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, int> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; //insert, find_by_order, order_of_key, erase

ll n, m, LCS[35][35], CNT[35][35];
string s, t;

ll lcs () {
	int i, j;
	for (i=0; i<=n; i++) LCS[i][0] = 0;
	for (j=0; j<=m; j++) LCS[0][j] = 0;
	for (i=1; i<=n; i++) for (j=1; j<=m; j++) {
		if (s[i-1] == t[j-1]) LCS[i][j] = LCS[i-1][j-1] + 1;
		else LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
	}
	return LCS[n][m];
}

ll cnt (int i, int j) {
	if (CNT[i][j] != -1) return CNT[i][j];
	if (i == 0 || j == 0) return CNT[i][j] = 1ll;
	CNT[i][j] = 0LL;
	if (s[i-1] == t[j-1]) CNT[i][j] += cnt(i-1, j-1);
	else {
		if (LCS[i][j] == LCS[i-1][j]) CNT[i][j] += cnt(i-1, j);
		if (LCS[i][j] == LCS[i][j-1]) CNT[i][j] += cnt(i, j-1);
	}
	return CNT[i][j];
}

int main () {
	//#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	//#endif
	//cout<<fixed<<setprecision(9); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j, k;
	
	cin>>tc; getline(cin, s);
	for (int it=1; it<=tc; it++) {
		getline(cin, s);
		getline(cin, t);
		n = s.length();
		m = t.length();
		memset(CNT, -1, sizeof CNT);
		cout<<"Case "<<it<<": "<<n+m-lcs()<<" ";
		cout<<cnt(n, m)<<endl;
	}
	
	return 0;
}
