/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2729
        Name: RIJECI
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

int k, a[2], b[2], f, s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin>>k;
	a[0] = 1; b[0] = 0; f = 0; s = 1;
	while (k--) {
		a[s] = b[f];
		b[s] = b[f] + a[f];
		swap(f, s);
	}
	cout<<a[f]<<" "<<b[f]<<"\n";
	
	return 0;
}
