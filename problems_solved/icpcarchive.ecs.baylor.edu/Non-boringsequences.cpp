/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=4269
        Name: Non-boring sequences
        Date: 14/07/2015
*/
 
#include <bits/stdc++.h>
#define next asjkdbg1238dv8ydf38gy832gf8yd
#define prev asjkdbuiqdg783gdiu3dg79832dui
#define y1 disagd91hd719dtg87d138dg317
#define EPS 1e-9
#define MP make_pair
#define DEB(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10000100
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

int n, a[200005], prev[200005], next[200005];
unordered_map<int, int> pos;
unordered_map<int, int>::iterator itr;

bool search (int l, int r) {
	if (l >= r) return true;
	int i = l, j = r;
	while (i <= j) {
		if (prev[i] < l && next[i] > r) return search(l, i-1) && search(i+1, r);
		if (i < j && prev[j] < l && next[j] > r) return search(l, j-1) && search(j+1, r);
		i++; j--;
	}
	return false;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>n;
		pos.clear();
		for (i=0; i<n; i++) cin>>a[i];
		for (i=0; i<n; i++) {
			itr = pos.find(a[i]);
			if (itr == pos.end()) {
				pos.insert(ii(a[i], i));
				prev[i] = -1;
			} else {
				next[(*itr).second] = i;
				prev[i] = (*itr).second;
				(*itr).second = i;
			}
			next[i] = INF;
		}
		if (search(0, n-1)) cout<<"non-boring\n";
		else cout<<"boring\n";
	}
	
	return 0;
}
