/*
        By: facug91
        From: http://coj.uci.cu/contest/cproblem.xhtml?pid=3285&cid=1453
        Name: Toby and Strange Function
        Date: 05/06/2015
*/
 
#include <bits/stdc++.h>
#define time alkjdhasjldh3289rhau9dty
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

ll n;
string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>n>>s;
		n %= s.length();
		for (i=(int)s.length()-n; i<s.length(); i++) cout<<s[i];
		n = (int)s.length()-n;
		for (i=0; i<n; i++) cout<<s[i];
		cout<<"\n";
	}
	
	return 0;
}
