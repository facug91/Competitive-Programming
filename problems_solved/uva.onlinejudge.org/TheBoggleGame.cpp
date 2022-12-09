/*
	By: facug91
	From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=545
	Name: The Boggle Game
	Date: 01/07/2016
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define prev bjasdbi132ge79qwgdi
#define next usayhkdgisaydgiy212
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
//#define MOD 100000007
//#define MAXN 10000005

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, int> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; //insert, find_by_order, order_of_key, erase

int sum, dx[] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
string mat[2][4], aux;
vector<string> ans[2];
bool vis[4][4];

bool isVowel (char c) {
	return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y';
}

void dfs (int x, int y, int idx, string& curr) {
	curr += mat[idx][x][y];
	if (curr.length() == 4) {
		int vowels = isVowel(curr[0]) + isVowel(curr[1]) + isVowel(curr[2]) + isVowel(curr[3]);
		if (vowels == 2) ans[idx].push_back(curr);
		curr.pop_back();
		return;
	}
	vis[x][y] = true;
	int w, z;
	for (int d=0; d<8; d++) {
		w = x + dx[d];
		z = y + dy[d];
		if (w >= 0 && w < 4 && z >= 0 && z < 4 && !vis[w][z]) dfs(w, z, idx, curr);
	}
	vis[x][y] = false;
	curr.pop_back();
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(9); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j, k;
	
	while (cin>>mat[0][0][0], mat[0][0][0] != '#') {
		if (tc++ != 1) cout<<endl;
		for (i=1; i<4; i++) cin>>mat[0][0][i];
		for (i=0; i<4; i++) cin>>mat[1][0][i];
		for (j=1; j<4; j++) {
			for (i=0; i<4; i++) cin>>mat[0][j][i];
			for (i=0; i<4; i++) cin>>mat[1][j][i];
		}
		ans[0].clear(); ans[1].clear(); aux = "";
		memset(vis, 0, sizeof vis);
		for (k=0; k<2; k++) for (int i=0; i<4; i++) for (j=0; j<4; j++) dfs(i, j, k, aux);
		for (k=0; k<2; k++) {
			sort(ans[k].begin(), ans[k].end());
			vector<string>::iterator itr = unique(ans[k].begin(), ans[k].end());
			ans[k].resize(distance(ans[k].begin(), itr));
		}
		bool found = false;
		i = 0; j = 0;
		for (; i<ans[0].size(); i++) for (; j<ans[1].size(); j++) {
			if (ans[0][i] == ans[1][j]) {
				cout<<ans[0][i]<<endl;
				j++;
				found = true;
				break;
			}
			if (ans[0][i] < ans[1][j]) break;
		}
		if (!found) cout<<"There are no common words for this pair of boggle boards."<<endl;
	}
	
	return 0;
}
