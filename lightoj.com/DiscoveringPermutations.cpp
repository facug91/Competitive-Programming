/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1023
        Name: Discovering Permutations
        Number: 1023
        Date: 17/10/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 131071
//#define MAXN 10000010

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, k;
char letters[30];

int main() {
	int TC, i, j;
	
	cin>>TC;
	for (int it=1; it<=TC; it++) {
		cin>>n>>k;
		for (i=0; i<n; i++) {
			letters[i] = i;
		}
		cout<<"Case "<<it<<":"<<endl;
		i = 0;
		do {
			for (j=0; j<n; j++) {
				cout<<(char)(letters[j]+'A');
			}
			cout<<endl;
			i++;
		} while (next_permutation(letters, letters+n) && (i < k));
	}
	
	return 0;
}
