/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2789
        Name: Sum Order
        Date: 01/11/2014
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
int num[4];
bool first;

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>s;
	num[0] = num[1] = num[2] = 0;
	for (i=0; i<(int)s.length(); i+=2)
		num[s[i]-'0']++;
	first = true;
	for (i=1; i<=3; i++) {
		for (j=0; j<num[i]; j++) {
			if (first) {
				first = false;
				cout<<i;
			} else {
				cout<<"+"<<i;
			}
		}
	}
	cout<<endl;
	
	return 0;
}
