/*
        By: facug91
        From: http://www.spoj.com/problems/SOCIALNE/
        Name: Possible Friends
        Date: 19/11/2015
*/
 
#include <bits/stdc++.h>
#define y1		nd03dnqwuidg1odbnw9uddu0132d
#define clock	asoudh219udhjdgausdhs9udy433
#define left	dfgag34gsfaf342rf23fgwrf42ff
#define middle	lk78k6ujkj76kjk88kkummnhh456
#define right	apidwcojbl213f80sjb3y8efjfas
#define move	df53y5fgsf43fdsfsdtg4j6hfdg4
#define count	nkwdfj111afbjdfsbj32r8yfwejb
#define prev	asdnklgbgbjfasdbhksdva4t9jds
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) //cerr << " #" << (#x) << ": " << (x)
#define DBL(x) //cerr << " #" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10005
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<int, ii> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iii> viii; typedef vector<iiii> viiii;

int n, m, u, mx, idx;
string mat[55];
queue<int> q;
bool vis[55];

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(4); //cerr<<fixed<<setprecision(4); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j, k;
	
	cin>>tc;
	while (tc--) {
		cin>>mat[0];
		n = mat[0].length();
		for (i=1; i<n; i++) cin>>mat[i];
		mx = 0; idx = 0;
		for (i=0; i<n; i++) {
			while (q.size()) q.pop();
			memset(vis, 0, sizeof vis);
			m = 0;
			vis[i] = true;
			for (j=0; j<n; j++) if (mat[i][j] == 'Y') {
				q.push(j);
				vis[j] = true;
				m++;
			}
			while (m--) {
				u = q.front(); q.pop();
				for (j=0; j<n; j++) if (mat[u][j] == 'Y' && !vis[j]) {
					q.push(j);
					vis[j] = true;
				}
			}
			if (q.size() > mx) {
				mx = q.size();
				idx = i;
			}
		}
		cout<<idx<<" "<<mx<<endl;
	}
	
	return 0;
}
