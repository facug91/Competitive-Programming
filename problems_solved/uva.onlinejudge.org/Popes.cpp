/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=898
        Name: Popes
        Date: 02/04/2015
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

int y, p, l[100005], first, last, cant;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int i, j;
	
	while (cin>>y) {
		cin>>p;
		for (i=0; i<p; i++) cin>>l[i];
		i=0; j=0; cant = 0;
		while (i < p) {
			while (j < p-1 && l[j+1]-l[i] < y) j++;
			if (cant < j-i+1) {
				cant = j-i+1;
				first = l[i]; last = l[j];
			}
			i++; if (i > j) j = i;
		}
		cout<<cant<<" "<<first<<" "<<last<<"\n";
	}
	
	return 0;
}
