/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=959
	Name: Reverse and Add
	Number: 10018
	Date: 18/06/2014
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
//
using namespace std;

char num[15], aux[15];
int ans, size;

void reverse (char * n) {
	for (int i=0, j=size-1; i<j; i++, j--)
		swap(num[i], num[j]);
}

void addition () {
	int i, carry = 0;
	
	for (i=size-1; i>=0; i--)
		aux[size-i-1] = num[i];
	
	i = 0;
	while (i < size) {
		carry += num[i]+aux[i];
		num[i] = carry % 10;
		carry /= 10;
		i++;
	}
	if (carry)
		num[size++] = 1;
	
}

bool is_palindrome () {
	for (int i=0, j=size-1; i<j; i++, j--)
		if (num[i] != num[j])
			return false;
	return true;
}

int main() {
	
	int t, i, j;
	
	scanf("%d", &t);
	getchar();
	
	while (t--) {
		
		gets(num);
		
		size = strlen(num);
		reverse(num);
		
		for (i=0; i<size; i++)
			num[i] -= '0';
		
		ans = 0;
		while (!is_palindrome()) {
			addition();
			ans++;
		}
		
		reverse(num);
		
		for (i=0; i<size; i++)
			num[i] += '0';
		num[size] = 0;
		
		printf("%d %s\n", ans, num);
	}
	
	return 0;
}
