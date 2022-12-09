/*
        By: facug91
        From: Google Code Jam - Qualification Round 2015 - Problem D Small
        Name: Ominous Omino
        Date: 11/04/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int x, r, c, s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(10); cerr<<fixed<<setprecision(10); //cout.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>x>>r>>c;
		if (r > c) swap(r, c);
		if (x == 1) cout<<"Case #"<<it<<": GABRIEL\n";
		else if (x == 2) {
			if ((r*c) % 2 == 1) cout<<"Case #"<<it<<": RICHARD\n";
			else cout<<"Case #"<<it<<": GABRIEL\n";
		} else if (x == 3) {
			if ((c < 3) || (((r*c) % x) != 0) || (r < 2)) cout<<"Case #"<<it<<": RICHARD\n";
			else cout<<"Case #"<<it<<": GABRIEL\n";
		} else { //x == 4
			if ((r == 3 && c == 4) || (r == 4 && c == 4)) cout<<"Case #"<<it<<": GABRIEL\n";
			else cout<<"Case #"<<it<<": RICHARD\n";
		}
	}
	
	return 0;
}
