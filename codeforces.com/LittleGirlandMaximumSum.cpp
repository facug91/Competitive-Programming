/*
        By: facug91
        From: http://codeforces.com/contest/276/problem/C
        Name: Little Girl and Maximum Sum
        Date: 03/09/2015
*/
 
#include <bits/stdc++.h>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 4294967296ll
//#define MAXN 1001
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

ll n, q, l, r, arr[200005], queries[200005], ans;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j;
	
	cin>>n>>q;
	for (i=0; i<n; i++) cin>>arr[i];
	sort(arr, arr+n);
	memset(queries, 0, sizeof queries);
	while (q--) {
		cin>>l>>r; l--; r--;
		queries[l]++;
		queries[r+1]--;
	}
	for (i=1; i<n; i++) queries[i] += queries[i-1];
	sort(queries, queries+n);
	ans = 0ll;
	for (i=0; i<n; i++) ans += (ll)(arr[i]*queries[i]);
	cout<<ans<<endl;
	
	return 0;
}
