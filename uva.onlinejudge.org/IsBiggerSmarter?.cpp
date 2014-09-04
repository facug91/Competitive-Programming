/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1072
        Name: Is Bigger Smarter?
        Number: 10131
        Date: 22/08/2014
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
typedef pair<ii, int> iii;

int n, LIS[1005], pre[1005];
iii ele[1005];

struct cmp {
	bool operator() (const iii &a, const iii &b) {
		if (a.first.first == b.first.first)
			return a.first.second < b.first.second;
		else
			return a.first.first > b.first.first;
	}
}myCmp;

ii lis () {
	int i, j, mx = -1, idx;
	for (i=1; i<=n; i++) {
		LIS[i] = 1;
		pre[i] = i;
		for (j=1; j<i; j++) {
			if ((ele[j].first.first > ele[i].first.first) && (ele[j].first.second < ele[i].first.second)) {
				if (LIS[j]+1 > LIS[i]) {
					LIS[i] = LIS[j]+1;
					pre[i] = j;
				}
			}
		}
		if (LIS[i] > mx) {
			mx = LIS[i];
			idx = i;
		}
	}
	return ii(mx, idx);
}

void print (ii l) {
	int i = l.second;
	cout<<l.first<<endl;
	cout<<ele[i].second<<endl;
	while (pre[i] != i) {
		i = pre[i];
		cout<<ele[i].second<<endl;
	}
}

int main () {
	//ios_base::sync_with_stdio(0);
	int i, j;
	
	n = 1;
	while (cin>>ele[n].first.first>>ele[n].first.second) {
		ele[n].second = n;
		n++;
	}
	n--;
	
	sort(ele+1, ele+n+1, myCmp);
	ii last = lis();
	print(last);
	
	return 0;
}
