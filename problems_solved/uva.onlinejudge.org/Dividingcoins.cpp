/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=503
	Name: Dividing coins
	Number: 562
	Date: 28/08/2014
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <iterator>
#include <utility>
#include <list>
#include <stack>
#include <iomanip>
#include <bitset>

#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;

int n, t, w, bag[105], DP[105][25005], ans;

int dp (int idx, int wi) {
	if (idx == n) return wi;
	if (DP[idx][wi] != -1) return DP[idx][wi];
	if (wi+bag[idx] > w) return DP[idx][wi] = max(wi, dp(idx+1, wi));
	return DP[idx][wi] = max(dp(idx+1, wi), dp(idx+1, wi+bag[idx]));
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		cin>>n;
		t = 0;
		for (i=0; i<n; i++) {
			cin>>bag[i];
			t += bag[i];
		}
		w = t / 2;
		memset(DP, -1, sizeof DP);
		ans = dp(0, 0);
		cout<<abs(ans-(t-ans))<<endl;
	}
	
	return 0;
}
