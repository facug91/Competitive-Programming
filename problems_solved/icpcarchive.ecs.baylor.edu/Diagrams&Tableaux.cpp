/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&Itemid=99999999&page=show_problem&category=&problem=4636&mosmsg=Submission+received+with+ID+1736295
        Name: Diagrams & Tableaux
        Date: 31/07/2015
*/
 
#include <bits/stdc++.h>
#define y1 nd03dnqwuidg1odbnw9uddu0132d
#define clock asoudh219udhjdgausdhs9udy
#define EPS 1e-9
#define MP make_pair
#define DEB(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 4294967296ll
#define MAXN 1001
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

int k, l[10], n, act[10][10], bottom[10];
map<pair<pair<int, int>, vector<int> >, int> DP;
map<pair<pair<int, int>, vector<int> >, int>::iterator itr;

int search (int x, int y) {
	if (x == k) return 1;
	if (y == l[x]) return search(x+1, 0);
	int mn = 1;
	if (x != 0) mn = act[x-1][y]+1;
	if (y != 0) mn = max(mn, act[x][y-1]);
	if (mn > n) return 0;
	vector<int> v;
	for (int i=0; i<y; i++) v.push_back(act[x][i]);
	if (x != 0) for (int i=y; i<l[x]; i++) v.push_back(act[x-1][i]);
	itr = DP.find(make_pair(make_pair(x, y), v));
	if (itr != DP.end()) return (*itr).second;
	int ans = 0;
	while (mn <= n && (bottom[y]-x-1)+mn<=n) {
		act[x][y] = mn;
		ans += search(x, y+1);
		mn++;
	}
	DP[make_pair(make_pair(x, y), v)] = ans;
	return ans;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int i, j;
	
	while (cin>>k) {
		DP.clear();
		for (i=0; i<k; i++) cin>>l[i];
		for (i=0; i<l[0]; i++) {
			for (j=0; j<k && l[j]-1>=i; j++);
			bottom[i] = j;
		}
		cin>>n;
		memset(act, 0, sizeof act);
		cout<<search(0, 0)<<"\n";
	}
	
	return 0;
}
