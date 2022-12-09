/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2858
	Name: Parsing Binary Strings
	Number: 2858
	Date: 27/06/2014
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
#define MOD 1000000007

using namespace std;

char s[10005], ans[10005];
int base2[10005], len;

void init () {
	base2[0] = 1;
	for (int i=1; i<10005; i++)
		base2[i] = (base2[i-1] * 2) % MOD;
}

void reverse_ans (int len) {
	int i, j;
	char tmp;
	for (i=0, j=len-1; i<j; i++, j--) {
		tmp = ans[i];
		ans[i] = ans[j];
		ans[j] = tmp;
	}
}

int main () {
	
	init();
	
	int i, ii, j, k;
	long long aux;
	
	gets(s);
	
	len = strlen(s);
	
	for (i=len-1, ii=0; i>=0; i--) {
		if ((s[i] == '1') || (s[i] == '0')) {
			aux = 0;
			for (j=i, k=0; (j>=0) && ((s[j] == '1') || (s[j] == '0')); j--, k++) {
				aux = (aux + ((s[j]-'0') * base2[k])) % MOD;
			}
			i = j+1;
			if (aux == 0) ans[ii++] = '0';
			while (aux) {
				ans[ii++] = ((aux % 10)+'0');
				aux /= 10;
			}
		} else ans[ii++] = s[i];
	}
	
	reverse_ans(ii);
	
	printf("%s\n", ans);
	
	return 0;
}
