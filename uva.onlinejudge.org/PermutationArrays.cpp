/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=423
	Name: Permutation Arrays
	Number: 482
	Date: 09/07/2014
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

int n;
vector<pair<int, int> > pos;
vector<char*> vec;
char s[1000005];

void parse_ints () {
	int aux = 0, ind = 0;
	char * p;
	p = strtok(s, " ");
	while (p != NULL) {
		aux = atoi(p);
		pos.push_back(make_pair(aux, ind++));
		p = strtok(NULL, " ");
	}
}

void parse_double () {
	char * p;
	p = strtok(s, " ");
	while (p != NULL) {
		vec.push_back(p);
		p = strtok(NULL, " ");
	}
}

int main () {
	
	int t, i, j;
	
	scanf("%d", &t);
	getchar();
	
	while (t--) {
		
		gets(s);
		gets(s);
		parse_ints();
		
		sort(pos.begin(), pos.end());
		
		gets(s);
		
		parse_double();
		
		for (i=0; i<pos.size(); i++)
			printf("%s\n", vec[pos[i].second]);
		
		if (t) {
			printf("\n");
			vec.clear();
			pos.clear();
		}
		
	}
	
	return 0;
}
