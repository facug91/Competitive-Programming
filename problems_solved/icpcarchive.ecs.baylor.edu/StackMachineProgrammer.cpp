/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=526&page=show_problem&problem=3894
        Name: Stack Machine Programmer
        Date: 01/08/2015
*/
 
#include <bits/stdc++.h>
#define y1 nd03dnqwuidg1odbnw9uddu0132d
#define clock asoudh219udhjdgausdhs9udy
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

int n;
ii inout[5];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j;
	
	while (cin>>n, n) {
		for (i=0; i<n; i++) {
			cin>>inout[i].first>>inout[i].second;
			inout[i].first++;
		}
		cout<<"NUM 1\n";
		cout<<"ADD\n";
		sort(inout, inout+n, greater<ii>());
		for (i=0; i<n; i++) {
			cout<<"DUP\n";
			for (j=0; j<i; j++) {
				cout<<"NUM "<<inout[j].first<<"\n";
				cout<<"MOD\n";
			}
			cout<<"NUM "<<inout[i].first<<"\n";
			cout<<"DIV\n";
			cout<<"NUM "<<inout[i].second<<"\n";
			cout<<"MUL\n";
			cout<<"SWP\n";
		}
		cout<<"POP\n";
		for (i=0; i<n-1; i++) cout<<"ADD\n";
		cout<<"END\n\n";
	}
	
	return 0;
}
