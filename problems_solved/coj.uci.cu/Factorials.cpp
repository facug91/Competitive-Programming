/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=3135
        Name: Factorials
        Date: 13/03/2015
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

int n, F[5005];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int TC, i;
	
	F[0] = 1;
	for (i=1; i<5005; i++) {
		F[i] = i * F[i-1];
		while (F[i] % 10 == 0) F[i] /= 10;
		F[i] %= 10000;
	}
	cin>>TC;
	while (TC--) {
		cin>>n;
		cout<<(F[n]%10)<<"\n";
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
