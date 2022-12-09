/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2403
        Name: Count DePrimes
        Date: 26/02/2016
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
#define MOD 1000000007ll
#define MAXN 5000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int a, b, sieve[MAXN], RSQ[MAXN];

bool isDePrime (int n) {
	int sum = 0, factor;
	while (n != 1) {
		factor = sieve[n];
		sum += factor;
		while (n % factor == 0) n /= factor;
	}
	return sieve[sum] == sum;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	for (i=2; i<MAXN; i+=2) sieve[i] = 2;
	for (i=1; i<MAXN; i+=2) sieve[i] = i;
	for (i=3; i<10000; i+=2)
		if (sieve[i] == i) {
			for (j=i*i; j<MAXN; j+=i+i)
				sieve[j] = i;
		}
	RSQ[1] = 0;
	for (i=2; i<MAXN; i++) 
		if (isDePrime(i)) RSQ[i] = RSQ[i-1] + 1;
		else RSQ[i] = RSQ[i-1];
	while (cin>>a, a) {
		cin>>b;
		cout<<RSQ[b]-RSQ[a-1]<<endl;
	}
	
	return 0;
}
