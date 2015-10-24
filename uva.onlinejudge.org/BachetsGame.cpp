/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1345
        Name: Bachet's Game
        Date: 24/10/2015
*/
 
#include <bits/stdc++.h>
#define y1		nd03dnqwuidg1odbnw9uddu0132d
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10005
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<int, ii> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iii> viii; typedef vector<iiii> viiii;

int n, m, p[15];
bool win[1000005];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(2); cerr<<fixed<<setprecision(6); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	//cout << std::right << std::setw(13)
	int tc, i, j;
	
	while (cin>>n>>m) {
		for (i=0; i<m; i++) cin>>p[i];
		for (i=1; i<=n; i++) win[i] = false;
		win[0] = false;
		for (i=1; i<=n; i++) for (j=0; j<m && !win[i]; j++) if (i-p[j] >= 0) win[i] |= !win[i-p[j]];
		if (win[n]) cout<<"Stan wins"<<endl;
		else cout<<"Ollie wins"<<endl;
	}
	
	return 0;
}
