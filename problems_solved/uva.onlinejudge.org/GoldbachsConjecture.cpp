/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=484
        Name: Goldbach's Conjecture
        Date: 21/10/2015
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
#define MAXN 10005
#define LOGN 14

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<int, ii> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iii> viii; typedef vector<iiii> viiii;

int n;
bool sieve[1000005];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j, k;
	
	for (i=0; i<1000005; i++) sieve[i] = true;
	sieve[0] = sieve[1] = false;
	for (i=4; i<1000005; i+=2) sieve[i] = false;
	for (i=3; i<1005; i++)
		if (sieve[i])
			for (j=i*i; j<1000005; j+=i+i)
				sieve[j] = false;
	while (cin>>n, n) {
		int a = 2;
		while (!sieve[a] || !sieve[n-a]) a++;
		cout<<n<<" = "<<a<<" + "<<n-a<<endl;
	}
	
	return 0;
}
