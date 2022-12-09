/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3106
        Name: 
        Number: 11955
        Date: 07/10/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 131071
//#define MAXN 10000010

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

ll DP[55][55];
int k;
char s[105], s1[105], s2[105], *p = new char[105];

void init () {
	int i, j;
	for (i=0; i<55; i++) {
		DP[i][i] = 1ll;
		DP[i][0] = 1ll;
	}
	for (i=2; i<55; i++) {
		for (j=1; j<i; j++) {
			DP[i][j] = DP[i-1][j-1] + DP[i-1][j];
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	init();
	
	scanf("%d", &TC);
	getchar();
	for (int it=1; it<=TC; it++) {
		printf("Case %d: ", it);
		gets(s);
		p = strtok(s, "()+^ ");
		strcpy(s1, p);
		p = strtok(NULL, "()+^ ");
		strcpy(s2, p);
		p = strtok(NULL, "()+^ ");
		k = atoi(p);
		printf("%s", s1);
		if (k != 1) printf("^%d", k);
		i = 1;
		while (DP[k][i] != 1ll) {
			printf("+%lld*%s", DP[k][i], s1);
			if ((k-i) != 1) printf("^%d", k-i);
			printf("*%s", s2);
			if (i != 1) printf("^%d", i);
			i++;
		}
		printf("+%s", s2);
		if (k != 1) printf("^%d", k);
		printf("\n");
	}
	
	return 0;
}
