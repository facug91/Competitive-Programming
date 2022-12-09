/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2091
	Name: Counting Task
	Number: 2091
	Date: 09/03/2014
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

#define tint unsigned long long int
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9;

using namespace std;

bool letra['z'+1];

int main() {
	
	int t, i, cont;
	string s;
	
	cin>>t;
	
	while (t--) {
		
		cin>>s;
		
		for (i='0'; i<='9'; i++) letra[i] = false;
		for (i='a'; i<='z'; i++) letra[i] = letra[i-32] = false;
		
		for (i=0; i<s.length(); i++) letra[s[i]] = true;
		
		cont = 0;
		for (i='0'; i<='9'; i++) cont += letra[i];
		for (i='a'; i<='z'; i++) cont += letra[i] + letra[i-32];
		
		cout<<cont<<endl;
	}
	
    return 0;
}
