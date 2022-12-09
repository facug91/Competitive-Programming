/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3778
        Name: Army Buddies
        Date: 25/12/2015
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

int l[100005], r[100005], s, b, p, q;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j, k;
	
	while (cin>>s>>b, s || b) {
		l[1] = -1;
		for (i=2; i<=s; i++) l[i] = i-1;
		r[s] = -1;
		for (i=s-1; i>=1; i--) r[i] = i+1;
		while (b--) {
			cin>>p>>q;
			if (l[p] == -1) cout<<"*";
			else cout<<l[p];
			cout<<" ";
			if (r[q] == -1) cout<<"*";
			else cout<<r[q];
			cout<<endl;
			if (l[p] == -1) {
				if (r[q] == -1) continue;
				else l[r[q]] = -1;
			} else {
				if (r[q] == -1) r[l[p]] = -1;
				else {
					r[l[p]] = r[q];
					l[r[q]] = l[p];
				}
			}
		}
		cout<<"-"<<endl;
	}
	
	return 0;
}
