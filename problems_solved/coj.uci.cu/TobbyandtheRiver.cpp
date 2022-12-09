/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2968
	Name: Tobby and the River
	Number: 2968
	Date: 11/07/2014
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

using namespace std;

int dog[6], boat1, boat2;



bool search (int i, int boat1, int boat2) {
	if (i == 6) {
		if (boat1 == boat2) return true;
		return false;
	}
	if (search(i+1, boat1+dog[i], boat2)) return true;
	return search(i+1, boat1, boat2+dog[i]);
}

int main () {
	int t, i, j, sumi, sumj, ii, jj;
	
	scanf("%d", &t);
	
	while (t--) {
		for (i=0; i<6; i++)
			scanf("%d", dog+i);
		if (search(0, 0, 0)) printf("Tobby puede cruzar\n");
		else printf("Tobby no puede cruzar\n");
	}
	
	return 0;
}
