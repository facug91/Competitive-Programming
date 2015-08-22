/*
        By: facug91
        From: http://coj.uci.cu/contest/cproblem.xhtml?pid=3299&cid=1453
        Name: How Many Triangular Numbers?
        Date: 06/06/2015
*/
 
#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
#define MOD 1000000007
//#define MAXN 10000100
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

ll a, b, DP[2000005];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(9); //cerr<<fixed<<setprecision(10); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	
	for (ll i=0; i<2000005; i++) DP[i] = (i*(i+1ll))/2ll;
	while (cin>>a>>b, a || b) {
		cout<<(upper_bound(DP, DP+2000005, b)-1-DP)-(lower_bound(DP, DP+2000005, a)-1-DP)<<"\n";
	}
	
	return 0;
}
