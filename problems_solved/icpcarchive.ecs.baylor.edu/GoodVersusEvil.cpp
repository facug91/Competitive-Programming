/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4235
        Name: Good Versus Evil
        Date: 06/08/2015
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

int good[6] = {1, 2, 3, 3, 4, 10}, bad[7] = {1, 2, 2, 2, 3, 5, 10}, c, ansg, ansb;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j, k;
	
	cin>>tc;
	for (i=1; i<=tc; i++) {
		ansg = 0;
		for (j=0; j<6; j++) {
			cin>>c;
			ansg += (c * good[j]);
		}
		ansb = 0;
		for (j=0; j<7; j++) {
			cin>>c;
			ansb += (c * bad[j]);
		}
		if (ansg < ansb) cout<<"Battle "<<i<<": Evil eradicates all trace of Good\n";
		else if (ansg > ansb) cout<<"Battle "<<i<<": Good triumphs over Evil\n";
		else cout<<"Battle "<<i<<": No victor on this battle field\n";
	}
	
	return 0;
}
