/*
	By: facug91
	From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2217
	Name: Pole Position
	Date: 06/10/2015
*/

#include <bits/stdc++.h>
#define next 	asjkdbg1238dv8ydf38gy832gf8yd
#define prev 	jasdjksadjsadho32r80ejd8h3rsd
#define right 	nkdbj3dsbuhdfhu32rbhkdfhubj38
#define down 	pjasfias3dbasdgsauidb39dgsa92
#define EPS 1e-9
#define MP make_pair
#define DEB(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
#define MAXN 500

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

int n, a[1005], b[1005], c[1005];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j;
	
	while (cin>>n, n) {
		for (i=1; i<=n; i++) cin>>a[i]>>b[i];
		memset(c, -1, sizeof c);
		bool ok = true;
		for (i=1; i<=n; i++) {
			int p = i + b[i];
			if (p > 0 && p <= n && c[p] == -1) c[p] = a[i];
			else ok = false;
		}
		if (!ok) cout<<-1<<endl;
		else {
			cout<<c[1];
			for (i=2; i<=n; i++) cout<<" "<<c[i];
			cout<<endl;
		}
	}
	
	return 0;
}
