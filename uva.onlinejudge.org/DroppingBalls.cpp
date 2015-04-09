/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=620
        Name: Dropping Balls
        Date: 31/03/2015
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

int d, i;

int binary_search (int cur, int depth, int ball) {
	if (depth == d-1) return cur;
	if (ball % 2 == 0) return binary_search(cur*2+1, depth+1, max(ball/2, 1));
	else return binary_search(cur*2, depth+1, max(ball/2+1, 1));
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int TC, i;
	
	cin>>TC;
	while (TC--) {
		cin>>d>>i;
		cout<<binary_search(1, 0, i)<<"\n";
	}
	
	return 0;
}
