/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2784
        Name: In Order of Size
        Date: 01/03/2015
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

int n, f[10005];

int main () {
	ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j, l;
	
	cin>>n;
	for (i=0; i<n; i++) cin>>f[i];
	sort(f, f+n);
	cout<<f[n-1];
	for (i=0; i<n-1; i++) cout<<" "<<f[i];
	cout<<endl;
	
	return 0;
}
