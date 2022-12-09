/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3886
        Name: Bars
        Date: 24/02/2015
*/

#include <bits/stdc++.h>
#define count asljdhasjld
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, m, p[25];
bool vis[21][1005];

bool dfs (int idx, int sum) {
	if (sum == n) return true;
	if (sum > n || idx == m) return false;
	if (vis[idx][sum]) return false;
	return vis[idx][sum] = (dfs(idx+1, sum) || dfs(idx+1, sum+p[idx]));
} 

int main () {
	ios_base::sync_with_stdio(0);
	cout << fixed << setprecision(10);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		cin>>n>>m;
		for (i=0; i<m; i++) cin>>p[i];
		memset(vis, 0, sizeof vis);
		if (dfs(0, 0)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	return 0;
}
