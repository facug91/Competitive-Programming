/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2775
        Name: LATIN
        Date: 01/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 10
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n;
string s;

int main () {
	ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j, l;
	
	cin>>n;
	while (n--) {
		cin>>s;
		if (s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') cout<<s<<"cow"<<endl;
		else cout<<s.substr(1)<<s[0]<<"ow"<<endl;
	}
	
	return 0;
}
