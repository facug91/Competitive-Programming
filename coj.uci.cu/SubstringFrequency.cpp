/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2250
        Name: Substring Frequency
        Date: 18/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int ans, n, m, b[1000005];
string t, p;

void kmp_preprocess () {
	int i = 0, j = -1; b[0] = -1;
	while (i < m) {
		while (j >= 0 && p[i] != p[j]) j = b[j];
		i++; j++;
		b[i] = j;
	}
}

void kmp_search () {
	int i = 0, j = 0; ans = 0;
	while (i < n) {
		while (j >= 0 && t[i] != p[j]) j = b[j];
		i++; j++;
		if (j == m) {
			ans++;
			j = b[j];
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int TC, i, j;
	
	cin>>TC;
	for (int it=1; it<=TC; it++) {
		cin>>t>>p;
		n = t.length(); m = p.length();
		kmp_preprocess();
		kmp_search();
		cout<<"Case "<<it<<": "<<ans<<"\n";
	}
	
	return 0;
}
