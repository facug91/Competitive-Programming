/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1591
        Name: Determinate Prime
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

int x, y, d, ip;
vector<vi> ans;
vi aux;
bool sieve[35000];
vi primes;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	for (i=3; i<35000; i+=2) sieve[i] = true;
	for (i=3; i<200; i+=2) if (sieve[i])
		for (j=i*i; j<35000; j+=i+i)
			sieve[j] = false;
	primes.push_back(-1);
	primes.push_back(2);
	for (i=3; i<35000; i+=2) if (sieve[i]) primes.push_back(i);
	
	d = primes[2] - primes[1];
	ip = 3;
	while (ip < primes.size()) {
		if (d != primes[ip]-primes[ip-1]) {
			i = ip-1;
			aux.clear();
			aux.push_back(primes[i]);
			i--;
			aux.push_back(primes[i]);
			while (primes[i+1]-primes[i] == primes[i]-primes[i-1]) {
				i--;
				aux.push_back(primes[i]);
			}
			reverse(aux.begin(), aux.end());
			if (aux.size() > 2) ans.push_back(aux);
			d = primes[ip]-primes[ip-1];
		}
		ip++;
	}
	
	while (cin>>x>>y, x || y) {
		if (x > y) swap(x, y);
		for (auto a : ans) if (x <= a.front() && a.back() <= y) {
			cout<<a.front();
			for (i=1; i<a.size(); i++) cout<<" "<<a[i];
			cout<<endl;
		}
	}
	
	return 0;
}
