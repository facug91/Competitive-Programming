/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=1381
        Name: Fast Fly
        Date: 13/05/2015
*/

#include <bits/stdc++.h>
#define left oiufg3782fdbeiwfdt2389dfa
#define right jsadh93dbh9d3hdgsakhdg973dh
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000003ll
//#define MAXN 5000050

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef vector<int> vi;    typedef vector<ii> vii;

double d, v1, v2, t, m;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout<<fixed<<setprecision(2); 
	int tc, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>d>>v1>>v2>>m;
		t = d/(v1+v2);
		cout<<m*t<<"\n";
	}
	
	return 0;
}
