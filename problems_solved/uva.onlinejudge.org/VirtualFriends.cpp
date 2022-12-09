/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2498
	Name: Virtual Friends
	Number: 11503
	Date: 08/07/2014
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

struct cmp {
	bool operator() (char * a, char * b) {
		return strcmp(a, b) > 0;
	}
};

map<char*, int, cmp> hash;
int f,cant, p[200005], rank[200005], size_set[200005];
char s1[25], s2[25], * c;

int find_set (int i) {return (p[i] == i) ? i : (p[i] = find_set(p[i]));}

void union_set (int i, int j) {
	int x = find_set(i);
	int y = find_set(j);
	if (x != y) {
		if (rank[x] > rank[y]) {
			p[y] = x;
			size_set[x] += size_set[y];
		} else {
			p[x] = y;
			size_set[y] += size_set[x];
			if (rank[x] == rank[y]) 
				rank[y]++;
		}
	}
}

int main () {
	
	int t, i, j;
	
	scanf("%d", &t);
	
	while (t--) {
		
		scanf("%d", &f);
		
		for (i=0; i<f*2; i++) {
			p[i] = i;
			rank[i] = 0;
			size_set[i] = 1;
		}
		
		cant = 0;
		while (f--) {
		
			scanf("%s %s", s1, s2);
			if (hash.find(s1) == hash.end()) {
				c = new char[25];
				strcpy(c, s1);
				hash.insert(make_pair(c, cant++));
			}
			if (hash.find(s2) == hash.end()) {
				c = new char[25];
				strcpy(c, s2);
				hash.insert(make_pair(c, cant++));
			}
			
			union_set(hash[s1], hash[s2]);
			printf("%d\n", size_set[find_set(hash[s1])]);
			
		}
		
		if (t) hash.clear();
		
	}
	
	return 0;
}
