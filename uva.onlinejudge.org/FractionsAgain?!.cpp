/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1917
        Name: Fractions Again?!
        Date: 10/04/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int k, num, den, sim;
vector<iii> ans;

int gcd (int a, int b) {
	if (a == 0) return b;
	return gcd(b%a, a);
}

int lcm (int a, int b) {
	return (a * b) / gcd(a, b);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(10); cerr<<fixed<<setprecision(10); //cout.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	
	while (cin>>k) {
		ans.clear();
		for (int i=k+1; i<=k*2; i++) {
			den = lcm(k, i);
			num = (den/k)-(den/i);
			sim = gcd(num, den);
			num /= sim;
			den /= sim;
			if (num == 1) ans.push_back(iii(k, ii(den, i)));
		}
		cout<<ans.size()<<"\n";
		for (int i=0; i<ans.size(); i++) cout<<"1/"<<ans[i].first<<" = 1/"<<ans[i].second.first<<" + 1/"<<ans[i].second.second<<"\n";
	}
	
	return 0;
}
