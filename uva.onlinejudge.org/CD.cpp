/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=565
	Name: CD
	Number: 624
	Date: 05/07/2014
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

int n, t, tracks[21];
pair<int, int> ans, DP[21][50000];

pair<int, int> dp (int id, int res) {
	if (id == t) return make_pair(res, 0);
	if (res == 0) return make_pair(0, 0);
	if (DP[id][res].first != -1) return DP[id][res];
	if (tracks[id] > res) return dp(id+1, res);
	pair<int, int> aux0 = dp(id+1,res-tracks[id]);
	aux0.second |= (1<<id);
	pair<int, int> aux1 = dp(id+1, res);
	if (aux0.first > aux1.first) return aux1;
	return aux0;
}

int main() {
	
	int i, j;
	
	while (scanf("%d %d", &n, &t) != EOF) {
		
		for (i=0; i<t; i++)
			scanf("%d", tracks+i);
		
		for (i=0; i<t; i++)
			for (j=0; j<50000; j++)
				DP[i][j].first = -1;
		
		ans = dp(0, n);
		//cout<<"first "<<ans.first<<endl;
		//cout<<"second "<<ans.second<<endl;
		for (i=0; i<t; i++)
			if (ans.second & (1<<i))
				printf("%d ", tracks[i]);
		printf("sum:%d\n", n-ans.first);
		
	}
	
	return 0;
}
