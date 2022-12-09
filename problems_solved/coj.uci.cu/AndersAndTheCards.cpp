/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=3132
        Name: Anders And The Cards
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

int n, q, moves[100005][2];
ll cards[100005];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int i;
	
	cin>>n>>q;
	for (i=0; i<q; i++) cin>>moves[i][0]>>moves[i][1];
	for (i=1; i<=n; i++) cin>>cards[i];
	for (i=q-1; i>=0; i--) swap(cards[moves[i][0]], cards[moves[i][1]]);
	cout<<cards[1];
	for (i=2; i<=n; i++) cout<<" "<<cards[i];
	cout<<"\n";
	
	return 0;
}
