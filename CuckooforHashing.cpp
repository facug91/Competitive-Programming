/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4565
        Name: Cuckoo for Hashing
        Date: 02/08/2015
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
//#define MAXN 1001
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

int n[2], m, t[2][1005], x;

void insert (int idx, int v) {
	if (t[idx][v%n[idx]] > -1) {
		int aux = t[idx][v%n[idx]];
		t[idx][v%n[idx]] = v;
		insert((idx+1)%2, aux);
	} else t[idx][v%n[idx]] = v;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j;
	
	while (cin>>n[0]>>n[1]>>m, n[0] || n[1] || m) {
		memset(t, -1, sizeof t);
		while (m--) {
			cin>>x;
			insert(0, x);
		}
		cout<<"Case "<<tc++<<":\n";
		for (i=0; i<2; i++) {
			bool empty = true;
			for (j=0; j<n[i]; j++) empty = empty && (t[i][j] == -1);
			if (!empty) {
				cout<<"Table "<<i+1<<"\n";
				for (j=0; j<n[i]; j++) if (t[i][j] > -1) cout<<j<<":"<<t[i][j]<<"\n";
			}
		}
	}
	
	return 0;
}
