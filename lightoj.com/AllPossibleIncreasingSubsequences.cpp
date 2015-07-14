/*
        By: facug91
        From: http://lightoj.com/volume_showproblem.php?problem=1085
        Name: All Possible Increasing Subsequences
        Date: 07/07/2015
*/
 
#include <bits/stdc++.h>
#define EPS 1e-9
#define MP make_pair
#define DEB(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
#define MOD 1000000007ll
//#define MAXN 10000100
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

ll n, a[100005], ft[100005], ans;
vector<pair<ll, ll> > seq;

struct cmp {
	bool operator() (const pair<ll, ll> &a, const pair<ll, ll> &b) {
		if (a.first == b.first) return a.second > b.second;
		return a.first < b.first;
	}
};

void update (int pos, ll v) {
	for (; pos<=n; pos += (pos&(-pos))) ft[pos] = (ft[pos] + v) % MOD;
}

ll query (int pos) {
	ll ans = 0ll;
	for (; pos>0; pos -= (pos&(-pos))) ans = (ans + ft[pos]) % MOD;
	return ans;
}

ll query (int a, int b) {
	return (MOD+query(b)-query(a-1)) % MOD;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		seq.clear();
		cin>>n;
		for (i=1; i<=n; i++) {
			cin>>a[i];
			seq.push_back(MP(a[i], i));
		}
		sort(seq.begin(), seq.end(), cmp());
		memset(ft, 0, sizeof ft);
		ans = 0ll;
		for (i=0; i<n; i++) {
			ll v = query(1, seq[i].second) + 1ll;
			ans = (ans + v) % MOD;
			update(seq[i].second, v);
		}
		cout<<"Case "<<it<<": "<<ans<<"\n";
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
