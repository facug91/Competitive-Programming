/*
        By: facug91
        From: http://coj.uci.cu/contest/cproblem.xhtml?pid=3280&cid=1453
        Name: The Book Thief
        Date: 05/06/2015
*/
 
#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10000100
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

int s, x;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	while (cin>>s, s) {
		x = ceil((sqrt(s*8.0)-1.0)/2.0);
		if (((x*(x+1))/2) == s) x++;
		cout<<((x*(x+1))/2)-s<<" "<<x<<"\n";
	}
	
	return 0;
}
