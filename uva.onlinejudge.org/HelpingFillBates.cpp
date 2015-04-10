/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1508
        Name: Helping Fill Bates
        Date: 02/04/2015
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

int q, act, l, r;
bool ok;
string s, ss;
map<char, vi> mp;
vi::iterator itr;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int i, j;
	
	cin>>s;
	for (i=0; i<s.length(); i++) mp[s[i]].push_back(i);
	cin>>q;
	while (q--) {
		cin>>ss;
		act = 0; ok = true;
		l = r = -1;
		for (i=0; i<ss.length(); i++) {
			itr = lower_bound(mp[ss[i]].begin(), mp[ss[i]].end(), act);
			if (itr == mp[ss[i]].end()) {
				ok = false;
				break;
			}
			if (l == -1) l = *itr;
			r = *itr;
			act = *itr + 1;
		}
		if (!ok) cout<<"Not matched\n";
		else cout<<"Matched "<<l<<" "<<r<<"\n";
	}
	
	return 0;
}
