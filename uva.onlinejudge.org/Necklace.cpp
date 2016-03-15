/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1942
        Name: Necklace
        Date: 07/03/2016
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
#define MOD 1000000007ll
#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int ans, cnt;
double vt, v0, v, len;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	while (cin>>vt>>v0, vt || v0) {
		len = -1.0;
		cnt = 0;
		i = 1;
		v = vt;
		while (v > v0) {
			double dim = 0.3*sqrt((double)v-v0);
			if (fabs(dim*i - len) < EPS) cnt++;
			else if (dim*i > len) {
				len = dim*i;
				cnt = 1;
				ans = i;
			}
			cerr<<"i "<<i<<" v "<<v<<" dim "<<dim<<" ans "<<ans<<" cnt "<<cnt<<" len "<<len<<endl;
			i++;
			v = vt / i;
		}
		if (cnt == 1) cout<<ans<<endl;
		else cout<<0<<endl;
	}
	
	return 0;
}
