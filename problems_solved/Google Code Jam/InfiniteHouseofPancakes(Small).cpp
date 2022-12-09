/*
        By: facug91
        From: Google Code Jam - Qualification Round 2015 - Problem B Small
        Name: 
        Date: 11/04/2015
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

int d, aux, p[15], ans;

void search (int act, int ant) {
	if (act == 1) {
		ans = min(ans, ant+1);
		return;
	}
	if (p[act] == 0) {
		search(act-1, ant);
		return;
	}
	ans = min(ans, ant+act);
	int i = act-1, j = 1;
	while (i >= j) {
		p[i] += p[act];
		p[j] += p[act];
		search(act-1, ant+p[act]);
		p[i] -= p[act];
		p[j] -= p[act];
		i--; j++;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(10); cerr<<fixed<<setprecision(10); //cout.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		memset(p, 0, sizeof p);
		cin>>d;
		for (i=0; i<d; i++) {
			cin>>aux;
			p[aux]++;
		}
		ans = INT_MAX;
		search(10, 0);
		cout<<"Case #"<<it<<": "<<ans<<"\n";
		cerr<<"tc "<<it<<"\n";
	}
	
	return 0;
}
