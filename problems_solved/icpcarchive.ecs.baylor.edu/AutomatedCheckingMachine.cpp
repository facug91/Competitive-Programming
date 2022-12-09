/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4833
        Name: Automated Checking Machine
        Date: 16/12/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int x[5], y[5];

bool check () {
	for (int i=0; i<5; i++)
		if (x[i] == y[i])
			return false;
	return true;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>x[0]>>x[1]>>x[2]>>x[3]>>x[4]) {
		cin>>y[0]>>y[1]>>y[2]>>y[3]>>y[4];
		
		if (check()) cout<<"Y"<<endl;
		else cout<<"N"<<endl;
	}
	
	return 0;
}
