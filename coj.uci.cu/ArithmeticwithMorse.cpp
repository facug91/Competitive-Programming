/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2604
	Name: Arithmetic with Morse
	Number: 2604
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

int n, total, parcial, num, values[10], val['='+1];
char s[10], operators[5];

void to_int (int i) {
	values[i] = 0;
	for (int j=0; s[j]; j++)
		values[i] += val[s[j]];
}

int main () {
	int i, j;
	
	val['.'] = 1;
	val[':'] = 2;
	val['-'] = 5;
	val['='] = 10;
	
	scanf("%d", &n);
	
	n = n*2+1;
	
	for (i=0; i<n; i++) {
		scanf("%s", s);
		
		if (i&1) operators[i/2] = s[0];
		else to_int(i/2);
	}
	
	n = (n-1)/2;
	total = 0; i = 0;
	while (i < n) {
		parcial = values[i];
		while ((i < n) && (operators[i] != '+')) {
			parcial *= values[i+1];
			i++;
		}
		total += parcial;
		i++;
	}
	if (operators[n-1] == '+') total += values[n];
	
	printf("%d\n", total);
	
	
	return 0;
}
