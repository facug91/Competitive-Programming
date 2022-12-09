/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=3129
        Name: Mysterious Number
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

int n, p;
string t;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int TC;
	
	cin>>TC;
	while (TC--) {
		cin>>n>>t>>p;
		if (t[0] == 'o') cout<<p*2<<"\n";
		else cout<<(p*2)-1<<"\n";
	}
	
	return 0;
}
