/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1018
        Name: The Stern-Brocot Number System
        Date: 31/03/2015
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

int n, m;
string ans;

void binary_search (ii l, ii c, ii r) {
	if (c.first == n && c.second == m) return;
	if ((double)c.first/(double)c.second > (double)n/(double)m) {
		ans += 'L';
		binary_search(l, ii(l.first+c.first, l.second+c.second), c);
	} else {
		ans += 'R';
		binary_search(c, ii(r.first+c.first, r.second+c.second), r);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	while (cin>>n>>m, n != 1 || m != 1) {
		ans = "";
		binary_search(ii(0, 1), ii(1, 1), ii(1, 0));
		cout<<ans<<"\n";
	}
	
	return 0;
}
