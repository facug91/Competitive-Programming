/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=347
        Name: Prime Cuts
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

int n, c, nop[2000], from, to;
bool sieve[2000];

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j;
	
	for (i=0; i<2000; i++) sieve[i] = true;
	sieve[0] = false;
	for (i=4; i<2000; i+=2) sieve[i] = false;
	for (i=3; i<500; i+=2)
		if (sieve[i])
			for (j=i*i; j<2000; j+=i+i)
				sieve[j] = false;
	nop[0] = 0;
	for (i=1; i<2000; i++) nop[i] = nop[i-1] + sieve[i];
	while (cin>>n>>c) {
		cout<<n<<" "<<c<<":";
		if (nop[n] % 2 == 0) c = c*2;
		else c = c*2-1;
		if (nop[n] >= c) {
			from = -(nop[n]-c)/2;
			to = c;
		} else {
			from = 0;
			to = nop[n];
		}
		i = 0;
		while (from < to) {
			if (sieve[i]) {
				from++;
				if (from > 0) cout<<" "<<i;
			}
			i++;
		}
		cout<<endl<<endl;
	}
	
	return 0;
}
