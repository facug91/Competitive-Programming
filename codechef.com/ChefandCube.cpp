/*
        By: facug91
        From: http://www.codechef.com/JULY15/problems/CHCUBE
        Name: Chef and Cube
        Date: 04/07/2015
*/
 
#include <bits/stdc++.h>
#define EPS 1e-9
#define MP make_pair
#define right ajkdg329hdb9g327gdy6tt
#define left ajkdg32fdsf9hdb9g327gd
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10000100
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

string front, back, left, right, top, bottom;

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>front>>back>>left>>right>>top>>bottom;
		bool ok = false;
		if ((front == bottom) && (front == left)) ok = true;
		if ((front == bottom) && (front == right)) ok = true;
		if ((front == top) && (front == left)) ok = true;
		if ((front == top) && (front == right)) ok = true;
		if ((back == top) && (back == left)) ok = true;
		if ((back == top) && (back == right)) ok = true;
		if ((back == bottom) && (back == left)) ok = true;
		if ((back == bottom) && (back == right)) ok = true;
		if (ok) cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}
