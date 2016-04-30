/*
	By: facug91
	From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3905
	Name: Lightning Lessons
	Date: 29/04/2016
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

int n, a[2][25], z, f, s;

bool finish () {
	for (int i=0; i<n-1; i++) if (a[f][i] != 0) return false;
	return true;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(2); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>n;
		for (i=0; i<n; i++) cin>>a[0][i];
		z = 0;
		f = 0; s = 1;
		while (!finish()) {
			for (i=0; i<=z; i++) a[s][i] = 0;
			for (i=z+1; i<n; i++) 
				a[s][i] = a[f][i] - a[f][i-1];
			z++;
			swap(f, s);
		}
		if (a[f][n-1] == 0) {
			for (i=0; i<z; i++) cout<<'z';
			cout<<"ap!"<<endl;
		} else if (a[f][n-1] > 0) cout<<"*fizzle*"<<endl;
		else cout<<"*bunny*"<<endl;
	}
	
	return 0;
}
