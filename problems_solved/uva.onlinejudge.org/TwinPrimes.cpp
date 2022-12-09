/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1335
        Name: Twin Primes
        Date: 23/10/2015
*/
 
#include <bits/stdc++.h>
#define endl "\n"
#define EPS 1e-9
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

int s, a, b;
bool sieve[20000005];
vii ans;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j;
	
	for (i=0; i<20000005; i++) sieve[i] = true;
	sieve[0] = sieve[1] = false;
	for (i=4; i<20000005; i+=2) sieve[i] = false;
	int sq = sqrt(20000005)+1;
	for (i=3; i<sq; i+=2)
		if (sieve[i])
			for (j=i*i; j<20000005; j+=i+i)
				sieve[j] = false;
	a = 3; b = 5;
	while (b < 20000005) {
		if (sieve[a] && sieve[b]) ans.emplace_back(a, b);
		a += 2;
		b += 2;
	}
	while (cin>>s) {
		s--;
		cout<<"("<<ans[s].F<<", "<<ans[s].S<<")"<<endl;
	}
	
	return 0;
}
