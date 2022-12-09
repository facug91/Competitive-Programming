/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1889
        Name: The primary problem
        Date: 23/10/2015
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
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 1000000007ll
#define MAXN 1000005
#define SQMAXN 1005
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<int, ii> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iii> viii; typedef vector<iiii> viiii;

int n, ip, p;
bool sieve[1000005];
vi primes;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j;
	
	for (i=0; i<MAXN; i++) sieve[i] = true;
	for (i=4; i<MAXN; i+=2) sieve[i] = false;
	for (i=3; i<SQMAXN; i+=2) if (sieve[i])
		for (j=i*i; j<MAXN; j+=i+i)
			sieve[j] = false;
	primes.push_back(2);
	for (i=3; i<MAXN/2; i+=2) if (sieve[i]) primes.push_back(i);
	while (cin>>n, n) {
		cout<<n<<":"<<endl;
		if (n % 2 == 1) {
			if (sieve[n-2]) cout<<2<<"+"<<n-2<<endl;
			else cout<<"NO WAY!"<<endl;
		} else {
			ip = 0;
			p = primes[ip];
			while (!sieve[p] || !sieve[n-p]) p = primes[++ip];
			cout<<p<<"+"<<n-p<<endl;
		}
	}
	
	return 0;
}
