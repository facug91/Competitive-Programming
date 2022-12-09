/*
	By: facug91
	From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4996
	Name: Triangular Test II
	Date: 25/05/2016
*/

#include <bits/stdc++.h>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
//#define MOD 100000007
#define MAXN 10000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, int> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, DP[MAXN];
vi tr;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(9); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int i, j;
	
	for (i=1; i*(i+1)/2<MAXN; i++) tr.push_back(i*(i+1)/2);
	DP[0] = 0;
	for (i=0; i<tr.size(); i++) {
		DP[tr[i]] = 1;
		for (j=i; j<tr.size(); j++) {
			if (tr[i]+tr[j] >= MAXN) break;
			DP[tr[i]+tr[j]] = 2;
		}
	}
	while (cin>>n) cout<<((DP[n]==0)?3:DP[n])<<endl;
	
	return 0;
}
