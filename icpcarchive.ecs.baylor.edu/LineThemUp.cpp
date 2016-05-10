/*
	By: facug91
	From: https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&Itemid=99999999&category=706&page=show_problem&problem=5377
	Name: Line Them Up
	Date: 10/05/2016
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
//#define MOD 1000000000ll
//#define MAXN 30015

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n;
string s[30];

bool incresing () {
	for (int i=1; i<n; i++) if (s[i-1] > s[i]) return false;
	return true;
}

bool decresing () {
	for (int i=1; i<n; i++) if (s[i-1] < s[i]) return false;
	return true;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(2); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1;
	
	while (cin>>n) {
		for (int i=0; i<n; i++) cin>>s[i];
		if (incresing()) cout<<"INCREASING"<<endl;
		else if (decresing()) cout<<"DECREASING"<<endl;
		else cout<<"NEITHER"<<endl;
	}
	
	return 0;
}
