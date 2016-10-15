/*
	By: facug91
	From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1394
	Name: Make Palindrome
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
#define move sdjifha978dyd9sag89
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

int DP[1005][1005], move[1005][1005];
string s;

int dp (int i, int j) {
	if (DP[i][j] != -1) return DP[i][j];
	if (i > j) {
		move[i][j] = -1;
		return DP[i][j] = 0;
	}
	if (i == j) {
		move[i][j] = -1;
		return DP[i][j] = 0;
	}
	if (s[i] == s[j]) {
		move[i][j] = 0;
		return DP[i][j] = dp(i+1, j-1);
	}
	if (dp(i+1, j) <= dp(i, j-1)) {
		move[i][j] = 1;
		DP[i][j] = dp(i+1, j) + 1;
	} else {
		move[i][j] = 2;
		DP[i][j] = dp(i, j-1) + 1;
	}
	return DP[i][j];
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(9); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j, k;
	
	while (getline(cin, s)) {
		for (i=0; i<(int)s.length(); i++) 
			for (j=0; j<(int)s.length(); j++)
				DP[i][j] = -1;
		cout<<dp(0, (int)s.length()-1);
		i = 0; j = (int)s.length()-1;
		string prefix = "", suffix = "";
		while (i <= j) {
			//cerr<<"i "<<i<<" j "<<j<<endl;
			if (i == j) {
				prefix += s[i];
				i++;
			} else if (move[i][j] == 0) {
				prefix += s[i];
				suffix += s[i];
				i++; j--;
			} else if (move[i][j] == 1) {
				prefix += s[i];
				suffix += s[i];
				i++;
			} else {
				prefix += s[j];
				suffix += s[j];
				j--;
			}
		}
		reverse(suffix.begin(), suffix.end());
		cout<<" "<<prefix<<suffix<<endl;
	}
	
	return 0;
}
