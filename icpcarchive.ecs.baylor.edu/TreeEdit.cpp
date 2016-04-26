/*
	By: facug91
	From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5248
	Name: Tree Edit
	Date: 25/04/2016
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
//#define MOD 1000000007ll
#define MAXN 100000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

string a, s[2];
int DP[2005][2005], size[2][2005], leaf[2][2005], level[2][2005], father[2][2005];
stack<int> stk;
vi tree[2][2005];

void dfs (int w, int u, int l) {
	level[w][u] = l;
	for (int v : tree[w][u]) dfs(w, v, l+1);
}

int dp (int i, int j) {
	if (DP[i][j] != -1) return DP[i][j];
	if (i >= s[0].length() && j >= s[1].length()) return DP[i][j] = 0;
	if (i >= s[0].length()) return DP[i][j] = dp(i, j+size[1][j]+leaf[1][j]+(s[1][j]=='*'))+size[1][j];
	if (j >= s[1].length()) return DP[i][j] = dp(i+size[0][i]+leaf[0][i]+(s[0][i]=='*'), j)+size[0][i];
	if (s[0][i] == '*' && s[1][j] == '*') return DP[i][j] = dp(i+1, j+1);
	if (s[0][i] == '*') return DP[i][j] = dp(i+1, j+size[1][j]+leaf[1][j]) + size[1][j];
	if (s[1][j] == '*') return DP[i][j] = dp(i+size[0][i]+leaf[0][i], j+1) + size[0][i];
	if (level[0][father[0][i]] > level[1][father[1][j]]) return DP[i][j] = dp(i+size[0][i]+leaf[0][i], j) + size[0][i];
	if (level[0][father[0][i]] < level[1][father[1][j]]) return DP[i][j] = dp(i, j+size[1][j]+leaf[1][j]) + size[1][j];
	int ans = dp(i+1, j+1) + (s[0][i] != s[1][j]);
	ans = min(ans, dp(i, j+size[1][j]+leaf[1][j]) + size[1][j]);
	ans = min(ans, dp(i+size[0][i]+leaf[0][i], j) + size[0][i]);
	return DP[i][j] = ans;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	cin>>tc;
	while (tc--) {
		for (int w=0; w<2; w++) {
			cin>>a;
			s[w] = "";
			father[w][0] = -1;
			for (i=0; i<2005; i++) tree[w][i].clear();
			for (i=0; i<a.length(); i++) {
				if (a[i] == '(') {
					i++;
					s[w] += a[i];
					stk.push(s[w].length()-1);
					size[w][s[w].length()-1] = 1;
					leaf[w][s[w].length()-1] = 0;
				} else if (a[i-1] != ')') {
					int tmp = stk.top(); stk.pop();
					leaf[w][tmp] = 1;
					if (stk.size()) {
						leaf[w][stk.top()]++;
						size[w][stk.top()]++;
						tree[w][stk.top()].push_back(tmp);
						father[w][tmp] = stk.top();
					}
					s[w] += "*";
					size[w][s[w].length()-1] = 0;
					leaf[w][s[w].length()-1] = 0;
				} else {
					int tmp = stk.top(); stk.pop();
					if (stk.size()) {
						leaf[w][stk.top()] += leaf[w][tmp];
						size[w][stk.top()] += size[w][tmp];
						tree[w][stk.top()].push_back(tmp);
						father[w][tmp] = stk.top();
					}
				}
			}
			dfs(w, 0, 0);
		}
		memset(DP, -1, sizeof DP);
		cout<<dp(0, 0)<<endl;
	}
	
	return 0;
}
