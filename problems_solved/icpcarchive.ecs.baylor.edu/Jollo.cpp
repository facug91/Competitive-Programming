/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2815
        Name: Jollo
        Date: 18/10/2015
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

int princess[3], prince[2], p1[3], p2[3];

void solve () {
	int i, cnt;
	bool ok;
	for (i=1; i<=52; i++) {
		p1[0] = princess[0];
		p1[1] = princess[1];
		p1[2] = princess[2];
		p2[0] = prince[0];
		p2[1] = prince[1];
		p2[2] = i;
		if (i == princess[0] || i == princess[1] || i == princess[2]  || i == prince[0]  || i == prince[1]) continue;
		sort(p1, p1+3);
		ok = true;
		do {
			sort(p2, p2+3);
			do {
				cnt = (int)(p1[0] > p2[0]) + (int)(p1[1] > p2[1]) + (int)(p1[2] > p2[2]);
				if (cnt >= 2) ok = false;
			} while (next_permutation(p2, p2+3) && ok);
		} while (next_permutation(p1, p1+3) && ok);
		if (ok) {
			cout<<i<<endl;
			return;
		}
	}
	cout<<-1<<endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j, k;
	
	while (cin>>princess[0], princess[0]) {
		cin>>princess[1]>>princess[2]>>prince[0]>>prince[1];
		solve();
	}
	
	return 0;
}
