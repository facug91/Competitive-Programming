/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2780
        Name: SQUARES
        Date: 02/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 10
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, DP[1005];
vi sq;

int main () {
	ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j, l;
	
	for (i=1; i<=500; i++) sq.push_back(i*i);
	memset(DP, 0, sizeof DP);
	for (i=0; i<sq.size(); i++)
		for (j=i; j<sq.size(); j++)
			if (sq[j]-sq[i] <= 1000)
				DP[sq[j]-sq[i]]++;
	cin>>n;
	cout<<DP[n]<<endl;
	
	return 0;
}
