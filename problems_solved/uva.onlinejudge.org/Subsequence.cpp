/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3562
        Name: Subsequence
        Date: 13/05/2015
*/

#include <bits/stdc++.h>
#define left oiufg3782fdbeiwfdt2389dfa
#define right jsadh93dbh9d3hdgsakhdg973dh
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000003ll
//#define MAXN 5000050

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, s, seq[100005], ans, sum;
deque<int> dq;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(4); cerr<<fixed<<setprecision(10); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j;
	
	while (cin>>n>>s) {
		for (i=0; i<n; i++) cin>>seq[i];
		ans = INT_MAX; sum = 0; dq.clear();
		for (i=0; i<n; i++) {
			sum += seq[i];
			dq.push_back(seq[i]);
			while (sum-dq.front() >= s) {
				sum -= dq.front();
				dq.pop_front();
			}
			if (sum >= s) ans = min(ans, (int)dq.size());
		}
		cout<<((ans == INT_MAX)?0:ans)<<"\n";
	}
	
	return 0;
}
