/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=353
        Name: Pi
        Date: 24/10/2015
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
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10005
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<int, ii> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iii> viii; typedef vector<iiii> viiii;

int n, a[55], cnt;

int gcd (int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout<<fixed<<setprecision(6); cerr<<fixed<<setprecision(6); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j;
	
	while (cin>>n, n) {
		for (i=0; i<n; i++) cin>>a[i];
		cnt = 0;
		for (i=0; i<n; i++) for (j=i+1; j<n; j++) if (gcd(a[i], a[j]) == 1) cnt++;
		if (cnt == 0) cout<<"No estimate for this data set."<<endl;
		else cout<<sqrt((double)((n*(n-1.0)/2.0)*6.0)/(double)cnt)<<endl;
	}
	
	return 0;
}
