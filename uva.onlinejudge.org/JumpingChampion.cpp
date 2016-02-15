/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=855
        Name: Jumping Champion
        Date: 26/10/2015
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

int l, r, mx, cnt, ans;
bool sieve[1000100];
vi primes;
unordered_map<int, vii> difs;

bool cmp_first (const ii& a, const ii& b) {
	return a.first < b.first;
}

bool cmp_second (const ii& a, const ii& b) {
	return a.second < b.second;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j;
	
	for (i=3; i<1100; i++) if (!sieve[i])
		for (j=i*i; j<1000100; j+=i+i)
			sieve[j] = true;
	primes.push_back(2);
	for (i=3; i<1000100; i+=2) if (!sieve[i]) primes.push_back(i);
	for (i=1; i<primes.size(); i++) difs[primes[i]-primes[i-1]].push_back(ii(primes[i-1], primes[i]));
	cin>>tc;
	while (tc--) {
		cin>>l>>r;
		mx = -1; cnt = 0;
		for (pair<int, vii> d : difs) {
			auto itrl = lower_bound(d.second.begin(), d.second.end(), ii(l, 0), cmp_first);
			auto itrr = upper_bound(d.second.begin(), d.second.end(), ii(0, r), cmp_second);
			if (itrl == d.second.end() || itrr == d.second.begin()) continue;
			itrr--;
			int dis = distance(itrl, itrr);
			if (dis > mx) {
				mx = dis;
				cnt = 1;
				ans = d.first;
			} else if (dis == mx) cnt++;
		}
		if (cnt != 1) cout<<"No jumping champion"<<endl;
		else cout<<"The jumping champion is "<<ans<<endl; 
	}
	
	return 0;
}
