/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1647
        Name: Number Sequence
        Date: 31/03/2015
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

ll n;
vector<ll> seq, dig;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int TC;
	
	ll act = 10ll, d = 1ll, i;
	seq.push_back(0ll); dig.push_back(0ll);
	for (i=1; seq[i-1]<=3000000000ll; i++) {
		if (i == act) {
			act *= 10ll;
			d++;
		}
		seq.push_back(seq[i-1]+dig[i-1]+d);
		dig.push_back(dig[i-1] + d);
	}
	cin>>TC;
	while (TC--) {
		cin>>n;
		vector<ll>::iterator itr = lower_bound(seq.begin(), seq.end(), n);
		n -= (*(--itr));
		act = 10ll, d = 1ll, i = 1ll;
		while (true) {
			if (i == act) {
				act *= 10ll;
				d++;
			}
			if (n > d) n -= d;
			else {
				string aux = "";
				while (i) {
					aux += ((i%10ll)+'0');
					i /= 10ll;
				}
				int j;
				for (j=aux.length()-1; n != 1; j--, n--);
				n = aux[j]-'0';
				break;
			}
			i++;
		}
		cout<<n<<"\n";
	}
	
	return 0;
}
