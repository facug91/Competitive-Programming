/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=3133
        Name: MALCOLM
        Date: 19/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
#define MP make_pair
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, k, l[25];
ll ans;
string s;
queue<int> q;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int i;
	
	cin>>n>>k;
	memset(l, 0, sizeof l);
	ans = 0ll;
	for (i=0; i<n; i++) {
		cin>>s;
		ans += (ll)l[s.length()];
		l[s.length()]++;
		q.push(s.length());
		if (q.size() > k) l[q.front()]--, q.pop();
	}
	cout<<ans<<"\n";
	
	return 0;
}
