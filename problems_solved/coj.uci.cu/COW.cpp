/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=3157
        Name: COW
        Date: 28/03/2015
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

int n;
ll c, o, ans;
string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int i;
	
	c = o = 0ll;
	cin>>n;
	cin>>s;
	ans = 0ll;
	for (i=0; i<n; i++) {
		if (s[i] == 'C') c++;
		else if (s[i] == 'O') o += c;
		else if (s[i] == 'W') ans += o;
	}
	cout<<ans<<"\n";
	
	return 0;
}
