/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3086
	Name: Through the Desert
	Number: 11935
	
	Solved with 1 linear scan
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

int value[55], dist[55], cant, leaks;
char action[55];
double ans;

void simulate () {
	
	double f, c = (((double) value[cant-1]) / 100.0) + ((double) leaks);
	int d = dist[cant-1], i = cant-1;
	ans = 0.0;
	
	do {
		
		f = 0.0;
		
		do {
			
			i--;
			
			f += (((double)(d-dist[i]))*c);
			
			d = dist[i];
			
			switch (action[i]) {
				case 'c':
					c = (((double) value[i]) / 100.0) + ((double) leaks);
					break;
				case 'l':
					leaks--;
					c -= 1.0;
					break;
				case 'm':
					leaks = value[i];
					c += ((double) leaks);
					break;
			}
			
		} while ((i > 0) && (action[i] != 's'));
		
		ans = max(ans, f);
		
	} while (i > 0);
	
}

int main() {
	
	int d, c, consumption;
	char s[20];
	
	scanf("%d", &d);
	scanf("%s", s);
	scanf("%s", s);
	scanf("%d", &c);
	
	while (c) {
		
		cant = 1;
		leaks = 0;
		value[cant] = c;
		consumption = c;
		
		while (scanf("%d", &d), d) {
			
			scanf("%s", s);
			if (strcmp(s, "Fuel") == 0) {
				scanf("%s", s);
				scanf("%d", &c);
				value[cant] = consumption;
				consumption = c;
				dist[cant] = d;
				action[cant] = 'c';
			} else if (strcmp(s, "Leak") == 0) {
				leaks++;
				dist[cant] = d;
				action[cant] = 'l';
			} if (strcmp(s, "Gas") == 0) {
				scanf("%s", s); 
				dist[cant] = d;
				action[cant] = 's';
			} if (strcmp(s, "Mechanic") == 0) {
				value[cant] = leaks;
				leaks = 0;
				dist[cant] = d; 
				action[cant] = 'm';
			} if (strcmp(s, "Goal") == 0) {
				value[cant] = consumption;
				dist[cant] = d; 
				action[cant] = 'g';
			}
			
			cant++;
			
		}
		
		simulate();
		
		printf("%.3lf\n", ans);
		
		scanf("%s", s);
		scanf("%s", s);
		scanf("%d", &c);
		
	}
	
	return 0;
} 
