/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2763
	Name: OBILAZAK
	Number: 2763
	Date: 30/06/2014
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

int k, in_order[1<<11], f, s;
set<pair<int, int> > level[2];
set<pair<int, int> >::iterator itrs;

int main () {
	
	int i, j;
	
	scanf("%d", &k);
	
	for (i=0; i<(1<<k)-1; i++)
		scanf("%d", in_order+i);
	
	f = 0; s = 1;
	level[0].insert(make_pair(0, (1<<k)-2));
	int aux;
	for (i=0; i<k; i++) {
		itrs = level[f].begin();
		aux = (*itrs).first + (((*itrs).second - (*itrs).first)/2);
		printf("%d", in_order[aux]);
		level[s].insert(make_pair((*itrs).first, aux));
		level[s].insert(make_pair(aux+1, (*itrs).second));
		level[f].erase(itrs);
		while (!level[f].empty()) {
			itrs = level[f].begin();
			aux = (*itrs).first + (((*itrs).second - (*itrs).first)/2);
			printf(" %d", in_order[aux]);
			level[s].insert(make_pair((*itrs).first, aux));
			level[s].insert(make_pair(aux+1, (*itrs).second));
			level[f].erase(itrs);
		}
		printf("\n");
		f = (f+1)%2;
		s = (s+1)%2;
	}
	
	return 0;
}
