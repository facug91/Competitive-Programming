/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2344
        Name: Encountering the Medal Table
        Date: 10/04/2015
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
typedef unsigned long long ull;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int g, s, b;
vector<pair<iii, string> > c;
string n;

struct cmp {
	bool operator() (const pair<iii, string> &a, const pair<iii, string> &b) {
		if (a.first.first == b.first.first) {
			if (a.first.second.first == b.first.second.first) {
				if (a.first.second.second == b.first.second.second) {
					return a.second.compare(b.second) < 0;
				} else return a.first.second.second > b.first.second.second;
			} else return a.first.second.first > b.first.second.first;
		} else return a.first.first > b.first.first;
	}
};

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(10); cerr<<fixed<<setprecision(10); //cout.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	bool first = true;
	
	cin>>n;
	while (n[0] != '#') {
		if (first) first = false;
		else cout<<"@\n";
		c.clear();
		while (n[0] != '@' && n[0] != '#') {
			cin>>g>>s>>b;
			c.push_back(make_pair(iii(g, ii(s, b)), n));
			cin>>n;
		}
		sort(c.begin(), c.end(), cmp());
		for (int i=0; i<c.size(); i++) cout<<c[i].second<<"\n";
		if (n[0] != '#') cin>>n;
	}
	
	return 0;
}
