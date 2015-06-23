/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=526&page=show_problem&problem=3891
        Name: Vigenère Cipher Encryption
        Date: 23/06/2015
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

string s, t, ans;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	
	while (cin>>s, s[0] != '0') {
		cin>>t;
		ans = "";
		for (int i=0; i<t.length(); i++) {
			ans.push_back((char)((((t[i]-'A')+(s[i%((int)s.length())]-'A')+1)%26)+'A'));
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
