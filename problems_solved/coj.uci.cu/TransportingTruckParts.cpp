/*
        By: facug91
        From: http://coj.uci.cu/contest/cproblem.xhtml?cid=1453&pid=3170
        Name: Transporting Truck Parts
        Date: 09/06/2015
*/
 
#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10000100
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

ll n, k, s, d, t[10];
vector<ll> p[10];
bool vis[500005];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	
	cin>>n>>k;
	s = (n*(n+1ll))/2ll;
	if (s % k != 0ll) cout<<"NO\n";
	else {
		d = s / k;
		for (int i=0; i<k; i++) {
			int j = n;
			while (j >= 1 && t[i] != d) {
				if (t[i]+j <= d && !vis[j]) {
					vis[j] = true;
					t[i] += j;
					p[i].push_back(j);
					j = min(d-t[i], j-1ll);
				} else j--;
			}
			if (t[i] != d) {
				cout<<"NO\n";
				return 0;
			}
		}
		for (int i=0; i<k; i++) {
			cout<<p[i].size()<<"\n";
			cout<<p[i][0];
			for (int j=1; j<p[i].size(); j++) cout<<" "<<p[i][j];
			cout<<"\n";
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
