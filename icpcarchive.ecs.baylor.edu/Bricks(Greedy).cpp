/*
	By: facug91
	From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4947
	Name: Bricks
	Date: 25/02/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, k, ratio[2], act[2], ans, r;
char c;
ii seq[100005];
 
int main () {
	ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j;
       
	cin>>TC;
	while (TC--) {
		cin>>n;
		ratio[0] = ratio[1] = 0;
		for (i=0; i<n; i++) {
			cin>>k>>c;
			seq[i].first = k;
			seq[i].second = ((c == 'B')?0:1);
			ratio[seq[i].second] += seq[i].first;
		}
		if (ratio[0] == 0 || ratio[1] == 0) cout<<max(ratio[0], ratio[1])<<endl;
		else {
			int gcd = __gcd(ratio[0], ratio[1]);
			ratio[0] /= gcd; ratio[1] /= gcd;
			act[0] = act[1] = ans = 0;
			for (i=0; i<n; i++) {
				if (act[seq[i].second^1] != 0 && act[seq[i].second^1] % ratio[seq[i].second^1] == 0) {
					r = act[seq[i].second^1] / ratio[seq[i].second^1] * ratio[seq[i].second];
					if (r <= act[seq[i].second] + seq[i].first && r > act[seq[i].second]) {
						act[seq[i].second^1] = 0;
						act[seq[i].second] = seq[i].first - (r - act[seq[i].second]);
						ans++;
					} else act[seq[i].second] += seq[i].first;
				} else act[seq[i].second] += seq[i].first;
			}
			cout<<ans<<endl;
		}
	}
       
	return 0;
}
