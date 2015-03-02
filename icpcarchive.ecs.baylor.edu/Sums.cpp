/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4941
        Name: Sums
        Date: 20/02/2015
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

ll n, sqr, ans, m;

int main () {
	ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		cin>>n;
		sqr = sqrt(n * 2ll) + 10ll;
		for (ans=2ll; ans <= sqr; ans++) {
			m = (n / ans) - (ans / 2ll);
			if (ans % 2ll == 0ll) m++;
			if (m <= 0ll) {
				ans = sqr + 1ll;
				break;
			} else if ((((m+ans-1ll) * (m+ans) / 2ll) - (m * (m - 1ll) / 2ll)) == n) break;
		}
		if (ans > sqr) cout<<"IMPOSSIBLE"<<endl;
		else {
			cout<<n<<" =";
			bool first = true;
			for (i=0; i<ans; i++) {
				cout<<" ";
				if (first) first = false;
				else cout<<"+ ";
				cout<<i+m;
			}
			cout<<endl;
		}
	}
	
	return 0;
}
