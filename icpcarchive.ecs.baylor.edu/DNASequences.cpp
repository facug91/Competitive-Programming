/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2214
        Name: DNA Sequences
        Date: 15/10/2015
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

int n, m, k, lss[1005][1005], lcs[1005][1005];
string s, t;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j, l;
	
	while (cin>>k, k) {
		cin>>s>>t;
		n = s.length() + 1;
		m = t.length() + 1;
		for (i=0; i<n; i++) lss[i][0] = 0;
		for (j=0; j<m; j++) lss[0][j] = 0;
		for (i=1; i<n; i++) for (j=1; j<m; j++) {
			if (s[i-1] == t[j-1]) lss[i][j] = lss[i-1][j-1] + 1;
			else lss[i][j] = 0;
		}
		for (i=0; i<n; i++) lcs[i][0] = 0;
		for (j=0; j<m; j++) lcs[0][j] = 0;
		for (i=1; i<n; i++) for (j=1; j<m; j++) {
			if (lss[i][j] >= k) {
				lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
				for (l=k; l<=lss[i][j]; l++) lcs[i][j] = max(lcs[i][j], lcs[i-l][j-l]+l);
			} else lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
		}
		cout<<lcs[n-1][m-1]<<endl;
	}
	
	return 0;
}
