/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=3007
        Name: Eight Queens
        Date: 18/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int v, h, d1, d2, cant;
string board[8];
bool ok;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int i, j;
	
	for (i=0; i<8; i++) cin>>board[i];
	v = h = d1 = d2 = cant = 0;
	ok = true;
	for (i=0; i<8; i++) for (j=0; j<8; j++) if (board[i][j] == '*') {
		if (((v & (1<<j)) != 0) || ((h & (1<<i)) != 0) || ((d1 & (1<<(i+j))) != 0) || ((d2 & (1<<((7-i)+j))) != 0)) ok = false;
		v |= (1<<j); h |= (1<<i); d1 |= (1<<(i+j)); d2 |= (1<<((7-i)+j));
		cant++;
	}
	if (ok && cant == 8) cout<<"valid\n";
	else cout<<"invalid\n";
	
	return 0;
}
