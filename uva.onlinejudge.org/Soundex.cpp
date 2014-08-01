/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1201
	Name: Soundex
	Number: 10260
	Date: 07/07/2014
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

char s[25], ans[25], hash['Z'+1], last;

void init () {
	memset(hash, 0, sizeof hash);
	hash['B'] = '1';
	hash['F'] = '1';
	hash['P'] = '1';
	hash['V'] = '1';
	hash['C'] = '2';
	hash['G'] = '2';
	hash['J'] = '2';
	hash['K'] = '2';
	hash['Q'] = '2';
	hash['S'] = '2';
	hash['X'] = '2';
	hash['Z'] = '2';
	hash['D'] = '3';
	hash['T'] = '3';
	hash['L'] = '4';
	hash['M'] = '5';
	hash['N'] = '5';
	hash['R'] = '6';
}

int main () {
	
	int i, j;
	
	init();
	
	while (scanf("%s", s) != EOF) {
		
		
		j = 0; last = '0';
		for (i=0; s[i]; i++) {
			if (hash[s[i]] != last) {
				if (hash[s[i]])
					ans[j++] = hash[s[i]];
				last = hash[s[i]];
			}
		}
		
		ans[j] = 0;
		printf("%s\n", ans);
		
	}
	
	return 0;
}
