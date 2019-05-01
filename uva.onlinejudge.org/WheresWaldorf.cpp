/*
	By: facug91
	From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=951
	Name: Where's Waldorf?
	Date: 30/06/2016
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

int n, m, k, b[55], dx[] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
string mat[55], s;
ii ans;

void kmpPreprocess () {
	int i = 0, j = -1; b[0] = -1;
	while (i < s.length()) {
		while (j >= 0 && s[i] != s[j]) j = b[j];
		i++; j++;
		b[i] = j;
	}
}

bool kmpSearch (int x, int y) {
	for (int d=0; d<8; d++) {
		int i = x, j = y, k = 0;
		while (i >= 0 && i < n && j >= 0 && j < m) {
			while (k >= 0 && mat[i][j] != s[k]) k = b[k];
			//if (x == 6 && y == 7) cerr<<"i "<<i<<" j "<<j<<" k "<<k<<endl;
			i += dx[d]; j += dy[d]; k++;
			if (k == s.length()) {
				int ax = i - dx[d] * k;
				int ay = j - dy[d] * k;
				if (ax < ans.F || (ax == ans.F && ay < ans.S)) ans = ii(ax, ay);
				//cerr<<"ax "<<ax<<" ay "<<ay<<endl;
				k = b[k];
			}
		}
	}
	return false;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(9); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>n>>m;
		for (i=0; i<n; i++) cin>>mat[i];
		for (i=0; i<n; i++) for (j=0; j<m; j++) mat[i][j] = tolower(mat[i][j]);
		cin>>k;
		while (k--) {
			cin>>s;
			for (i=0; i<s.length(); i++) s[i] = tolower(s[i]);
			kmpPreprocess();
			ans =  ii(INF, INF);
			for (i=0; i<n; i++) kmpSearch(i, 0), kmpSearch(i, m-1);
			for (j=0; j<m; j++) kmpSearch(0, j), kmpSearch(n-1, j);
			cout<<ans.F+1<<" "<<ans.S+1<<endl;
		}
		if (tc) cout<<endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
