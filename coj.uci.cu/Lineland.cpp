/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2907
	Name: Lineland
	Number: 2907
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

#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
#define _log2(x) log(x) * 1.44269504088896340736
//const long double PI = 2*acos(0);

#define INF 1000000000

using namespace std;

int n, x, c;
vector<pair<int, int> > point(2000005, make_pair(0, 0));
vector<pair<int, int> >::iterator itr;


int main () {
	int t, i, j;
	
	while (scanf("%d", &n) != EOF) {
		
		for (i=0; i<n; i++) {
			scanf("%d %d", &x, &c);
			point[i].first = x;
			point[i].second = c;
		}
		
		sort(point.begin(), point.begin()+n);
		
		int idx, mx = -1, aux;
		for (itr=point.begin(), i=0; i<n; itr++, i++) {
			aux = distance(itr, lower_bound(itr, point.begin()+min((*itr).second+i, n), make_pair((*itr).first+(*itr).second, 0)));
			//cout<<"aux "<<aux<<endl;
			if (aux > mx) {
				mx = aux;
				idx = i;
			}
		}
		
		printf("%d %d\n", point[idx].first, mx-1);
		
	}
	
	return 0;
}
