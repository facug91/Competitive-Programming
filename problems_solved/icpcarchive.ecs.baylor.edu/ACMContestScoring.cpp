/*
	By: facug91
	From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5372
	Name: ACM Contest Scoring
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

int m, t[300], np, nt;
bool solved[300];
char p;
string v;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(2); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1;
	
	while (cin>>m) {
		memset(t, 0, sizeof t);
		memset(solved, 0, sizeof solved);
		np = nt = 0;
		while (m != -1) {
			cin>>p>>v;
			if (!solved[p]) {
				if (v[0] == 'r') {
					solved[p] = true;
					np++;
					nt += m + t[p];
				} else {
					t[p] += 20;
				}
			}
			cin>>m;
		}
		cout<<np<<" "<<nt<<endl;
	}
	
	return 0;
}
