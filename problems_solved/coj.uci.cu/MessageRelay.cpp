/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2270
        Name: Message Relay
        Date: 28/10/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, f, ans;
vector<int> cows[1005], init;

void dfs (int idx) {
	ans++;
	for (int i=0; i<(int)cows[idx].size(); i++)
		dfs(cows[idx][i]);
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>n;
	for (i=1; i<=n; i++) {
		cin>>f;
		if (f == 0) init.push_back(i);
		else cows[f].push_back(i);
	}
	ans = 0;
	for (i=0; i<(int)init.size(); i++)
		dfs(init[i]);
	cout<<ans<<endl;
	
	return 0;
}
