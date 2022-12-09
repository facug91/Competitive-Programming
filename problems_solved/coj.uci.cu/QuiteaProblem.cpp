/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2127
        Name: Quite a Problem
        Date: 05/04/2015
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

string s, p;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int i, j;
	
	p = "problem";
	while (getline(cin, s)) {
		bool ok = false;
		for (i=0; i<s.length() && !ok; i++) {
			for (j=0; j<p.length() && i+j<s.length(); j++) if (tolower(s[i+j]) != p[j]) break;
			if (j == p.length()) ok = true;
		}
		if (ok) cout<<"yes\n";
		else cout<<"no\n";
	}
	
	return 0;
}
