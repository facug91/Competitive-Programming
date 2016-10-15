/*
	By: facug91
	From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=677
	Name: Lost in Space
	Date: 02/07/2016
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

int n, dx[] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
string mat[55], s, to_dir[8];
vector<iii> ans;

void search (int x, int y) {
	if (mat[x][y] == ' ') return;
	for (int d=0; d<8; d++) {
		int i = x, j = y, k = 0;
		while (i >= 0 && i < n && j >= 0 && j < n) {
			if (mat[i][j] == ' ') {
				i += dx[d]; j += dy[d];
				continue;
			}
			if (mat[i][j] != s[k]) break;
			i += dx[d]; j += dy[d]; k++;
			if (k == s.length()) ans.push_back(MP(MP(x, y), d));
		}
	}
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(9); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j, k;
	
	to_dir[0] = "N";
	to_dir[1] = "NE";
	to_dir[2] = "E";
	to_dir[3] = "SE";
	to_dir[4] = "S";
	to_dir[5] = "SW";
	to_dir[6] = "W";
	to_dir[7] = "NW";
	
	cin>>tc;
	while (tc--) {
		cin>>n; getline(cin, mat[0]);
		for (i=0; i<n; i++) getline(cin, mat[i]);
		while (getline(cin, s)) {
			if (s.length() == 0) break;
			ans.clear();
			for (i=0; i<n; i++) for (j=0; j<n; j++) search(i, j);
			sort(ans.begin(), ans.end());
			auto it = unique(ans.begin(), ans.end());
			ans.resize(distance(ans.begin(), it));
			cout<<endl<<s<<endl;
			if (ans.size() == 0) cout<<"not found"<<endl;
			for (i=0; i<ans.size(); i++) cout<<"("<<ans[i].F.F+1<<","<<ans[i].F.S+1<<") - "<<to_dir[ans[i].S]<<endl;
		}
		if (tc) cout<<endl;
	}
	
	return 0;
}
