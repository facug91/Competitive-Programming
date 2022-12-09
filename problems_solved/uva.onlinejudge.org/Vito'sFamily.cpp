/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=982
        Name: Vito's Family
        Date: 10/04/2015
*/

#include <bits/stdc++.h>
#define left ksajdsadhbqak3b49u3yhf
#define right adjkhsakjdjbsd9374ywd9
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

int n, s[505], ans, left, right, lsum, rsum;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(10); cerr<<fixed<<setprecision(10); //cout.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>n;
		lsum = rsum = 0;
		for (i=0; i<n; i++) {
			cin>>s[i];
			rsum += s[i];
		}
		sort(s, s+n);
		ans = INT_MAX; left = 0; right = n;
		for (i=1, j=0; i<=s[n-1]; i++) {
			rsum -= right; lsum += left;
			if (ans > rsum+lsum) ans = rsum+lsum;
			while (i == s[j]) {
				right--;
				left++;
				j++;
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
