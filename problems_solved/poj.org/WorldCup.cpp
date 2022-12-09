/*
        By: facug91
        From: http://poj.org/problem?id=3117
        Name: World Cup
        Number: 3117
        Date: 15/08/2014
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
//#define MOD 1000000007
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;
 
int t, n, maximum, total, p;
char name[20];
 
int main () {
	int i, j;
	
	while (scanf("%d", &t), t) {
		scanf("%d", &n);
		maximum = n*3;
		total = 0;
		while (t--) {
			scanf("%s %d", name, &p);
			total += p;
		}
		printf("%d\n", maximum-total);
	}
	
	return 0;
}
