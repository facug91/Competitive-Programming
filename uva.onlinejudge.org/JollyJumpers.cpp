/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=979
        Name: Jolly Jumpers
        Number: 10038
        Date: 24/08/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007
//#define MAXN N

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, seq[3005];
set<int> s;

int main () {
	ios_base::sync_with_stdio(0);
	int i, j;
	
	while (cin>>n) {
		for (i=0; i<n; i++)
			cin>>seq[i];
		if (n == 1) cout<<"Jolly"<<endl;
		else {
			s.clear();
			for (i=1; i<n; i++)
				s.insert(abs(seq[i-1]-seq[i]));
			if ((*(s.begin()) == 1) && (*(--s.end()) == n-1) && ((int)s.size() == n-1)) cout<<"Jolly"<<endl;
			else cout<<"Not jolly"<<endl;
		}
	}
	
	return 0;
}

