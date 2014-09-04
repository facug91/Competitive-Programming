/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=422
        Name: What Goes Up
        Number: 481
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

int n;
vector<int> seq, pre, LIS;
vector<int>::iterator itr;
ii last;
stack<int> print;

struct cmp {
	bool operator()(int i, int j) {
		return seq[i] < seq[j]; }
} myCmp;

ii lis () {
	int i, j;
	pre[0] = 0;
	LIS.clear();
	LIS.push_back(0);
	for (i=1; i<(int)seq.size(); i++) {
		itr = lower_bound(LIS.begin(), LIS.end(), i, myCmp);
		if (itr == LIS.end()) {
			pre[i] = LIS.back();
			LIS.push_back(i);
		} else {
			if (itr == LIS.begin()) {
				pre[i] = i;
				*itr = i;
			} else {
				pre[i] = *(--itr);
				*(++itr) = i;
			}
		}
	}
	return ii(LIS.size(), LIS.back());
}

int main () {
	ios_base::sync_with_stdio(0);
	int i, j;
	
	while (scanf("%d", &n) != EOF) 
		seq.push_back(n);
	pre.resize(seq.size());
	last = lis();
	printf("%d\n-\n", last.first);
	print.push(seq[last.second]);
	int act = last.second;
	while (pre[act] != act) {
		act = pre[act];
		print.push(seq[act]);
	}
	while (!print.empty()) {
		printf("%d\n", print.top());
		print.pop();
	}
	
	return 0;
}
