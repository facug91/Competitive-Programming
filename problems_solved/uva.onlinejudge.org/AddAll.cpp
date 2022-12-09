/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1895
        Name: Add All
        Date: 13/04/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-12
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, a, b, ans;
priority_queue<int, vi, greater<int> > pq;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(10); cerr<<fixed<<setprecision(10); //cout.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	
	while (cin>>n, n) {
		for (int i=0; i<n; i++) {
			cin>>a;
			pq.push(a);
		}
		ans = 0;
		while (pq.size() > 1) {
			a = pq.top(); pq.pop();
			b = pq.top(); pq.pop();
			ans += a+b;
			pq.push(a+b);
		}
		pq.pop();
		cout<<ans<<"\n";
	}
	
	return 0;
}
