/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2632
	Name: Two Mysterious Alphabets from a Tree
	Number: 2632
	Date: 02/08/2014
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
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;

int n, mat[105][105], sum[105][105], sqr[105][105];



int main () {
	int t, i, j;
	
	scanf("%d", &n);
	for (i=0; i<n; i++)
		for (j=0; j<=i; j++)
			scanf("%d", &mat[i][j]);
	for (j=0; j<n; j++) {
		sum[n-1][j] = mat[n-1][j];
		sqr[n-1][j] = mat[n-1][j]*mat[n-1][j];
	}
	for (i=n-2; i>=0; i--) {
		for (j=0; j<=i; j++) {
			sum[i][j] = mat[i][j] + max(sum[i+1][j], sum[i+1][j+1]);
			sqr[i][j] = mat[i][j]*mat[i][j] + max(sqr[i+1][j], sqr[i+1][j+1]);
		}
	}
	printf("%d %d\n%c%c\n", sqr[0][0], sum[0][0], (char) ((sqr[0][0] % 26) + 'a'), (char) ((sum[0][0] % 26) + 'a'));
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
