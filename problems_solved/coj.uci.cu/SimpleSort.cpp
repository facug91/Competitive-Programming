/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=3140
        Name: Simple Sort
        Date: 07/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl;
//const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int a, arr[501], i, j, k;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	for (i=0; i<1000; i++) {
		cin>>a;
		arr[a]++;
	}
	for (i=0; i<=500; i++) {
		if ((k = arr[i])) for (j=0; j<k; j++) cout<<i<<"\n";
	}
	
	return 0;
}
