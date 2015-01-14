/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1239
        Name: Power Strings
        Date: 03/11/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

string s;
int b[1000005], m;

void kmpPreprocess () {
	int i = 0, j = -1; b[0] = -1;
	while (i < (int)s.length()) {
		while (j >= 0 && s[i] != s[j]) j = b[j];
		i++; j++;
		b[i] = j;
	}
}

bool check () {
	for (int i=0; i<(int)s.length()-m; i++) {
		if (s[i] != s[i+m]) return false;
	}
	return true;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>s, s[0] != '.') {
		kmpPreprocess();
		m = (int)s.length() - b[(int)s.length()-1] - 1;
		if ((int)s.length() % m != 0) {
			cout<<1<<endl;
		} else {
			if (check()) cout<<(int)s.length()/m<<endl;
			else cout<<1<<endl;
		}
	}
	
	return 0;
}
