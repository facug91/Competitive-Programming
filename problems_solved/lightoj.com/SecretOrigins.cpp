/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1042
	Name: Secret Origins
	Number: 1042
	Date: 02/08/2014
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
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;

int n;

void search () {
	int i, j, k;
	for (i=0; !(n & (1<<i)); i++);
	for (j=i+1; (n & (1<<j)); j++);
	k = j - i - 1;
	n = (n & (~((1<<j)-1))) | (1<<j);
	for (i=0; i<k; i++) n |= (1<<i);
}

int main () {
	int t, i, j;
	
	scanf("%d", &t);
	for (int it=1; it<=t; it++) {
		scanf("%d", &n);
		search();
		printf("Case %d: %d\n", it, n);
	}
	
	return 0;
}
