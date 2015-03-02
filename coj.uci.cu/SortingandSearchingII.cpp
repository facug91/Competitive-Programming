/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=3068
        Name: Sorting and Searching II
        Date: 01/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 10
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, q1, q2, a;
vi seq;

int main () {
	//ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j, l;
	
	scanf("%d", &n);
	for (i=0; i<n; i++) {
		scanf("%d", &a);
		seq.push_back(a);
	}
	sort(seq.begin(), seq.end());
	scanf("%d %d", &q1, &q2);
	for (i=0; i<q1; i++) {
		scanf("%d", &a);
		if (binary_search(seq.begin(), seq.end(), a)) printf(":)\n");
		else printf(":(\n");
	}
	for (i=0; i<q2; i++) {
		scanf("%d", &a);
		printf("%d\n", seq[a-1]);
	}
	
	return 0;
}
