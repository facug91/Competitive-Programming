/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1052
	Name: SuperPrime Rib
	Number: 1052
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

#define tint unsigned long long int
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9;

using namespace std;

int n;

bool esPrimo (int num) {
	if (num % 2 == 0) return false;
	for (int i=3; i<sqrt(num)+1; i+=2) 
		if (num % i == 0) return false;
	return true;
}

void dfs (int nivel, int ant) {
	if (nivel == n) {
		cout<<ant<<endl;
	} else {
		for (int i=1; i<10; i+=2) {
			if (esPrimo(ant*10+i)) {
				dfs(nivel+1, ant*10+i);
			}
		}
	}
}

void dfs_main () {
	dfs(1, 2);
	dfs(1, 3);
	dfs(1, 5);
	dfs(1, 7);
}

int main() {
	
	while (cin>>n)
		dfs_main();
	
	return 0;
}
