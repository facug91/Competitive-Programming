/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=3017
        Name: Reverse Polish Notation
        Date: 16/02/2015
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
#define find asjkldhakjsdbsakjdb
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

string s;
stack<ll> stk;
ll a, b;

int main () {
	ios_base::sync_with_stdio(0);
	
	while (getline(cin, s)) {
		istringstream ss(s);
		while (ss>>s) {
			if (s[0] == '+') {
				b = stk.top(); stk.pop();
				a = stk.top(); stk.pop();
				stk.push(a+b);
			} else if (s[0] == '*') {
				b = stk.top(); stk.pop();
				a = stk.top(); stk.pop();
				stk.push(a*b);
			} else if (s[0] == '-') {
				b = stk.top(); stk.pop();
				a = stk.top(); stk.pop();
				stk.push(a-b);
			} else {
				a = 0ll;
				for (int i=0; i<s.length(); i++)
					a = (a * 10ll) + (ll)(s[i]-'0');
				stk.push(a);
			}
		}
		cout<<stk.top()<<endl;
		stk.pop();
	}
	
	return 0;
}
