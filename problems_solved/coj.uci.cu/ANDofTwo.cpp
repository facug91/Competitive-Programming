/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=3128
        Name: AND of Two
        Date: 13/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, a, f;
vi seq[2];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		cin>>n;
		seq[0].clear();
		seq[1].clear();
		for (i=0; i<n; i++) {
			cin>>a;
			seq[0].push_back(a);
		}
		f = 0;
		for (i=9; i>=0; i--) {
			seq[f^1].clear();
			for (j=0; j<seq[f].size(); j++)
				if ((seq[f][j] & (1<<i)) != 0) seq[f^1].push_back(seq[f][j]);
			if (seq[f^1].size() > 1) f ^= 1;
		}
		cout<<(seq[f][0]&seq[f][1])<<"\n";
	}
	
	return 0;
}
