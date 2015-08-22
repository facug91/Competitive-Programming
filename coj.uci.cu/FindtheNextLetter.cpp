/*
        By: facug91
        From: http://coj.uci.cu/contest/cproblem.xhtml?pid=3239&cid=1453
        Name: Find the Next Letter
        Date: 06/06/2015
*/
 
#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
#define MOD 1000000007
//#define MAXN 10000100
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

int n, ans[100005];
string s;
vi prev[30];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(9); //cerr<<fixed<<setprecision(10); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>n>>s;
		for (i=0; i<30; i++) prev[i].clear();
		for (i=0; i<n; i++) ans[i] = -2;
		for (i=0; i<n; i++) {
			for (j=0; j<s[i]-'a'; j++) {
				while (prev[j].size()) {
					ans[prev[j].back()] = i;
					prev[j].pop_back();
				}
			}
			prev[s[i]-'a'].push_back(i);
		}
		cout<<ans[0]+1;
		for (i=1; i<n; i++) cout<<" "<<ans[i]+1;
		cout<<"\n";
	}
	
	return 0;
}
