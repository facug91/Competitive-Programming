/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2526
        Name: More Triangles
        Date: 27/12/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000ll
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, x, len, dis, ans, a, b, c;
vector<int> points;

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>n) {
		points.clear();
		points.push_back(0);
		for (i=0; i<n; i++) {
			cin>>x;
			points.push_back(points.back()+x);
		}
		len = points.back();
		points.pop_back();
		ans = 0;
		if (len % 3 == 0) {
			dis = len / 3;
			for (i=0; i<n; i++) {
				a = points[i];
				b = a + dis;
				c = b + dis;
				if (c >= len) break;
				if (binary_search(points.begin(), points.end(), b) && binary_search(points.begin(), points.end(), c)) ans++;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
