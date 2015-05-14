/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3644
        Name: Argus
        Date: 13/04/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int q, k, p[3005];
ii act;
string s;
priority_queue<ii, vii, greater<ii> > pq;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(10); cerr<<fixed<<setprecision(10); //cout.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	
	while (cin>>s, s[0] != '#') {
		cin>>q;
		cin>>p[q];
		pq.push(ii(p[q], q));
	}
	cin>>k;
	while (k--) {
		act = pq.top(); pq.pop();
		cout<<act.second<<"\n";
		act.first += p[act.second];
		pq.push(act);
	}
	
	return 0;
}
