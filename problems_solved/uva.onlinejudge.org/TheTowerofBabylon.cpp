/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=378
        Name: The Tower of Babylon
        Number: 437
        Date: 20/08/2014
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

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;

int n, point[3], lis[105];
vector<pair<ii, int> > block;

int LIS () {
	int i, j, mx = -1, size = (int)block.size();
	for (i=0; i<size; i++) {
		lis[i] = block[i].second;
		for (j=0; j<i; j++) {
			if (block[j].first.first < block[i].first.first && block[j].first.second < block[i].first.second) {
				if (lis[j]+block[i].second > lis[i]) {
					lis[i] = lis[j]+block[i].second;
				}
			}
		}
		if (lis[i] > mx) mx = lis[i];
	}
	return mx;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC = 1, i, j;
	
	while (scanf("%d", &n), n) {
		block.clear();
		for (i=0; i<n; i++) {
			scanf("%d %d %d", &point[0], &point[1], &point[2]);
			sort(point, point+3);
			do {
				block.push_back(make_pair(make_pair(point[0], point[1]), point[2]));
			} while (next_permutation(point, point+3));
		}
		sort(block.begin(), block.end());
		printf("Case %d: maximum height = %d\n", TC++, LIS());
	}
	
	return 0;
}
