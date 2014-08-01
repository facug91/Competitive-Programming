/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2552
	Name: Elections
	Number: 2552
	Date: 11/07/2014
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

using namespace std;

int n, votes[15], total;

int main () {
	
	int i, j;
	
	scanf("%d", &n);
	
	total = 0;
	for (i=0; i<n; i++) {
		scanf("%d", votes+i);
		total += votes[i];
	}
	
	sort(votes, votes+n, greater<int>());
	
	if (votes[0]*100 >= 45*total) printf("1\n");
	else if ((votes[0]*100 >= 40*total) && (votes[0]*100-votes[1]*100>=10*total)) printf("1\n");
	else printf("2\n");
	
	return 0;
}
