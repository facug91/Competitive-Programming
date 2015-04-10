/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2483
        Name: Rectangle
        Date: 02/04/2015
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

int x, y, a, b;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	x = y = 0;
	cin>>a>>b;
	x ^= a; y ^= b;
	cin>>a>>b;
	x ^= a; y ^= b;
	cin>>a>>b;
	x ^= a; y ^= b;
	cout<<x<<" "<<y<<"\n";
	
	return 0;
}
