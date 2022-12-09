/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=214
	Name: Chess
	Number: 278
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

int t, m, n, ans;
char piece;

int main() {
	
	scanf("%d", &t);
	getchar();
	
	while (t--) {
		
		scanf("%c %d %d", &piece, &m, &n);
		getchar();
		
		if (m < n) m ^= n ^= m ^= n;
		//m > n , siempre
		
		switch (piece) {
			case 'r': //Torre
				printf("%d\n", n);
				break;
			case 'K': //Rey
				printf("%d\n", (((m/2)+(m%2))*((n/2)+(n%2))));
				break;
			case 'Q': //Reina
				printf("%d\n", n);
				break;
			case 'k': //Caballo
				printf("%d\n", ((n*m/2)+((n*m)%2)));
				break;
		}
		
	}
	
	return 0;
} 
