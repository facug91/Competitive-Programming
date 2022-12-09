/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=3227
        Name: Divide or Conquer
        Date: 04/04/2015
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

int n, f, s;
ll x;
multiset<ll> seq;
multiset<ll>::iterator ant, act, sig;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		cin>>n;
		seq.clear();
		for (i=0; i<n; i++) cin>>x, seq.insert(x);
		if (n > 1) {
			act = seq.begin();
			ant = act++;
			while (act != seq.end()) {
				if (*ant == *act) {
					x = *ant + *act;
					sig = act; sig++;
					seq.erase(ant);
					seq.erase(act);
					seq.insert(x);
					if (sig == seq.end() || seq.size() == 1) act = seq.end();
					else if (sig == seq.begin()) {
						act = sig;
						ant = act++;
					} else {
						ant = sig;
						act = ant--;
					}
				} else {
					ant++;
					act++;
				}
			}
		}
		act = seq.end(); act--;
		cout<<(*act)<<"\n";
	}
	
	return 0;
}
