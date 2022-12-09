/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=455
        Name: Rails
        Date: 13/02/2015
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
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, order[1005];

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>n, n) {
		while (cin>>order[0], order[0]) {
			stack<int> stk;
			for (i=1; i<n; i++) cin>>order[i];
			bool ok = true;
			for (i=0, j=1; i<n; i++) {
				if (stk.size() && stk.top() == order[i]) stk.pop();
				else {
					while (j <= n && order[i] != j) stk.push(j++);
					if (j <= n && j == order[i]) j++;
					else {
						ok = false;
						break;
					}
				}
			}
			if (ok) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
		cout<<endl;
	}
	
	return 0;
}
