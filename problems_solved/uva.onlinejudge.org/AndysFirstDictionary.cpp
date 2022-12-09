/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1756
	Name: Andy's First Dictionary
	Number: 10815
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
string s, aux;
set<string> words;

bool is_letter (char c) {
	if (((c >= 'A') && (c<='Z')) || ((c >= 'a') && (c<='z')))
		return true;
	return false;
}

void solve () {
	len = s.length();
	int i = -1;
	while (i<len) {
		aux = "";
		for (++i; is_letter(s[i]); i++) {
			if ((s[i] >= 'A') && (s[i]<='Z')) aux += (s[i]+32);
			else aux += s[i];
		}
		if (aux.length())
			words.insert(aux);
	}
}

int main() {
	
	while (cin>>s)
		solve();
	
	for (set<string>::iterator itr=words.begin(); itr!=words.end(); itr++)
		cout<<*itr<<endl;
	
	return 0;
}
