/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2454
        Name: Snakes and Ladders
        Date: 31/12/2015
*/

#include <bits/stdc++.h>
#define endl "\n"
#define EPS 1e-2
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
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int a, b, c, place[105], player[1000005], mov[1000005], s, t;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j;
	
	cin>>tc;
	while (tc--) {
		memset(place, -1, sizeof place);
		cin>>a>>b>>c;
		for (i=0; i<b; i++) {
			cin>>s>>t;
			place[s] = t;
		}
		for (i=0; i<c; i++) cin>>mov[i];
		for (i=0; i<a; i++) player[i] = 1;
		for (i=0; i<c; i++) {
			player[i%a] += mov[i];
			if (player[i%a] >= 100) break;
			if (place[player[i%a]] != -1) player[i%a] = place[player[i%a]];
			if (player[i%a] >= 100) break;
		}
		for (i=0; i<a; i++) cout<<"Position of player "<<i+1<<" is "<<player[i]<<"."<<endl;
	}
	
	return 0;
}
