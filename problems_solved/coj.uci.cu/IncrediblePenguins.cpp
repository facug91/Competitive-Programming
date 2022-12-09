/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2752
        Name: Incredible Penguins
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

int n, match[1005], id;
string s;
vector<pair<string, int> > p;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int i;
	
	memset(match, 0, sizeof match);
	cin>>n;
	for (i=0; i<n; i++) {
		cin>>s>>id;
		match[abs(id)] ^= 1;
		p.push_back(MP(s, abs(id)));
	}
	cout<<"FOREVER ALONE ones:\n";
	for (i=0; i<p.size(); i++) if (match[p[i].second]) cout<<p[i].first<<"\n";
	
	return 0;
}
