/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4415
        Name: SecurePINs
        Date: 13/02/2015
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int d[10];
string s;

int main () {
	ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		cin>>s;
		bool ok = true;
		memset(d, 0, sizeof d);
		for (i=0; i<6; i++) d[s[i]-'0']++;
		for (i=0; i<10; i++) if (d[i] >= 3) ok = false;
		for (i=0; i<4; i++) {
			if (s[i] == s[i+1]+1 && s[i+1] == s[i+2]+1) ok = false;
			if (s[i] == s[i+1]-1 && s[i+1] == s[i+2]-1) ok = false;
		}
		if (ok) cout<<"ACCEPTABLE"<<endl;
		else cout<<"WEAK"<<endl;
	}
	
	return 0;
}
