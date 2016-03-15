/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2315
        Name: Newspaper
        Date: 14/03/2016
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
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, m, sum, val[520];
char c;
string line;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>n;
		memset(val, 0, sizeof val);
		for (i=0; i<n; i++) {
			cin>>c;
			cin>>val[c+128];
		}
		cin>>m;
		cin.ignore();
		sum = 0;
		while (m--) {
			getline(cin, line);
			for (i=0; i<line.length(); i++) sum += val[line[i]+128];
		}
		cout<<sum/100<<"."<<setfill('0')<<setw(2)<<sum%100<<"$"<<endl;
	}
	
	return 0;
}
