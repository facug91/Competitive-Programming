/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=425
        Name: The Department of Redundancy Department
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

int n;
map<int, int> mp;
queue<int> q;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(10); cerr<<fixed<<setprecision(10); //cout.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	
	while (cin>>n) {
		if (mp.find(n) != mp.end()) mp[n]++;
		else {
			mp[n] = 1;
			q.push(n);
		}
	}
	while (q.size()) {
		cout<<q.front()<<" "<<mp[q.front()]<<"\n";
		q.pop();
	}
	
	return 0;
}
