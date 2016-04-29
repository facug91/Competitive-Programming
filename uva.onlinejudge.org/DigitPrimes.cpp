/*
	By: facug91
	From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1474
	Name: Digit Primes
	Date: 12/02/2016
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define endl "\n"
#define DB(x) cerr << "#" << (#x) << ": " << (x) << " "
#define DBL(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10000100

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi; typedef vector<ii> vii;		   typedef vector<iii> viii;

int a, b, digit[1000005];
bool sieve[1000005];

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(4); cerr<<fixed<<setprecision(4); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j;
	
	for (i=0; i<1000005; i++) sieve[i] = i%2, digit[i] = 0;
	sieve[0] = false;
	sieve[1] = false;
	sieve[2] = true;
	digit[0] = 0;
	digit[1] = 0;
	digit[2] = 1;
	for (i=3; i<1005; i+=2) {
		if (sieve[i]) {
			for (j=i*i; j<1000005; j+=i+i) sieve[j] = false;
			int sum = 0, aux = i;
			while (aux) {
				sum += (aux%10);
				aux /= 10;
			}
			if (sieve[sum]) digit[i] = 1;
			else digit[i] = 0;
		}
	}
	for (i=1005; i<1000005; i+=2) {
		if (sieve[i]) {
			int sum = 0, aux = i;
			while (aux) {
				sum += (aux%10);
				aux /= 10;
			}
			if (sieve[sum]) digit[i] = 1;
			else digit[i] = 0;
		}
	}
	for (i=1; i<1000005; i++) digit[i] += digit[i-1];
	cin>>tc;
	while (tc--) {
		cin>>a>>b;
		cout<<digit[b]-digit[a-1]<<endl;
	}
	
	return 0;
}
