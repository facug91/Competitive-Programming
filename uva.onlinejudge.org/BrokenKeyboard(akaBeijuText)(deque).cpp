/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3139
	Name: Broken Keyboard (a.k.a. Beiju Text)
	Number: 11988
	Date: 08/07/2014
	Using deque
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

char s[100005];
deque<char> dq;

int main () {
	
	int i, j, k;
	
	while (scanf("%s", s) != EOF) {
		
		i = 0;
		while (s[i]) {
			while ((s[i]) && (s[i] != '[')) {
				if (s[i] != ']') dq.push_back(s[i]);
				i++;
			}
			if ((s[i]) && (s[i] == '[')) {
				j = i+1;
				while ((s[j]) && (s[j] != '[') && (s[j] != ']')) j++;
				k = j;
				for (--j; j>i; j--) dq.push_front(s[j]);
				i = k;
			}
		}
		
		while (!dq.empty()) {
			printf("%c", dq.front());
			dq.pop_front();
		}
		printf("\n");
	}
	
	return 0;
}
