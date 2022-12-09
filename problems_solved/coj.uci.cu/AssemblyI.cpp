/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2930
	Name: Assembly I
	Number: 2930
	Date: 13/07/2014
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
#define MAXN 1000010

using namespace std;

int n, S[20010], incresing, decresing;

int LIS () {
	set<int> st;
	set<int>::iterator itr;
	st.insert(S[0]);
	for (int i=1; i<n; i++) {
		itr = st.lower_bound(S[i]);
		if (itr == st.end()) st.insert(S[i]);
		else if (*itr != S[i]) {
			st.erase(itr);
			st.insert(S[i]);
		}
	}
	return st.size();
}

int LDS () {
	set<int> st;
	set<int>::iterator itr;
	st.insert(S[n-1]);
	for (int i=n-2; i>=0; i--) {
		itr = st.lower_bound(S[i]);
		if (itr == st.end()) st.insert(S[i]);
		else if (*itr != S[i]) {
			st.erase(itr);
			st.insert(S[i]);
		}
	}
	return st.size();
}


int main () {
	int i, j;
	
	while (scanf("%d", &n) != EOF) {
		
		for (i=0; i<n; i++)
			scanf("%d", S+i);
		
		incresing = LIS();
		decresing = LDS();
		
		if (incresing == decresing) printf("Caution. I will not intervene.\n");
		else printf("Don't worry. I must intervene.\n");
		
	}
	
	return 0;
}
