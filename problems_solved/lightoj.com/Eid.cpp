/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1024
	Name: Eid
	Date: 06/07/2016
*/

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define prev bjasdbi132ge79qwgdi
#define next usayhkdgisaydgiy212
#define move sdjifha978dyd9sag89
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
//#define MOD 100000007
//#define MAXN 10000005

using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, int> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; //insert, find_by_order, order_of_key, erase

int n, a[1005], sieve[10005], num[10005], size, factors[10005];

void factorize (int n) {
	//cerr<<"n "<<n<<endl;
	int p, c, pw;
	if (n < 2) return;
	while (sieve[n] != n) {
		p = sieve[n];
		pw = 1;
		while (sieve[n] % p == 0) {
			pw *= p;
			n /= p;
		}
		//cerr<<"n "<<n<<" p "<<p<<" pow "<<pw<<endl;
		factors[p] = max(factors[p], pw);
	}
	if (n > 1) factors[n] = max(factors[n], n);
}

void mul (int n) {
	//cerr<<"n "<<n<<endl;
	//cerr<<"num "; for (int i=0; i<size; i++) cerr<<num[i]; cerr<<endl;
	int carry = 0;
	for (int i=0; i<size; i++) {
		carry += n * num[i];
		num[i] = carry % 10;
		carry /= 10;
	}
	while (carry) {
		num[size++] = carry % 10;
		carry /= 10;
	}
	//cerr<<"num "; for (int i=0; i<size; i++) cerr<<num[i]; cerr<<endl;
}

int main () {
	//#ifdef ONLINE_JUDGE
	//	ios_base::sync_with_stdio(0); cin.tie(0);
	//#endif
	//cout<<fixed<<setprecision(9); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j;
	
	for (i=0; i<10005; i++) sieve[i] = i;
	for (i=2; i<105; i++) if (sieve[i] == i) 
		for (j=i; j<10005; j += i) sieve[j] = i;
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>n;
		for (i=0; i<n; i++) cin>>a[i];
		memset(factors, 0, sizeof factors);
		for (i=0; i<n; i++) factorize(a[i]);
		num[0] = 1;
		size = 1;
		for (i=0; i<10005; i++) if (factors[i] > 0) mul(factors[i]);
		cout<<"Case "<<it<<": ";
		for (i=size-1; i>=0; i--) cout<<num[i];
		cout<<endl;
	}
	
	return 0;
}
