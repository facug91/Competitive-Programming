/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=351
	Name: Station Balance
	Number: 410
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

int t, c, s, m, i, j;
vector<int> mass;
double am, cm[25], ans;

int main() {
	
	int t = 1;
	
	while (scanf("%d %d", &c, &s) != EOF) {
		
		if (t != 1) mass.clear();
		
		am = 0.0;
		for (i=0; i<s; i++) {
			scanf("%d", &m);
			mass.push_back(m);
			am += ((double) m);
		}
		am /= ((double) c);
		
		for (i=s; i<2*c; i++) 
			mass.push_back(0);
		
		sort(mass.begin(), mass.end());
		
		printf("Set #%d\n", t++);
		ans = 0.0;
		int aux0, aux1;
		for (i=0; i<c; i++) {
			aux0 = mass[2*c-(2*c-i)];
			aux1 = mass[2*c-i-1];
			cm[i] = (double) (aux0 + aux1);
			ans += fabs(cm[i]-am);
			printf(" %d:", i);
			if (aux0) printf(" %d", aux0);
			if (aux1) printf(" %d", aux1);
			printf("\n");
		}
		printf("IMBALANCE = %.5lf\n\n", ans);
		
	}
	
	return 0;
} 
