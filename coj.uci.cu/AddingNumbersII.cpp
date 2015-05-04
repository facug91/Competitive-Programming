/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2374
        Name: Adding Numbers II
        Date: 13/04/2015
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

int a, b, c, d;
string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(4); cerr<<fixed<<setprecision(10); //cout.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j;
	
	cin>>s;
	a = b = 0;
	for (i=0; i<s.length(); i++) {
		a = a*10 + (s[i]-'0'); if (s[i] == '6') a--;
		b = b*10 + (s[i]-'0'); if (s[i] == '5') b++;
	}
	cin>>s;
	c = d = 0;
	for (i=0; i<s.length(); i++) {
		c = c*10 + (s[i]-'0'); if (s[i] == '6') c--;
		d = d*10 + (s[i]-'0'); if (s[i] == '5') d++;
	}
	cout<<a+c<<" "<<b+d<<"\n";
	
	return 0;
}
