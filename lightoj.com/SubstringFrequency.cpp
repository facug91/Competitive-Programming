/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1255
        Name: Substring Frequency
        Date: 03/11/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

char t[1000005], p[1000005];
int b[1000005], n, m;

void kmpPreprocess () {
	int i = 0, j = -1; b[0] = -1;
	while (i < m) {
		if (j >= 0 && p[i] != p[j]) j = b[j];
		i++; j++;
		b[i] = j;
	}
}
int kmpSearch () {
	int i = 0, j = 0, ans = 0;
	while (i < n) {
		while (j >= 0 && t[i] != p[j]) j = b[j];
		i++; j++;
		if (j == m) {
			ans++;
			j = b[j];
		}
	}
	return ans;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	scanf("%d", &TC);
	for (int it=1; it<=TC; it++) {
		scanf("%s %s", t, p);
		n = strlen(t);
		m = strlen(p);
		kmpPreprocess();
		printf("Case %d: %d\n", it, kmpSearch());
	}
	
	return 0;
}
