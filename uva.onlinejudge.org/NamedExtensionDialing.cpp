/*
	By: facug91
	From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=827
	Name: Named Extension Dialing
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

int to_num[300];
vector<string> words_map, expr;
string s, t, n;
set<string> exp_check;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(9); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j;
	
	to_num['a'] = to_num['b'] = to_num['c'] = '2';
	to_num['d'] = to_num['e'] = to_num['f'] = '3';
	to_num['g'] = to_num['h'] = to_num['i'] = '4';
	to_num['j'] = to_num['k'] = to_num['l'] = '5';
	to_num['m'] = to_num['n'] = to_num['o'] = '6';
	to_num['p'] = to_num['q'] = to_num['r'] = to_num['s'] = '7';
	to_num['t'] = to_num['u'] = to_num['v'] = '8';
	to_num['w'] = to_num['x'] = to_num['y'] = to_num['z'] = '9';
	
	while (cin>>s, 'a' <= tolower(s[0]) && tolower(s[0]) <= 'z') {
		cin>>t>>n;
		exp_check.insert(n);
		string aux = "";
		aux += to_num[tolower(s[0])];
		for (i=0; i<t.length(); i++) aux += to_num[tolower(t[i])];
		words_map.push_back(aux);
		expr.push_back(n);
	}
	n = s;
	do {
		if (exp_check.find(n) != exp_check.end()) cout<<n<<endl;
		else {
			bool first = true;
			for (i=0; i<words_map.size(); i++) {
				if (expr.size() < n.length()) continue;
				bool valid = true;
				for (j=0; j<n.length(); j++) if (words_map[i][j] != n[j]) valid = false;
				if (valid) {
					if (first) first = false;
					else cout<<" ";
					cout<<expr[i];
				}
			}
			if (first) cout<<0;
			cout<<endl;
		}
	} while (cin>>n);
	
	return 0;
}
