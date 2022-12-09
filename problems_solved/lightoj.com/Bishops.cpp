/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1202
	Name: Bishops
	Number: 1202
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

int r1, c1, r2, c2;

bool same_pos () {return ((r1 == r2) && (c1 == c2));}
bool same_diagonal () {return (abs(r1-r2) == abs(c1-c2));}
bool same_color () {return (((r1%2)==(c1%2)) == ((r2%2)==(c2%2)));}

int main () {
    int t, i, j;
    
    scanf("%d", &t);
    for (int it=1; it<=t; it++) {
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		if (same_pos()) printf("Case %d: 0\n", it);
		else if (same_diagonal()) printf("Case %d: 1\n", it);
		else if (same_color()) printf("Case %d: 2\n", it);
		else printf("Case %d: impossible\n", it);
	}
    
    return 0;
}
