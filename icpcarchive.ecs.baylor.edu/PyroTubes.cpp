/*
	By: facug91
	From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5379
	Name: Pyro Tubes
	Date: 10/05/2016
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
//#define MOD 1000000000ll
//#define MAXN 30015

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, m, ans[250005], a[250005];
bool in[300005];

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(2); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1;
	
	while (cin>>n) {
		memset(in, 0, sizeof in);
		memset(ans, 0, sizeof ans);
		m = 0;
		while (n != -1) {
			a[m++] = n;
			in[n] = true;
			cin>>n;
		}
		for (int i=0; i<m; i++) {
			for (int j=0; j<18; j++)
				if (in[a[i] ^ (1<<j)] && (a[i] ^ (1<<j)) > a[i]) ans[i]++;
			for (int j=0; j<18; j++) for (int k=j+1; k<18; k++) if (j != k)
				if (in[a[i] ^ (1<<j) ^ (1<<k)] && (a[i] ^ (1<<j) ^ (1<<k)) > a[i]) ans[i]++;
		}
		for (int i=0; i<m; i++) cout<<a[i]<<":"<<ans[i]<<endl;
	}
	
	return 0;
}
