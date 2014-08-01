/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2906
	Name: Reordering the Cows
	Number: 2906
	Date: 13/07/2014
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
#define MAXN 1000010

using namespace std;

int n, a[110], b[110], cant_cycles, longest, aux;

int find_next (int x) {
	for (int i=1; i<=n; i++)
		if (b[i] == x) return i;
}

int cycle (int s) {
	int ant, sig, tmp, cont, i, j;
	
	cont = 1;
	ant = a[s]; sig = find_next(a[s]);
	while (sig != s) {
		cont++;
		tmp = a[sig];
		a[sig] = ant;
		ant = tmp;
		sig = find_next(ant);
	}
	return cont;
}

int main () {
	int i, j;
	
	scanf("%d", &n);
	
	for (i=1; i<=n; i++)
		scanf("%d", a+i);
	
	for (i=1; i<=n; i++)
		scanf("%d", b+i);
	
	cant_cycles = 0; longest = -1;
	for (i=1; i<=n; i++) {
		if (a[i] != b[i]) {
			aux = cycle(i);
			cant_cycles++;
			if (aux > longest)
				longest = aux;
		}
	}
	
	printf("%d %d\n", cant_cycles, (cant_cycles == 0) ? -1 : longest);
	
	return 0;
}
