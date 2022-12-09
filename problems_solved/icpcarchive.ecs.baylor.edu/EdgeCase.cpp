/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4281
        Name: Edge Case
        Date: 23/07/2015
*/
 
#include <bits/stdc++.h>
#define y1 nd03dnqwuidg1odbnw9uddu0132d
#define EPS 1e-9
#define MP make_pair
#define DEB(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 4294967296ll
//#define MAXN 1001
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

int n, carry, aux;
vector<int> DP[10005]; 

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j;
	
	DP[0].push_back(0);
	DP[1].push_back(1);
	DP[2].push_back(2);
	DP[3].push_back(4);
	DP[4].push_back(7);
	for (i=5; i<10005; i++) {
		carry = 0;
		j = 0;
		while (j < DP[i-1].size()) {
			aux = 0;
			if (DP[i-2].size() > j) aux += DP[i-2][j];
			aux += DP[i-1][j] + carry;
			DP[i].push_back(aux%10);
			carry = aux/10;
			j++;
		}
		if (carry == 1) DP[i].push_back(1);
	}
	while (cin>>n) {
		for (i=DP[n].size()-1; i>=0; i--) cout<<DP[n][i];
		cout<<"\n";
	}
	
	return 0;
}
