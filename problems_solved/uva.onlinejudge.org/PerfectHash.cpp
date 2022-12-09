/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=124
	Name: Perfect Hash
	Number: 188
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

long long w[15], n, c;
char s[100], * p;
bool first = true;

int main() {
	
	int i, j, k;
	
	while (gets(s)) {
		
		printf("%s\n", s);
		
		n = 0; c = MAX_LONG;
		p = strtok(s, " ");
		while (p != NULL) {
			w[n] = 0;
			for (int i=0; p[i]; i++) {
				w[n] <<= 5;
				w[n] += (p[i]+1-'a');
			}
			c = min(c, w[n]);
			n++;
			p = strtok(NULL, " ");
		}
		
		bool solved = false;
		while (!solved) {
			solved = true;
			for (i=0; i<n; i++) {
				for (j=i+1; j<n; j++) {
					if (i != j) {
						if ((((long long) floor(c/w[i]))%n) == (((long long) floor(c/w[j]))%n)) {
							c = min((((long long) floor(c/w[i]))+1)*w[i], (((long long) floor(c/w[j]))+1)*w[j]);
							solved = false;
						}
					}
				}
			}
		}
		
		printf("%lld\n\n", c);
	}
	
	return 0;
} 
