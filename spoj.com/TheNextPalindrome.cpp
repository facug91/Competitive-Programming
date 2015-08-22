/*
	By: facug91
	From: http://www.spoj.com/problems/PALIN/
	Name: The Next Palindrome
	Code: PALIN
	Date: 24/06/2014
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

char s[1000005];

int main() {
	
	int t, i, j, k, len;
	bool is_pal;
	
	scanf("%d", &t);
	
	while (t--) {
		
		scanf("%s", s);
		
		len = strlen(s);
		is_pal = true;
		
		for (i=(len>>1)-1, j=(len>>1)+(len&1); j<len; i--, j++) {
			if (s[i] > s[j]) {
				is_pal = false;
				for (; j<len; i--, j++)
					s[j] = s[i];
				break;
			}
			if (s[i] < s[j]) {
				is_pal = false;
				if ((len & 1) && (s[(len>>1)] != '9')) s[(len>>1)]++;
				else {
					if (len & 1) s[(len>>1)] = '0';
					for (i=(len>>1)-1; i>=0; i--) {
						if (s[i] == '9') s[i] = '0';
						else {
							s[i]++;
							break;
						}
					}
				}
				for (i=(len>>1)-1, j=(len>>1)+(len&1); j<len; i--, j++)
					s[j] = s[i];
				break;
			}
		}
		
		if (is_pal) {
			if ((len & 1) && (s[(len>>1)] != '9')) s[(len>>1)]++;
			else {
				if (len & 1) s[(len>>1)] = '0';
				for (i=(len>>1)-1; i>=0; i--) {
					if (s[i] == '9') s[i] = '0';
					else {
						s[i]++;
						break;
					}
				}
				if (i == -1) {
					printf("1");
					s[len-1] = '1';
					s[len] = 0;
					len--;
				}
			}
			for (i=(len>>1)-1, j=(len>>1)+(len&1); j<len; i--, j++)
				s[j] = s[i];
		}
		
		printf("%s\n", s);
		
	}
	
	return 0;
}
