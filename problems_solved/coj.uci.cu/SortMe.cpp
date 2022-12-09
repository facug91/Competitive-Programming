/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2974
	Name: Sort Me
	Number: 2974
	Date: 11/07/2014
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

string s[20], alf;
int n, order[30];

struct cmp {
	bool operator()(const string a, const string b) {
		int len = min (a.length(), b.length());
		for (int i=0; i<len; i++)
			if (a[i] != b[i]) return order[a[i]-'A'] < order[b[i]-'A'];
		return (a.length() < b.length());
	}
}myCmp;

int main () {
	int t = 1, i, j;
	
	while (scanf("%d", &n), n) {
		cin>>alf;
		for (i=0; i<n; i++)
			cin>>s[i];
		for (i=0; i<26; i++)
			order[alf[i]-'A'] = i;
		sort(s, s+n, myCmp);
		cout<<"year "<<t++<<endl;
		for (i=0; i<n; i++)
			cout<<s[i]<<endl;
	}
	
	
	
	
	
	return 0;
}
