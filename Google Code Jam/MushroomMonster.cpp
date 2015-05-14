/*
        By: facug91
        From: Google Code Jam - Round 1A  2015 - Problem A Complete
        Name: Mushroom Monster
        Date: 17/04/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

ll n, m[1005], ans1, max2, ans2;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(4); cerr<<fixed<<setprecision(10); //cout.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>n;
		for (i=0; i<n; i++) cin>>m[i];
		ans1 = 0;
		for (i=1; i<n; i++) {
			ans1 += max(m[i-1]-m[i], 0ll);
		}
		max2 = 0;
		for (i=1; i<n; i++) {
			max2 = max(max2, max(m[i-1]-m[i], 0ll));
		}
		ans2 = 0;
		for (i=0; i<n-1; i++) {
			ans2 += min(m[i], max2);
		}
		cout<<"Case #"<<it<<": "<<ans1<<" "<<ans2<<"\n";
	}
	
	return 0;
}
