/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1338
	Name: Hidden Secret!
	Number: 1338
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

int used['Z'+1];
char name1[105], name2[105];

int main () {
    int t, i, j;
    
    scanf("%d", &t);
    getchar();
    for (int it=1; it<=t; it++) {
		gets(name1);
		gets(name2);
		memset(used, 0, sizeof used);
		for (i=0; name1[i]; i++)
			used[toupper(name1[i])]++;
		for (i=0; name2[i]; i++)
			used[toupper(name2[i])]--;
		bool equal = true;
		for (i=0; i<='z'; i++)
			if ((i != ' ') && (used[i] < 0)) equal = false;
		if (equal) printf("Case %d: Yes\n", it);
		else printf("Case %d: No\n", it);
	}
	
    return 0;
}
