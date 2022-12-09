/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=3147
        Name: Sum Challenge
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

int n, seq[55], act;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		cin>>n;
		for (i=0; i<n; i++) cin>>seq[i];
		bool ok = false;
		for (i=0; i<n; i++) {
			act = 0;
			for (j=i; j<n; j++) {
				act += seq[j];
				if (act == 0) ok = true;
			}
		}
		if (ok) cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}
