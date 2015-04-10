/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2231
        Name: Challenge
        Date: 02/04/2015
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

int n, a, b;
string s1, s2;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin>>n;
	a = b = 0;
	while (n--) {
		cin>>s1>>s2;
		if (s1[0] == 'r' && s2[0] == 's') a++;
		else if (s1[0] == 'r' && s2[0] == 'p') b++;
		else if (s1[0] == 's' && s2[0] == 'p') a++;
		else if (s1[0] == 's' && s2[0] == 'r') b++;
		else if (s1[0] == 'p' && s2[0] == 'r') a++;
		else if (s1[0] == 'p' && s2[0] == 's') b++;
	}
	if (a == b) cout<<"tied\n";
	else if (a > b) cout<<"A win\n";
	else cout<<"B win\n";
	
	return 0;
}
