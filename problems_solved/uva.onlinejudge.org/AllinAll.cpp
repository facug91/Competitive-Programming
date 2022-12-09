/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1281
        Name: All in All
        Date: 06/04/2015
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

string s, t;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(10); cerr<<fixed<<setprecision(10);
	int i, j;
	
	while (cin>>s>>t) {
		i = j = 0;
		while (i<s.length() && j < t.length()) {
			while (j<t.length() && s[i] != t[j]) j++;
			if (s[i] == t[j]) i++;
			j++;
		}
		if (i == s.length()) cout<<"Yes\n";
		else cout<<"No\n";
	}
	
	return 0;
}
