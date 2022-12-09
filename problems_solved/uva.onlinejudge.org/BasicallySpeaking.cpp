/*
	By: facug91
	From: http://uva.onlinejudge.org/
	Name: Basically Speaking
	Number: 389
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

char s[10], ans[10];
int b_from, b_to, s_int;
char to_char[20];
int to_int['Z'];

void init () {
	for (int i=0; i<10; i++) {
		to_char[i] = '0'+i;
		to_int['0'+i] = i;
	}
	for (int i=0; i<6; i++) {
		to_char[i+10] = 'A'+i;
		to_int['A'+i] = i+10;
	}
}

int to_base10 () {
	int len = strlen(s), act = 1, aux = 0;
	for (int i=len-1; i>=0; i--) {
		aux += (to_int[s[i]] * act);
		act *= b_from;
	}
	return aux;
}

bool make_answer () {
	int i = 7;
	ans[i--] = 0;
	if (s_int == 0) ans[i--] = '0';
	while (s_int) {
		//cout<<"i "<<i<<" s_int "<<s_int<<endl;
		if (i < 0) return false;
		ans[i--] = to_char[s_int % b_to];
		s_int /= b_to;
	}
	while (i >= 0) ans[i--] = ' ';
	return true;
}

int main() {
	
	init();
	
	while (scanf("%s", s) != EOF) {
		
		scanf("%d %d", &b_from, &b_to);
		
		s_int = to_base10();
		//cout<<s_int<<endl;
		if (!make_answer()) printf("  ERROR\n");
		else printf("%s\n", ans);

	}
	
	return 0;
} 
