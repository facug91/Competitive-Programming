/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2531
        Name: Smallest Sub-Array
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

int n, m, k, seq[1000005], acc[105], cont, ans;
deque<int> dq;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(4); cerr<<fixed<<setprecision(10); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	seq[0] = 1;
	seq[1] = 2;
	seq[2] = 3;
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>n>>m>>k;
		for (i=3; i<n; i++) seq[i] = (seq[i-1] + seq[i-2] + seq[i-3]) % m + 1;
		dq.clear(); memset(acc, 0, sizeof acc); cont = 0; ans = INT_MAX;
		for (i=0; i<n; i++) {
			dq.push_back(seq[i]); 
			if (seq[i] <= k) {
				if (acc[seq[i]] == 0) cont++;
				acc[seq[i]]++;
			}
			while (dq.size() && (dq.front() > k || acc[dq.front()] > 1)) {
				if (dq.front() <= k) acc[dq.front()]--;
				dq.pop_front();
			}
			if (cont == k) ans = min(ans, (int)dq.size());
		}
		if (ans == INT_MAX) cout<<"Case "<<it<<": sequence nai\n";
		else cout<<"Case "<<it<<": "<<ans<<"\n";
	}
	
	return 0;
}
