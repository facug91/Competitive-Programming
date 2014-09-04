/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=651&page=show_problem&problem=438
        Name: Strategic Defense Initiative
        Number: 497
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

vector<int> seq, pre, lis;
char n[10];
stack<int> print;

ii LIS () {
	int i, j, mx = -1, idx;
	for (i=0; i<(int)seq.size(); i++) {
		lis.push_back(1);
		pre.push_back(i);
		for (j=0; j<i; j++) {
			if (seq[j] < seq[i]) {
				if (lis[j]+1 > lis[i]) {
					lis[i] = lis[j]+1;
					pre[i] = j;
				}
			}
		}
		if (lis[i] > mx) {
			mx = lis[i];
			idx = i;
		}
	}
	return ii(mx, idx);
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	scanf("%d", &TC);
	getchar();
	gets(n);
	while (TC--) {
		seq.clear();
		while (gets(n) && n[0] != 0)
			seq.push_back(atoi(n));
		ii last = LIS();
		printf("Max hits: %d\n", last.first);
		print.push(last.second);
		int act = last.second;
		while (pre[act] != act) {
			act = pre[act];
			print.push(act);
		}
		while (!print.empty()) {
			printf("%d\n", seq[print.top()]);
			print.pop();
		}
		if (TC) printf("\n");
	}
	
	return 0;
}
