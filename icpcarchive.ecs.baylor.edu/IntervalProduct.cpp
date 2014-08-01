/*
	By: facug91
	From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4150
	Name: Interval Product
	Number: 6139
	Date: 22/07/2014
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
typedef long long ll;
typedef pair<int, int> ii;

int n, k, arr[100005], st[400005], x, y, s;
char op;

int left (int p) {return (p<<1);}
int right (int p) {return (p<<1)+1;}

void build (int p, int L, int R) {
	if (L == R) {
		if (arr[L] > 0) st[p] = 1;
		else if (arr[L] < 0) st[p] = -1;
		else st[p] = 0;
	}else {
		build(left(p), L, (L+R)/2);
		build(right(p), (L+R)/2+1, R);
		st[p] = st[left(p)] * st[right(p)];
	}
}

int update (int p, int L, int R, int idx, int new_value) {
	if (idx > R || idx < L) return st[p];
	if (L == idx && R == idx) {
		if (new_value > 0) return st[p] = 1;
		else if (new_value < 0) return st[p] = -1;
		else return st[p] = 0;
	}
	return st[p] = (update(left(p), L, (L+R)/2, idx, new_value) * update(right(p), (L+R)/2+1, R, idx, new_value));
}

int query (int p, int L, int R, int i, int j) {
	if (i > R || j < L) return INF;
	if (L >= i && R <= j) return st[p];
	int p1 = query(left(p), L, (L+R)/2, i, j);
	int p2 = query(right(p), (L+R)/2+1, R, i, j);
	if (p1 == INF) return p2;
	if (p2 == INF) return p1;
	return p1*p2;
}

int main() {
	int t, i, j;
	
	while (scanf("%d %d", &n, &k) != EOF) {
		for (i=0; i<n; i++)
			scanf("%d", arr+i);
		build(1, 0, n-1);
		
		for (i=0; i<k; i++) {
			scanf(" %c %d %d", &op, &x, &y);
			if (op == 'C') update(1, 0, n-1, x-1, y);
			else {
				s = query(1, 0, n-1, x-1, y-1);
				if (s < 0) printf("-");
				else if (s > 0) printf("+");
				else printf("0");
			}
		}
		printf("\n");
		
	}
	
	return 0;
} 
