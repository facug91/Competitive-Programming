/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1020
        Name: A Childhood Game
        Date: 12/05/2015
*/

#include <bits/stdc++.h>
#define left oiufg3782fdbeiwfdt2389dfa
#define right jsadh93dbh9d3hdgsakhdg973dh
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000003ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n;
string name;

int main () {
	int tc, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>n>>name;
		cout<<"Case "<<it<<": ";
		if (name[0] == 'A') {
			if (n % 3 == 1) cout<<"Bob\n";
			else cout<<"Alice\n";
		} else {
			if (n % 3 == 0) cout<<"Alice\n";
			else cout<<"Bob\n";
		}
	}
	
	return 0;
}
