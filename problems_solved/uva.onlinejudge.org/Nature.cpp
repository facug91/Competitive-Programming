/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1626
	Name: Nature
	Number: 10685
	Date: 18/07/2014
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
//const long double PI = 2*acos(0);

#define INF 1000000000

using namespace std;

int c, r, p[5010], rank[5010], size_set[5010], mx;
map<string, int> hash;
string s0, s1;

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
			if (rank[y] == rank[x]) rank[y]++;
		}
	}
}

int main() {
	int i, j;
	
	while (cin>>c>>r, c || r) {
		
		for (i=0; i<c; i++)
			p[i] = i, rank[i] = 0, size_set[i] = 1;
		
		for (i=0; i<c; i++) {
			cin>>s0;
			hash.insert(make_pair(s0, i));
		}
		
		for (i=0; i<r; i++) {
			cin>>s0>>s1;
			union_set(hash[s0], hash[s1]);
		}
		
		mx = -1;
		for (i=0; i<c; i++)
			if (size_set[find_set(i)] > mx) mx = size_set[find_set(i)];
		
		printf("%d\n", mx);
		
	}
	
	return 0;
} 
