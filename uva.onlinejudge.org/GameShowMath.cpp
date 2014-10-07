/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1341
        Name: Game Show Math
        Number: 10400
        Date: 12/09/2014
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
//#define MAXN 6005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int p, seq[105], obj, move[105][64010];

bool dp (int idx, int count) {
	if (idx == p) {
		if ((count-32000) == obj) return true;
		return false;
	}
	if (move[idx][count] != -1) return move[idx][count];
	if ((abs((count-32000)+seq[idx]) <= 32000) && (dp(idx+1, count+seq[idx]))) {
		move[idx][count] = 1;
		return true;
	}
	if ((abs((count-32000)-seq[idx]) <= 32000) && (dp(idx+1, count-seq[idx]))) {
		move[idx][count] = 2;
		return true;
	}
	if ((abs((count-32000)*seq[idx]) <= 32000) && (dp(idx+1, ((count-32000)*seq[idx])+32000))) {
		move[idx][count] = 3;
		return true;
	}
	if (((count-32000) % seq[idx] == 0) && (abs((count-32000)/seq[idx]) <= 32000) && (dp(idx+1, ((count-32000)/seq[idx])+32000))) {
		move[idx][count] = 4;
		return true;
	}
	move[idx][count] = 0;
	return false;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		cin>>p;
		for (i=0; i<p; i++)
			cin>>seq[i];
		cin>>obj;
		memset(move, -1, sizeof move);
		if (dp(1, seq[0]+32000)) {
			cout<<seq[0];
			j=seq[0];
			for (i=1; i<p; i++) {
				switch (move[i][j+32000]) {
					case 1:
						cout<<"+"<<seq[i];
						j += seq[i];
						break;
					case 2:
						cout<<"-"<<seq[i];
						j -= seq[i];
						break;
					case 3:
						cout<<"*"<<seq[i];
						j *= seq[i];
						break;
					case 4:
						cout<<"/"<<seq[i];
						j /= seq[i];
						break;
				}
			}
			cout<<"="<<obj<<"\n";
		} else cout<<"NO EXPRESSION\n";
	}
	
	return 0;
}

