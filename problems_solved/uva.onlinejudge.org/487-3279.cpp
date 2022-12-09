/*
	By: facug91
	From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=696
	Name: 487-3279
	Date: 16/11/2015
*/

#include <bits/stdc++.h>
#define next asjkdbg1238dv8ydf38gy832gf8yd
#define prev asjkdbuiqdg783gdiu3dg79832dui
#define EPS 1e-7
#define MP make_pair
#define DB(x) cerr << "#" << (#x) << ": " << (x) << " "
#define DBL(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10000100

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi; typedef vector<ii> vii;		   typedef vector<iii> viii;

int n;
string s, t;
int num[300];
map<string, int> col;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	num['A'] = num['B'] = num['C'] = '2';
	num['D'] = num['E'] = num['F'] = '3';
	num['G'] = num['H'] = num['I'] = '4';
	num['J'] = num['K'] = num['L'] = '5';
	num['M'] = num['N'] = num['O'] = '6';
	num['P'] = num['R'] = num['S'] = '7';
	num['T'] = num['U'] = num['V'] = '8';
	num['W'] = num['X'] = num['Y'] = '9';
	
	cin>>tc;
	while (tc--) {
		cin>>n;
		col.clear();
		while (n--) {
			cin>>s;
			t = "";
			for (char c : s) {
				if (c == '-') continue;
				if (c >= '0' && c <= '9') t += c;
				else t += num[c];
				if (t.length() == 3) t += "-"; 
			}
			col[t]++;
		}
		bool none = true;
		for (auto c : col) {
			if (c.second > 1) {
				cout<<c.first<<" "<<c.second<<endl;
				none = false;
			}
		}
		if (none) cout<<"No duplicates."<<endl;
		if (tc) cout<<endl;
	}
	 
	return 0;
}
