/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1552
        Name: The Playboy Chimp
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

int n, q, x;
vi c;
vi::iterator itr;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int i, j;
	
	cin>>n;
	for (i=0; i<n; i++) cin>>x, c.push_back(x);
	cin>>q;
	for (i=0; i<q; i++) {
		cin>>x;
		itr = lower_bound(c.begin(), c.end(), x);
		if (itr == c.begin()) cout<<"X";
		else cout<<(*(--itr));
		itr = upper_bound(c.begin(), c.end(), x);
		if (itr == c.end()) cout<<" X\n";
		else cout<<" "<<(*itr)<<"\n";
	}
	
	return 0;
}
