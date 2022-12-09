/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3678
        Name: Expert Enough?
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

int n, l[10005], h[10005], q, p, cnt;
string m[10005], ans;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>n;
		for (i=0; i<n; i++) cin>>m[i]>>l[i]>>h[i];
		cin>>q;
		for (i=0; i<q; i++) {
			cin>>p;
			cnt = 0;
			for (j=0; j<n; j++) if (l[j] <= p && p <= h[j]) {
				cnt++;
				ans = m[j];
			}
			if (cnt == 1) cout<<ans<<endl;
			else cout<<"UNDETERMINED"<<endl;
		}
		if (tc) cout<<endl;
	}
	
	return 0;
}
