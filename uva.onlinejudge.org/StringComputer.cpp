/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=100
        Name: String Computer
        Number: 164
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

int LD[25][25];
string s1, s2;
char action[25][25];

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
			cha = LD[i-1][j-1] + ((s1[j-1] == s2[i-1]) ? 0 : 1);
			del = LD[i][j-1] + 1;
			ins = LD[i-1][j] + 1;
			if (ins <= cha && ins <= del) {
				LD[i][j] = ins;
				action[i][j] = 'I';
			} else if (del <= cha && del <= ins) {
				LD[i][j] = del;
				action[i][j] = 'D';
			} else {
				LD[i][j] = cha;
				if (s1[j-1] == s2[i-1])	action[i][j] = 'N';
				else action[i][j] = 'C';
			}
		}
	}
}

void print (int x, int y) {
	if (x == 0 && y == 0) return;
	if (x == 0) {
		print(x, y-1);
		printf("D%c01", s1[y-1]);
	} else if (action[x][y] == 'N') {
		print(x-1, y-1);
	} else if (action[x][y] == 'C') {
		print(x-1, y-1);
		printf("C%c%02d", s2[x-1], x);
	} else if (action[x][y] == 'I') {
		print(x-1, y);
		printf("I%c%02d", s2[x-1], x);
	} else if (action[x][y] == 'D') {
		print(x, y-1);
		printf("D%c%02d", s1[y-1], x+1);
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	int i, j;
	
	while (cin>>s1, s1[0] != '#') {
		cin>>s2;
		ld();
		int size1 = (int)s1.length(), size2 = (int)s2.length();
		print((int)s2.size(), (int)s1.size());
		printf("E\n");
	}
	
	return 0;
}

