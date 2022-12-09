/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=5&page=show_problem&problem=289
	Name: Pesky Palindromes
	Number: 353
	Date: 22/06/2014
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

int len;
string s;
set<string> pal;

bool is_palindrome_even (int pos, int size) {
	for (int i=pos, j=pos+1, cont=2; cont<=size; i--, j++, cont+=2)
		if (s[i] != s[j])
			return false;
	return true;
}

bool is_palindrome_odd (int pos, int size) {
	for (int i=pos-1, j=pos+1, cont=3; cont<=size; i--, j++, cont+=2)
		if (s[i] != s[j])
			return false;
	return true;
}

int main() {
	
	int i, j;
	
	while (cin>>s) {
		len = s.length();
		
		for (i=0; i<len; i++)
			pal.insert(s.substr(i, 1));
		
		for (i=1; i<len; i++)
			for (j=(i/2); j+(i/2)+(i%2)<len; j++) {
				if ((i % 2) == 1) {
					if (is_palindrome_even(j, i+1))
						pal.insert(s.substr(j-(i/2), i+1));
				} else {
					if (is_palindrome_odd(j, i+1))
						pal.insert(s.substr(j-(i/2), i+1));
				}
			}
		
		cout<<"The string '"<<s<<"' contains "<<pal.size()<<" palindromes."<<endl;
		pal.clear();
		
	}
	
	return 0;
}
