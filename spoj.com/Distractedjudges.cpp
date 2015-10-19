/*
        By: facug91
        From: http://www.spoj.com/problems/TAP2014J/
        Name: Distracted judges
        Number: 21177
        Date: 07/10/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 131071
//#define MAXN 10000010

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int t, r[100005];
bool DP[100005];
vector<int> ans;

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>t;
	for (i=1; i<=t; i++) {
		cin>>r[i];
	}
	memset(DP, false, sizeof DP);
	ans.push_back(t);
	for (i=t-1; i>1; i--) {
		if ((i+r[i] == t) || ((i+r[i] < t) && DP[i+r[i]+1])) {
			ans.push_back(i-1);
			DP[i] = true;
		}
	}
	for (i=(int)ans.size()-1; i>=0; i--) {
		cout<<ans[i]<<endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
