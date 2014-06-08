/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=298
	Name: 18,000 Seconds Remaining
	Number: 362
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
//const long double PI = 2*acos(0);

#define INF 1000000000
//
using namespace std;

int n, res, seg, last[5];
double sum;

int main() {
	
	int t = 1, i, j;
	
	while (scanf("%d", &n), n) {
		
		res = n; seg = 0;
		printf("Output for data set %d, %d bytes:\n", t++, n);
		
		while (res) {
			
			for (i=0; (i<5) && (res); i++) {
				
				scanf("%d", &last[i]);
				res -= last[i];
				seg++;
				
			}
			
			if (seg % 5 == 0) {
				sum = 0.0;
				for (i=0; i<5; i++)
					if (last[i])
						sum += last[i];
				
				if (sum != 0.0) printf("   Time remaining: %d seconds\n", ((int) ceil(res*5.0/sum)));
				else printf("   Time remaining: stalled\n");
			}
			
		}
		
		printf("Total time: %d seconds\n\n", seg);
		
	}
	
	return 0;
} 
