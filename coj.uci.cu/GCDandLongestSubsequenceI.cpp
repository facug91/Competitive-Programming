/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2896
	Name: GCD and Longest Subsequence I
	Number: 2896
	Date: 01/07/2014
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
#define _log2(x) log(x) * 1.44269504088896340736
//const long double PI = 2*acos(0);

#define INF 1000000000
//
using namespace std;

int n, seq[1001], q, k, DP[1001];

int main() {
	
	int i, j, mx;
	
	fill(DP, DP+1000, 0);
	
	scanf("%d", &n);
	
	mx = -1;
	for (i=0; i<n; i++) {
		scanf("%d", seq+i);
		mx = max(mx, seq[i]);
	}
	
	int act, cont;
	for (i=mx; i>0; i--) {
		act = cont = 0;
		for (j=0; j<n; j++) {
			if ((seq[j] % i) == 0) {
				if (act == 0) act = seq[j];
				else act = __gcd(act, seq[j]);
				cont++;
			}
		}
		if (act) DP[act] = cont;
	}
	
	for (i=mx; i>0; i--)
		if ((DP[i-1] == 0)) DP[i-1] = DP[i];
	
	scanf("%d", &q);
	for (i=0; i<q; i++) {
		scanf("%d", &k);
		printf("%d\n", DP[k]);
	}
	
	return 0;
}
