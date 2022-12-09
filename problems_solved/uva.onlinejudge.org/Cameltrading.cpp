/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1641
        Name: Camel trading
        Date: 07/04/2015
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

ll ant, act, n;
string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(10); cerr<<fixed<<setprecision(10);
	int tc, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>s;
		cout<<"The maximum and minimum are ";
		i = 0;
		n = (ll)(s[i]-'0');
		if (i+1 < s.length() && s[i+1] != '+' && s[i+1] != '*') {
			n = n * 10ll + (ll)(s[i+1]-'0');
			i++;
		}
		i++;
		ant = 1ll; act = n;
		for (; i<s.length(); i+=2) {
			if (s[i] == '+') {
				n = (ll)(s[i+1]-'0');
				if (i+2 < s.length() && s[i+2] != '+' && s[i+2] != '*') {
					n = n * 10ll + (ll)(s[i+2]-'0');
					i++;
				}
				act += n;
			} else {
				n = (ll)(s[i+1]-'0');
				if (i+2 < s.length() && s[i+2] != '+' && s[i+2] != '*') {
					n = n * 10ll + (ll)(s[i+2]-'0');
					i++;
				}
				ant *= act;
				act = n;
			}
		}
		cout<<ant*act<<" and ";
		i = 0;
		n = (ll)(s[i]-'0');
		if (i+1 < s.length() && s[i+1] != '+' && s[i+1] != '*') {
			n = n * 10ll + (ll)(s[i+1]-'0');
			i++;
		}
		i++;
		ant = 0ll; act = n;
		for (; i<s.length(); i+=2) {
			if (s[i] == '*') {
				n = (ll)(s[i+1]-'0');
				if (i+2 < s.length() && s[i+2] != '+' && s[i+2] != '*') {
					n = n * 10ll + (ll)(s[i+2]-'0');
					i++;
				}
				act *= n;
			} else {
				n = (ll)(s[i+1]-'0');
				if (i+2 < s.length() && s[i+2] != '+' && s[i+2] != '*') {
					n = n * 10ll + (ll)(s[i+2]-'0');
					i++;
				}
				ant += act;
				act = n;
			}
		}
		cout<<ant+act<<".\n";
	}
	
	return 0;
}
