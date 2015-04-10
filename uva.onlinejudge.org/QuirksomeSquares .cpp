/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=192
        Name: Quirksome Squares 
        Date: 09/04/2015
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

int dig;
vi memo[10];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(10); cerr<<fixed<<setprecision(10); //cout.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j, k;
	
	int lim = 10;
	for (i=2; i<=8; i+=2) {
		for (j=0; j<lim; j++) for (k=0; k<lim; k++)
			if (((j+k)*(j+k)) == ((j*lim)+k)) memo[i].push_back((j*lim)+k);
		lim *= 10;
	}
	while (cin>>dig) {
		for (i=0; i<memo[dig].size(); i++) cout<<setfill('0')<<setw(dig)<<memo[dig][i]<<"\n";
	}
	
	return 0;
}
