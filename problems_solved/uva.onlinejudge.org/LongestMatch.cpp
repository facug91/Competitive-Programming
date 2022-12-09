/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1041
        Name: Longest Match
        Number: 10100
        Date: 22/08/2014
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

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int LCS[1005][1005];
char s[1005];
vector<string> seq1, seq2;

int lcs () {
	int i, j, size1 = (int) seq1.size(), size2 = (int)seq2.size();
	for (i=0; i<=size1; i++) LCS[i][0] = 0;
	for (j=0; j<=size2; j++) LCS[0][j] = 0;
	for (i=1; i<=size1; i++) {
		for (j=1; j<=size2; j++) {
			if (seq1[i-1] == seq2[j-1]) LCS[i][j] = LCS[i-1][j-1] + 1;
			else LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
		}
	}
	return LCS[size1][size2];
}

int main () {
	//ios_base::sync_with_stdio(0);
	int TC = 1, i, j;
	
	while (gets(s)) {
		seq1.clear();
		seq2.clear();
		
		if (s[0] != 0) {
			char * p = new char[25];
			p = strtok(s, " !#$%&'()*+,-./:;<=>?@[]^_`{|}~");
			while (p != NULL) {
				seq1.push_back(string(p));
				p = strtok(NULL, " !#$%&'()*+,-./:;<=>?@[]^_`{|}~");
			}
		}
		
		gets(s);
		if (s[0] != 0) {
			char * p = new char[25];
			p = strtok(s, " !#$%&'()*+,-./:;<=>?@[]^_`{|}~");
			while (p != NULL) {
				seq2.push_back(string(p));
				p = strtok(NULL, " !#$%&'()*+,-./:;<=>?@[]^_`{|}~");
			}
		}
		
		printf("%2d. ", TC++);
		if (seq1.empty() || seq2.empty()) printf("Blank!\n");
		else printf("Length of longest match: %d\n", lcs());
	}
	
	return 0;
}
