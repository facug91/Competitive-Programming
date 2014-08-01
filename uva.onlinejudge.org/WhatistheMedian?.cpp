/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1048
	Name: What is the Median?
	Number: 10107
	Date: 08/07/2014
	
	Time comparative table of different solution types
	multiset+iterator		Accepted	C++	0.019
	array  (nth_element)	Accepted	C++	0.096
	array  (nth_element)*	Accepted	C++	0.082
	array  (partial_sort)	Accepted	C++	1.096
	array  (sort)			Accepted	C++	1.215
	vector (nth_element)	Accepted	C++	0.139
	vector (nth_element)*	Accepted	C++	0.129
	vector (partial_sort)	Accepted	C++	1.048
	vector (sort)			Accepted	C++	1.129
	
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

int n, a, b;
multiset<int> ms;
multiset<int>::iterator itrms;

int main () {
	
	itrms = ms.begin();
	
	while (true) {
		
		if (scanf("%d", &n) != EOF) {
			ms.insert(n);
			if (*itrms <= n) itrms++;
			printf("%d\n", *itrms);
		} else return 0;
		
		if (scanf("%d", &n) != EOF) {
			ms.insert(n);
			if (*itrms > n) itrms--;
			a = *itrms;
			b = *(++itrms);
			itrms--;
			printf("%d\n", (a+b)/2);
		} else return 0;
		
	}
	
	return 0;
}
