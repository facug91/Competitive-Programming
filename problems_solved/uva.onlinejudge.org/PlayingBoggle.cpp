/*
	By: facug91
	From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2258
	Name: Playing Boggle
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

int n, points, dx[] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
string mat[4];
string s;
bool vis[4][4];

bool dfs (int x, int y, int len) {
	if (len == s.length()) return true;
	vis[x][y] = true;
	for (int d=0; d<8; d++) {
		int w = x + dx[d];
		int z = y + dy[d];
		if (w >= 0 && w < 4 && z >= 0 && z < 4 && !vis[w][z] && mat[w][z] == s[len]) if (dfs(w, z, len+1)) {
			vis[x][y] = false;
			return true;
		}
	}
	vis[x][y] = false;
	return false;
}

bool search () {
	for (int i=0; i<4; i++) for (int j=0; j<4; j++) if (mat[i][j] == s[0] && dfs(i, j, 1)) return true;
	return false;
}

int to_points (int len) {
	if (len == 3 || len == 4) return 1;
	if (len == 5) return 2;
	if (len == 6) return 3;
	if (len == 7) return 5;
	if (len >= 8) return 11;
	return 0;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(9); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j, k;
	
	memset(vis, 0, sizeof vis);
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		for (i=0; i<4; i++) cin>>mat[i];
		cin>>n;
		points = 0;
		while (n--) {
			cin>>s;
			if (search()) points += to_points(s.length());
		}
		cout<<"Score for Boggle game #"<<it<<": "<<points<<endl;
	}
	
	return 0;
}
