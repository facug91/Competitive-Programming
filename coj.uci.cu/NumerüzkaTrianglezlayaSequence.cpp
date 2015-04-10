/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2458
        Name: Numerüzka Trianglezlaya Sequence
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

ll x, n;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(10); cerr<<fixed<<setprecision(10);
	
	while (cin>>x, x) {
		n = (ll)ceil((sqrt(x*8.0+1.0) - 1.0) / 2.0);
		cout<<n<<"\n";
	}
	
	return 0;
}
