/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1415
        Name: Where is the Marble?
        Date: 30/03/2015
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

int n, q, x, num[10005], RSQ[10005];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int TC = 1, i;
	
	while (cin>>n>>q, n || q) {
		memset(num, 0, sizeof num);
		for (i=0; i<n; i++) {
			cin>>x;
			num[x]++;
		}
		RSQ[0] = 0;
		for (i=1; i<10005; i++) RSQ[i] = RSQ[i-1] + num[i-1];
		cout<<"CASE# "<<TC++<<":\n";
		for (i=0; i<q; i++) {
			cin>>x;
			if (num[x] == 0) cout<<x<<" not found\n";
			else cout<<x<<" found at "<<RSQ[x] + 1<<"\n";
		}
	}
	
	return 0;
}
