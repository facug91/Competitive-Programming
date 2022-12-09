/*
        By: facug91
        From: Google Code Jam - Qualification Round 2015 - Problem A Complete
        Name: Standing Ovation
        Date: 11/04/2015
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
typedef unsigned long long ull;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, act, ans;
string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(10); cerr<<fixed<<setprecision(10); //cout.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>n;
		cin>>s;
		act = ans = 0;
		for (int i=0; i<=n; i++) {
			if (act < i) {
				ans += (i-act);
				act = i;
			}
			act += (s[i]-'0');
		}
		cout<<"Case #"<<it<<": "<<ans<<"\n";
	}
	
	return 0;
}
