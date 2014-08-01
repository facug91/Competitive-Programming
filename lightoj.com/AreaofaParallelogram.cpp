/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1305
	Name: Area of a Parallelogram
	Number: 1305
	Date: 25/07/2014
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
//const double PI = 2*acos(0.0);

#define INF 1000000000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;

int x[4], y[4];

int area () {
	int ans = 0;
	for (int i=0; i<3; i++)
		ans += (x[i]*y[i+1]-x[i+1]*y[i]);
	ans += (x[3]*y[0]-x[0]*y[3]);
	return abs(ans)/2;
}

int main () {
    int t, i, j;
    
    scanf("%d", &t);
    for (int it=1; it<=t; it++) {
		for (i=0; i<3; i++)
			scanf("%d %d", x+i, y+i);
		x[3] = x[2]-(x[1]-x[0]);
		y[3] = y[0]+(y[2]-y[1]);
		printf("Case %d: %d %d %d\n", it, x[3], y[3], area());
	}
    
    return 0;
}
