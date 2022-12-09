/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=3093
        Name: Remainder of Word
        Date: 01/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 10
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int ans;
string s;

int main () {
	ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j, l;
	
	cin>>s;
	ans = 1;
	for (i=0; i<s.length(); i++) ans = (ans * (s[i]-'A'+1)) % 26;
	printf("%02d\n", ans);
	
	return 0;
}
