/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2722
        Name: Random Numbers
        Date: 07/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl;
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000007ll
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

ll y;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int TC, i, j, l;
	
	cin>>y;
	for (i=1; i<=10; i++) {
		y = (y * 13821ll) % 32768ll;
		cout<<y<<" : "<<(y%7ll)+1ll<<"\n";
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
