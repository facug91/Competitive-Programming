/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5247
        Name: 3-Primes Problem
        Date: 14/04/2016
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
//#define MOD 1000000007ll
#define MAXN 100000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int k;
bool sieve[1005];
vector<int> ans;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	for (i=0; i<1005; i++) sieve[i] = true;
	for (i=4; i<1005; i+=2) sieve[i] = false;
	for (i=3; i<35; i+=2)
		if (sieve[i])
			for (j=i*i; j<1005; j+=i+i)
				sieve[j] = false;
	cin>>tc;
	while (tc--) {
		cin>>k;
		ans.clear();
		if (k % 2 == 0) {
			k -= 2;
			ans.push_back(2);
		} else {
			k -= 3;
			ans.push_back(3);
		}
		i = 2;
		while (!sieve[k-i] || !sieve[i]) i++;
		ans.push_back(i);
		ans.push_back(k-i);
		sort(ans.begin(), ans.end());
		cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
	}
	
	return 0;
}
