/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1432
	Name: Cows and Cars
	Number: 10491
	Date: 28/06/2014
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

double ncows, ncars, nshow, ans;

int main () {
	
	while (scanf("%lf %lf %lf", &ncows, &ncars, &nshow) != EOF) {
		ans = (ncars/(ncows+ncars))*((ncars-1.0)/(ncows+ncars-nshow-1)) + (ncows/(ncows+ncars))*(ncars/(ncows+ncars-nshow-1));
		printf("%.5lf\n", ans);
	}
	
	return 0;
}
