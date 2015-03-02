/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2843
        Name: GCD
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

int n, ans;
vi seq;

int gcd (int a, int b) {
	if (a == 0) return b;
	return gcd(b%a, a);
}

int main () {
	ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j, l;
	
	while (cin>>n) seq.push_back(n);
	ans = 1;
	for (i=0; i<seq.size(); i++)
		for (j=i+1; j<seq.size(); j++)
			ans = max(ans, gcd(seq[i], seq[j]));
	cout<<ans<<endl;
	
	return 0;
}
