/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2874
        Name: Lazy Cat III
        Date: 01/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 10
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int g, a, r, gi, gj, ai, aj, aa, ga, DPG[100005], DPA[100005], gscore, ascore;

int gcd (int a, int b) {
	if (a == 0) return b;
	return gcd(b%a, a);
}

int main () {
	ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j, l;
	
	cin>>g>>a;
	DPG[0] = 0;
	for (i=1; i<100005; i++) DPG[i] = DPG[i-1] + (gcd(g, i) == 1);
	DPA[0] = 0;
	for (i=1; i<100005; i++) DPA[i] = DPA[i-1] + (gcd(a, i) == 1);
	cin>>r;
	gscore = ascore = 0;
	while (r--) {
		cin>>gi>>gj>>ai>>aj>>aa>>ga;
		if (DPG[gj]-DPG[gi-1] == aa) ascore+=2;
		else ascore--;
		if (DPA[aj]-DPA[ai-1] == ga) gscore+=2;
		else gscore--;
	}
	if (gscore == ascore) cout<<"Draw"<<endl;
	else if (gscore > ascore) cout<<"Garfield wins"<<endl;
	else cout<<"Anders wins"<<endl;
	
	return 0;
}
