/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=9
        Name: Exact Sum
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

int n, m, b[10005], l, r;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int i, j;
	
	while (cin>>n) {
		for (i=0; i<n; i++) cin>>b[i];
		sort(b, b+n);
		cin>>m;
		j = n-1;
		for (i=0; i<j; i++) {
			while (i < j && b[i]+b[j] > m) j--;
			if (i < j && b[i]+b[j] == m) {
				l = i;
				r = j;
			}
		}
		cout<<"Peter should buy books whose prices are "<<b[l]<<" and "<<b[r]<<".\n\n";
	}
	
	return 0;
}
