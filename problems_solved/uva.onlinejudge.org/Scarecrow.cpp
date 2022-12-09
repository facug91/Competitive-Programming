/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3836
        Name: Scarecrow
        Date: 05/04/2015
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

int n, ans;
string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int TC, i, j;
	
	cin>>TC;
	for (int it=1; it<=TC; it++) {
		cin>>n;
		cin>>s;
		i = ans = 0;
		while (i < s.length()) {
			if (s[i] == '.') {
				ans++;
				i += 3;
			} else i++;
		}
		cout<<"Case "<<it<<": "<<ans<<"\n";
	}
	
	return 0;
}
