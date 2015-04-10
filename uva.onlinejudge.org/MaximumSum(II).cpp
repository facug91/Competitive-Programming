/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1597
        Name: Maximum Sum (II)
        Date: 06/04/2015
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

int n, x;
bool allzero, first;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	while (cin>>n, n) {
		allzero = first = true;
		while (n--) {
			cin>>x;
			if (x != 0) {
				allzero = false;
				if (first) first = false;
				else cout<<" ";
				cout<<x;
			}
		}
		if (allzero) cout<<"0\n";
		else cout<<"\n";
	}
	
	return 0;
}
