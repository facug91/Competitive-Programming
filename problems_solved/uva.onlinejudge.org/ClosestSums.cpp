/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1428
        Name: Closest Sums
        Date: 07/03/2016
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
#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, a[1005], q, m, ans;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	
	while (cin>>n, n) {
		for (i=0; i<n; i++) cin>>a[i];
		cin>>q;
		cout<<"Case "<<tc++<<":"<<endl;
		while (q--) {
			cin>>m;
			ans = INF;
			for (i=0; i<n; i++) for (j=i+1; j<n; j++) if (abs(ans-m) > abs(a[i]+a[j]-m)) ans = a[i]+a[j];
			cout<<"Closest sum to "<<m<<" is "<<ans<<"."<<endl;
		}
	}
	
	return 0;
}
