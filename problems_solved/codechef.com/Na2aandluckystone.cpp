/*
        By: facug91
        From: http://www.codechef.com/JULY15/problems/LCKYST
        Name: Na2a and lucky stone
        Date: 04/07/2015
*/
 
#include <bits/stdc++.h>
#define EPS 1e-9
#define MP make_pair
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10000100
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

int n;
ll a, aux, five, two;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	
	cin>>n;
	for (int i=0; i<n; i++) {
		cin>>a;
		aux = a;
		five = two = 0ll;
		while (aux % 5 == 0) {
			aux /= 5;
			five++;
		}
		while (aux % 2 == 0) {
			aux /= 2;
			two++;
		}
		if (two < five)  {
			five -= two;
			five = five / 2ll + (five % 2ll);
			while (five--) a *= 4ll;
		}
		cout<<a<<"\n";
	}
	
	return 0;
}
