/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4801
        Name: Superstitious Socks
        Date: 15/01/2015
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
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, k, socks[100005];

int smaller_or_equal_than (int d) {
	if (d < 0) return 0;
	int p1, p2; ll c = 0;
	p1 = 0; p2 = 1;
	while (p1 < n-1) {
		while ((p2 < n-1) && ((socks[p2]-socks[p1]) <= d)) p2++;
		while ((p2 > p1) && (socks[p2]-socks[p1]) > d) p2--;
		c += (ll)(p2-p1);
		p1++;
		if (p1 >= p2) p2 = p1 + 1;
	}
	return (c > MAX_INT) ? MAX_INT : (int)c;
}

int binary_search_difference (int k) {
	int lo = 0, hi = 1000000001, mid, ans;
	while (lo < hi) {
		mid = (hi + lo) / 2;
		if (smaller_or_equal_than(mid) < k) lo = mid+1;
		else hi = mid;
	}
	return (hi + lo) / 2;
}

ii kth_with_difference (int k, int d) {
	int p1, p2, c;
	p1 = c = 0; p2 = 1;
	while (true) {
		if (socks[p2]-socks[p1] == d) p2++, c++;
		else if (socks[p2]-socks[p1] < d) p2++;
		else p1++;
		if (c == k) return ii(socks[p1], socks[--p2]);
		if (p2 == n) {
			p2 = n - 1;
			p1++;
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>n>>k, n || k) {
		for (i=0; i<n; i++)
			cin>>socks[i];
		sort(socks, socks+n);
		int d = binary_search_difference(k);
		ii ans = kth_with_difference(k-smaller_or_equal_than(d-1), d);
		cout<<ans.first<<" "<<ans.second<<endl;
	}
	
	return 0;
}
