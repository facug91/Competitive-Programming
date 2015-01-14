/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2995
        Name: What does the fox say?
        Date: 27/12/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

string s;
set<string> st;

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	getline(cin, s);
	while (TC--) {
		getline(cin, s);
		istringstream ss(s);
		while (cin>>s, s != "what") {
			cin>>s;
			cin>>s;
			st.insert(s);
		}
		getline(cin, s);
		bool first = true;
		while (ss>>s) {
			if (st.find(s) == st.end()) {
				if (first) {
					first = false;
					cout<<s;
				} else {
					cout<<" "<<s;
				}
			}
		}
		cout<<endl;
	}
	
	return 0;
}
