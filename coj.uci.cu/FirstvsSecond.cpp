/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2691
        Name: First vs Second
        Date: 05/04/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, m, s[2], t;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int i;
	
	cin>>n>>m;
	s[0] = s[1] = 0;
	for (i=0; i<n; i++) cin>>t, s[0] += t;
	for (i=0; i<m; i++) cin>>t, s[1] += t;
	if (s[0] > s[1]) cout<<"first win\n";
	else if (s[0] < s[1]) cout<<"second win\n";
	else cout<<"tie\n";
	
	return 0;
}
