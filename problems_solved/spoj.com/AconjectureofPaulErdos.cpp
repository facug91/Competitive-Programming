/*
        By: facug91
        From: http://www.spoj.com/problems/HS08PAUL/
        Name: A conjecture of Paul Erdős
        Date: 19/11/2015
*/
 
#include <bits/stdc++.h>
#define y1		nd03dnqwuidg1odbnw9uddu0132d
#define clock	asoudh219udhjdgausdhs9udy433
#define left	dfgag34gsfaf342rf23fgwrf42ff
#define middle	lk78k6ujkj76kjk88kkummnhh456
#define right	apidwcojbl213f80sjb3y8efjfas
#define move	df53y5fgsf43fdsfsdtg4j6hfdg4
#define count	nkwdfj111afbjdfsbj32r8yfwejb
#define prev	asdnklgbgbjfasdbhksdva4t9jds
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) //cerr << " #" << (#x) << ": " << (x)
#define DBL(x) //cerr << " #" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10005
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<int, ii> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iii> viii; typedef vector<iiii> viiii;

int n, DP[10000010], x, y;
bool sieve[3200];
vi primes;

bool is_prime (int n) {
	int ip = 0, p = primes[ip];
	while (p*p <= n) {
		if (n % p == 0) return false;
		p = primes[++ip];
	}
	return true;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(4); //cerr<<fixed<<setprecision(4); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j, k;
	
	for (i=3; i<60; i+=2)
		if (!sieve[i])
			for (j=i*i; j<3200; j+=i+i)
				sieve[j] = true;
	primes.push_back(2);
	for (i=3; i<3200; i+=2) if (!sieve[i]) primes.push_back(i);
	memset(DP, 0, sizeof DP);
	for (x=1; x<=3163; x++) for (y=1; y<=57; y++) {
		i = x*x+y*y*y*y;
		if (i < 10000005 && is_prime(i)) DP[i] = 1;
	}
	for (i=1; i<10000005; i++) DP[i] += DP[i-1];
	cin>>tc;
	while (tc--) {
		cin>>n;
		cout<<DP[n]<<endl;
	}
	
	return 0;
}
