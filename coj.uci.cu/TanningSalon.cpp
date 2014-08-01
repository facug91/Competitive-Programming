/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2977
	Name: Tanning Salon
	Number: 2977
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

int frees, lost;
bool act[27];
char cus[60];

int main () {
	
	int i, j;
	
	while (scanf("%d", &frees), frees) {
		
		memset(act, 0, sizeof act);
		scanf("%s", cus);
		lost = 0;
		for (i=0; cus[i]; i++) {
			if (act[cus[i]-'A']) {
				frees++;
				act[cus[i]-'A'] = false;
			} else {
				act[cus[i]-'A'] = true;
				if (frees <= 0) lost++;
				frees--;
			}
		}
		if (lost) printf("%d customer(s) walked away.\n", lost);
		else  printf("All customers tanned successfully.\n");
		
	}
	
	
	
	
	return 0;
}
