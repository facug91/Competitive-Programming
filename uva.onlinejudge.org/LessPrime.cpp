/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1793
        Name: Less Prime
        Date: 24/10/2015
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
//#define MAXN 1000005
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<int, ii> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iii> viii; typedef vector<iiii> viiii;

int n, x, p, ip, pr, m;
bool sieve[20020], first;
vi primes;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	for (i=3; i<20020; i+=2) sieve[i] = true;
	for (i=3; i<150; i+=2) if (sieve[i])
		for (j=i*i; j<20020; j+=i+i)
			sieve[j] = false;
	primes.push_back(2);
	for (i=3; i<20020; i+=2) if (sieve[i]) primes.push_back(i);
	cin>>tc;
	while (tc--) {
		cin>>n;
		ip = 0, pr = primes[ip], m;
		first = true;
		while (pr <= n) {
			m = n / pr;
			if (pr * m <= n && n < pr * (m+1)) {
				if (first) {
					first = false;
					x = pr;
					p = m;
				} else if (n - (p * x) < n - (m * pr)) {
					x = pr;
					p = m;
				}
			}
			pr = primes[++ip];
		}
		cout<<x<<endl;
	}
	
	return 0;
}
