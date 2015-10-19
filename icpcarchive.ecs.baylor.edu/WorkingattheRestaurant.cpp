/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2506
        Name: Working at the Restaurant
        Date: 09/08/2015
*/
 
#include <bits/stdc++.h>
#define y1 		nd03dnqwuidg1odbnw9uddu0132d
#define clock 	asoudh219udhjdgausdhs9udy433
#define left	dfgag34gsfaf342rf23fgwrf42ff
#define middle	lk78k6ujkj76kjk88kkummnhh456
#define right	apidwcojbl213f80sjb3y8efjfas
#define EPS 1e-9
#define MP make_pair
#define DEB(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 4294967296ll
#define MAXN 1001
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

int n, m, pile1, pile2;
string op;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j;
	
	bool first = true;
	while (cin>>n, n) {
		if (first) first = false;
		else cout<<"\n";
		pile1 = pile2 = 0;
		for (i=0; i<n; i++) {
			cin>>op>>m;
			if (op[0] == 'D') {
				cout<<"DROP 1 "<<m<<"\n";
				pile1 += m;
			} else {
				if (pile2 == 0) {
					cout<<"MOVE 1->2 "<<pile1<<"\n";
					pile2 = pile1;
					pile1 = 0;
					cout<<"TAKE 2 "<<m<<"\n";
					pile2 -= m;
				} else if (pile2 < m) {
					cout<<"TAKE 2 "<<pile2<<"\n";
					m -= pile2;
					cout<<"MOVE 1->2 "<<pile1<<"\n";
					pile2 = pile1;
					pile1 = 0;
					cout<<"TAKE 2 "<<m<<"\n";
					pile2 -= m;
				} else {
					cout<<"TAKE 2 "<<m<<"\n";
					pile2 -= m;
				}
			}
		}
	}
	
	return 0;
}
