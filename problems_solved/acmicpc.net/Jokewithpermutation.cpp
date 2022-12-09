/*
        By: facug91
        From: https://www.acmicpc.net/problem/10597
        Name: Jokewithpermutation
        Date: 28/05/2015
*/
 
#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10000100
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

int n;
string s;
bool vis[105];
vi ans;

void dfs (int idx) {
	if (idx >= s.length()) return;
	int act = s[idx]-'0';
	if (act != 0 && !vis[act]) {
		vis[act] = true;
		ans.push_back(act);
		dfs(idx+1);
		if (ans.size() == n) return;
		ans.pop_back();
		vis[act] = false;
	}
	if (idx+1 >= s.length()) return;
	act = act*10 + s[idx+1]-'0';
	if (act != 0 && act <= n && !vis[act]) {
		vis[act] = true;
		ans.push_back(act);
		dfs(idx+2);
		if (ans.size() == n) return;
		ans.pop_back();
		vis[act] = false;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin>>s;
	if (s.length() < 10) n = s.length();
	else n = 9 + (s.length()-9)/2;
	memset(vis, 0, sizeof vis);
	dfs(0);
	for (int i=0; i<ans.size(); i++) cout<<ans[i]<<" \n"[i==ans.size()-1];
	
	return 0;
}
