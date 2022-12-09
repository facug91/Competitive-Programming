/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2904
	Name: Super Sum
	Number: 2904
	Date: 22/05/2014
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
#include <ctime>

#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
//const long double PI = 2*acos(0);

#define INF 1000000000
//
using namespace std;

int t, sum[1000], size, len, i, j, carry;
char n[1000];

int main() {
	
	memset(sum, 0, sizeof sum);
	size = 0;
	
	scanf("%d", &t);
	
	scanf("%s", n);
	size = strlen(n);
	for (i=size-1, j=0; i>=0; i--, j++)
		sum[j] = n[i]-'0';
	
	--t;
	while (t--) {
		
		scanf("%s", n);
		
		len = strlen(n); carry = 0;
		for (i=len-1, j=0; i>=0; i--, j++) {
			carry += sum[j]+(n[i]-'0');
			sum[j] = carry%10;
			carry /= 10;
		}
		
		while (carry) {
			carry += sum[j];
			sum[j] = carry%10;
			carry /= 10;
			j++;
		}
		
		size = max(size, j);
		
	}
	
	size += 10;
	for (i=size-1; i>=0 && !sum[i]; i--) size--;
	
	for (i=size-1; i>=0; i--)
		printf("%d", sum[i]);
	if (!size) printf("0");
	printf("\n");
	
	return 0;
} 
