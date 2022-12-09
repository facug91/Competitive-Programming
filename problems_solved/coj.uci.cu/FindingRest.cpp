/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2661
        Name: Finding Rest
        Date: 03/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000000ll
//#define MAXN 4000000000ll

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int power, ans;
string n;

int main () {
	ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j;
	
	while (cin>>n) {
		power = 0;
		for (i=0; i<n.length(); i++) power = (power + n[i] - '0') % 6;
		ans = 1;
		for (i=0; i<power; i++) ans = (ans * 7) % 9;
		cout<<ans<<endl;
	}
	
	return 0;
}
