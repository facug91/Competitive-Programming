/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2061
	Name: Power Sum
	Number: 2061
	Date: 01/07/2014
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

long long fast_exponentiation (long long x, long long n) {
	if (n == 1) {return x%MOD;}
	long long aux = fast_exponentiation(x, n/2);
	if ((n % 2) == 0) {return (aux*aux)%MOD;}
	else {return (((aux*aux)%MOD)*x)%MOD;}
}

long long s (long long x, long long n) {
	if (n == 0) return 1;
	if (n == 1) {return (x+1)%MOD;}
	if (n == 2) {return ((((x*x)%MOD)+(x+1))%MOD);}
	if ((n % 2) != 0) {return (((x+1)*s((x*x)%MOD, n/2))%MOD);}
	else {return ((((((x+1)% MOD)*s((x*x)%MOD, (n-1)/2))%MOD)+fast_exponentiation(x, n))%MOD);}
}

int main() {
	
	long long x, n;
	int t;
	
	scanf("%d", &t);
	
	while (t--) {
		
		scanf("%lld %lld", &x, &n);
		
		printf("%lld\n", s(x, n));
		
	}
	
	return 0;
}
