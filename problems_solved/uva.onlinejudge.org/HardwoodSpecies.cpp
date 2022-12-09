/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1167
        Name: Hardwood Species
        Date: 13/04/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int total;
string s;
map<string, int> mp;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout<<fixed<<setprecision(4); cerr<<fixed<<setprecision(10); //cout.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	cin>>tc;
	getline(cin, s);
	getline(cin, s);
	while (tc--) {
		mp.clear(); total = 0;
		while (getline(cin, s), s.length()) {
			mp[s]++;
			total++;
		}
		for (map<string, int>::iterator itr=mp.begin(); itr!=mp.end(); itr++) {
			cout<<(*itr).first<<" "<<(double)(*itr).second*100.0/(double)total<<"\n";
		}
		if (tc) cout<<"\n";
	}
	
	return 0;
}
