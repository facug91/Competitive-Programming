/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1967
	Name: Cow IDs
	Number: 1967
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

long long n;
int k, ones[11];

void divbygcd(long a, long b) {
	long g = __gcd(a, b);
	a /= g;
	b /= g;
}
long long comb(long long n, long long k) {
	long long numerator = 1, denominator = 1, toMul, toDiv, i;
	if (k > n / 2) k = n - k;
	for (int i = k; i > 0; i--) {
		toMul = n - k + i;
		toDiv = i;
		divbygcd(toMul, toDiv);
		divbygcd(numerator, toDiv);
		divbygcd(toMul, denominator);
		numerator *= toMul;
		denominator *= toDiv;
	}
	return numerator / denominator;
}

int solve (int right) {
	int pos = right+1;
	long long ant = 1, val = 1;
	while (val < n) {
		pos++;
		ant = val;
		val += comb(pos-1, right);
	}
	n -= ant;
	return pos;
}

int main() {
	
	int i, j, aux;
	
	scanf("%lld %d", &n, &k);
	
	if (k == 1) {
		printf("1");
		for (i=1; i<n; i++)
			printf("0");
		printf("\n");
	} else {
		for (i=k; i>1; i--)
			ones[i] = solve(i-1);
		ones[1] = n;
		ones[0] = 0;
		
		for (i=k; i>0; i--){
			printf("1");
			for (j=ones[i]-1; j>ones[i-1]; j--)
				printf("0");
		}
		printf("\n");
	}
	
	return 0;
} 
