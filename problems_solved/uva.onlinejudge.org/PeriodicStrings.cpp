/*
	By: facug91
	From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=396
	Name: Periodic Strings
	Date: 21/06/2016
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

string p;
int b[100], m;

void kmp_preprocess () {
	int i = 1, j = -1; b[0] = -1;
	while (i < m) {
		while (j >= 0 && p[j+1] != p[i]) j = b[j];
		if (p[j+1] == p[i]) j++;
		b[i] = j;
		i++;
	}
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(9); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j;
	
	cin>>tc;
	getline(cin, p);
	while (tc--) {
		getline(cin, p);
		getline(cin, p);
		m = p.length();
		kmp_preprocess();
		//for (i=0; i<m; i++) cerr<<b[i]<<" ";
		//cerr<<endl;
		if (m % (m - b[m-1] - 1) == 0) cout<<(m - b[m-1] - 1)<<endl;
		else cout<<m<<endl;
		if (tc) cout<<endl;
	}
	
	return 0;
}
