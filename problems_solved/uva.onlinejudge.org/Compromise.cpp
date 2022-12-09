/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=472
        Name: Compromise
        Number: 531
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
typedef pair<int, pair<int, int> > iii;

int n1, n2, LCS[105][105];
string proposal1[105], proposal2[105];
stack<string> p;

void lcs () {
	int i, j;
	for (i=0; i<=n1; i++) LCS[i][0] = 0;
	for (i=0; i<=n2; i++) LCS[0][i] = 0;
	for (i=1; i<=n1; i++) {
		for (j=1; j<=n2; j++) {
			if (proposal1[i] == proposal2[j]) LCS[i][j] = LCS[i-1][j-1] + 1;
			else LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
		}
	}
}

void print () {
	int i = n1, j = n2;
	while (i >= 1 && j >= 1) {
		if (proposal1[i] == proposal2[j]) {
			p.push(proposal1[i]);
			i--; j--;
		} else if (LCS[i-1][j] > LCS[i][j-1]) i--;
		else j--;
	}
	if (!p.empty()) {
		cout<<p.top();
		p.pop();
	}
	while (!p.empty()) {
		cout<<" "<<p.top();
		p.pop();
	}
	cout<<endl;
}

int main () {
	//ios_base::sync_with_stdio(0);
	int i, j;
	
	while (cin>>proposal1[1]) {
		n1 = 2;
		while (cin>>proposal1[n1], proposal1[n1][0] != '#') n1++;
		n1--;
		n2 = 1;
		while (cin>>proposal2[n2], proposal2[n2][0] != '#') n2++;
		n2--;
		lcs();
		print();
	}
	
	return 0;
}
