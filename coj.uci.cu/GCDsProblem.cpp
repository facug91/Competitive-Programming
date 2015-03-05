/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2887
        Name: GCDs Problem
        Date: 03/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, a[100005], ptr, g;
set<int> ans, act[2];
set<int>::iterator itr;

int gcd (int a, int b) {
	if (a == 0) return b; 
	return gcd(b%a, a);
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>n, n) {
		for (i=0; i<n; i++) cin>>a[i];
		ans.clear(); act[0].clear(); act[1].clear(); ptr = 0;
		for (i=0; i<n; i++) {
			for (itr=act[ptr].begin(); itr!=act[ptr].end(); itr++) {
				g = gcd((*itr), a[i]);
				ans.insert(g);
				act[ptr^1].insert(g);
			}
			act[ptr^1].insert(a[i]);
			ans.insert(a[i]);
			act[ptr].clear();
			ptr ^= 1;
		}
		cout<<ans.size()<<endl;
	}
	
	return 0;
}
