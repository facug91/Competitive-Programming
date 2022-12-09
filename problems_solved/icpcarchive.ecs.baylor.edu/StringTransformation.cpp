/*
	By: facug91
	From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4913
	Name: String Transformation
	Date: 28/04/2016
*/

#include <bits/stdc++.h>
#define endl "\n"
#define next sbjkdfh329re9fdshfd98fyh
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

int idx[2], ans;
string a, b;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(2); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>a>>b;
		for (i=0; i<2; i++) {
			idx[i] = b.length()-1;
			while (a[idx[i]] != 'a'+i) idx[i]--;
		}
		ans = 0;
		for (i=b.length()-1; i>=0; i--) {
			//cerr<<"i "<<i<<" ans "<<ans<<endl;
			int curr = b[i]-'a';
			if (a[i] != b[i] || i == idx[(a[i]-'a')^1]) {
				ans += (i - idx[curr]);
				if (idx[curr] < idx[curr^1]) idx[curr^1]--;
				a[idx[curr]] = 'a'+(curr^1);
				idx[curr]--;
				while (idx[curr] >= 0 && a[idx[curr]] != 'a'+curr) idx[curr]--;
			} else {
				for (j=0; j<2; j++) {
					if (idx[j] == i) {
						idx[j]--;
						while (idx[curr] >= 0 && a[idx[j]] != 'a'+j) idx[j]--;
					}
				}
			}
			//cerr<<"idx[0] "<<idx[0]<<" idx[1] "<<idx[1]<<endl;
			//cerr<<"i "<<i<<" ans "<<ans<<endl;
			//cerr<<endl;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
