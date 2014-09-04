/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=467
        Name: String Distance and Transform Process
        Number: 526
        Date: 26/08/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007
//#define MAXN N

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int LD[85][85], cont;
string s1, s2;
char action[85][85];

void ld () {
	int i, j, size1 = (int)s1.length(), size2 = (int)s2.length(), ins, del, cha;
	LD[0][0] = 0;
	action[0][0] = 'N';
	for (j=1; j<=size1; j++) {
		LD[0][j] = j;
		action[0][j] = 'D';
	}
	for (i=1; i<=size2; i++) {
		LD[i][0] = i;
		action[i][0] = 'I';
	}
	for (i=1; i<=size2; i++) {
		for (j=1; j<=size1; j++) {
			cha = LD[i-1][j-1] + (s2[i-1] != s1[j-1]);
			ins = LD[i-1][j] + 1;
			del = LD[i][j-1] + 1;
			if (del <= ins && del <= cha) {
				LD[i][j] = del;
				action[i][j] = 'D';
			} else if (cha <= ins && cha <= del) {
				LD[i][j] = cha;
				action[i][j] = (s2[i-1] != s1[j-1]) ? 'C' : 'N';
			} else {
				LD[i][j] = ins;
				action[i][j] = 'I';
			}
		}
	}
}

void print (int x, int y) {
	if (x == 0 && y == 0) return;
	if (action[x][y] == 'D') {
		print(x, y-1);
		printf("%d Delete %d\n", cont++, x+1);
	} else if (action[x][y] == 'I') {
		print(x-1, y);
		printf("%d Insert %d,%c\n", cont++, x, s2[x-1]);
	} else if (action[x][y] == 'C') {
		print(x-1, y-1);
		printf("%d Replace %d,%c\n", cont++, x, s2[x-1]);
	} else print(x-1, y-1);
}

int main () {
	//ios_base::sync_with_stdio(0);
	int i, j;
	bool first = true;
	
	while (getline(cin, s1)) {
		
		if (first) first = false;
		else printf("\n");
		
		getline(cin, s2);
		
		ld();
		
		printf("%d\n", LD[(int)s2.length()][(int)s1.length()]);
		cont = 1;
		print((int)s2.length(), (int)s1.length());
	}
	
	return 0;
}

