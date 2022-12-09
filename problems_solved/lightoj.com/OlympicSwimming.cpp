/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1423
        Name: Olympic Swimming
        Date: 22/09/2015
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
//#define MOD 4294967296ll
//#define MAXN 10005
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int l, k, n, p, a[35][50005], ans;
map<llu, int> prev;
llu hashNumber, power;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j, tc;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		memset(a, 0, sizeof a);
		cin>>l>>k;
		for (i=0; i<k; i++) {
			cin>>n;
			for (j=0; j<n; j++) {
				 cin>>p;
				 a[i][p]++;
			}
			for (j=1; j<l; j++) a[i][j] += a[i][j-1];
		}
		prev.clear();
		hashNumber = 0llu; power = 1llu;
		for (j=0; j<k; j++) {
			hashNumber += power;
			power *= 5003llu;
		}
		prev[hashNumber] = -1;
		ans = 0;
		for (i=0; i<l; i++) {
			p = INT_MAX; 
			for (j=0; j<k; j++) p = min(p, a[j][i]);
			hashNumber = 0llu; power = 1llu;
			for (j=0; j<k; j++) {
				hashNumber += ((a[j][i]-p+1llu)*power);
				power *= 5003llu;
			}
			if (prev.find(hashNumber) != prev.end()) {
				ans = max(ans, i-prev[hashNumber]);
			} else prev[hashNumber] = i;
		}
		cout<<"Case "<<it<<": "<<ans<<" meter(s)"<<endl;
	}
	
	return 0;
}
