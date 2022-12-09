/*
	By: facug91
	From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4244
	Name: Temple Build
	Date: 28/04/2016
*/

#include <bits/stdc++.h>
#define endl "\n"
#define next sbjkdfh329re9fdshfd98fyh
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
//#define MOD 1000000007ll
#define MAXN 100000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

ll height, bottom, top, cubic[3], DP[1000005];

ll dp (int h) {
	if (DP[h] != -1ll) return DP[h];
	ll haux, vol, ans = 0, cubes;
	for (int i=0; i<3; i++) {
		haux = h + cubic[i];
		if (haux <= height) {
			ll baseAux = (ll)floor(bottom - haux * (bottom-top) / (double)(height));
			cubes = baseAux / cubic[i];
			vol = cubes * cubic[i] * cubes * cubic[i] * cubic[i];
			//cerr<<"h "<<h<<" haux "<<haux<<" vol "<<vol<<" cubes "<<cubes<<endl;
			ans = max(ans, dp(haux) + vol);
		}
	}
	return DP[h] = ans;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(2); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	while (cin>>height>>bottom>>top>>cubic[0]>>cubic[1]>>cubic[2]) {
		for (i=0; i<=height; i++) DP[i] = -1;
		cout<<dp(0)<<endl;
	}
	
	return 0;
}
