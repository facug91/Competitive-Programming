/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4834
        Name: Black and white stones
        Date: 18/12/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int a, b, c;
ll ans;
string s;

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>a>>b) {
		b = a-b;
		cin>>s;
		c = 0; ans = 0;
		for (i=0; i<(int)s.length(); i++)
			if (s[i] == 'B')
				c++;
		for (i=c-1; i>=0 && s[i]!='W'; i--);
		for (j=c; j<(int)s.length() && s[j]!='B'; j++);
		while (i >= 0 && j < (int)s.length()) {
			if (a <= (j-i)*b) {
				break;
			} else {
				ans += ((j-i)*b);
				i--; j++;
				for (; i>=0 && s[i]!='W'; i--);
				for (; j<(int)s.length() && s[j]!='B'; j++);
			}
		}
		while (i >= 0 && j < (int)s.length()) {
			i--; j++;
			for (; i>=0 && s[i]!='W'; i--);
			for (; j<(int)s.length() && s[j]!='B'; j++);
			ans += a;
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}
