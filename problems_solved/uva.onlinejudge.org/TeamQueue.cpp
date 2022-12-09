/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=481
        Name: Team Queue
        Date: 13/04/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int t, team[1000005], n, m;
queue<int> q, qt[1005];
string op;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(4); cerr<<fixed<<setprecision(10); //cout.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j;
	
	while (cin>>t, t) {
		cout<<"Scenario #"<<tc++<<"\n";
		for (i=0; i<t; i++) {
			cin>>n;
			for (j=0; j<n; j++) {
				cin>>m;
				team[m] = i;
			}
		}
		while (cin>>op, op[0] != 'S') {
			if (op[0] == 'E') {
				cin>>m;
				if (qt[team[m]].size()) qt[team[m]].push(m);
				else {
					qt[team[m]].push(m);
					q.push(team[m]);
				}
			} else {
				cout<<qt[q.front()].front()<<"\n";
				qt[q.front()].pop();
				if (qt[q.front()].size() == 0) q.pop();
			}
		}
		while (q.size()) q.pop();
		for (i=0; i<t; i++) while (qt[i].size()) qt[i].pop();
		cout<<"\n";
	}
	
	return 0;
}
