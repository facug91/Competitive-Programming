/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1350
        Name: Die Game
        Date: 31/12/2015
*/

#include <bits/stdc++.h>
#define move askudashgsdgaskdgsahdashk
#define endl "\n"
#define EPS 1e-2
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, mat[3][3];
string move;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j;
	
	while (cin>>n, n) {
		mat[1][1] = 1;
		mat[0][1] = 2;
		mat[1][0] = 3;
		mat[1][2] = 4;
		mat[2][1] = 5;
		while (n--) {
			cin>>move;
			switch (move[0]) {
				case 'w':
					mat[1][0] = mat[1][1];
					mat[1][1] = mat[1][2];
					mat[1][2] = 7 - mat[1][0];
					break;
				case 'e':
					mat[1][2] = mat[1][1];
					mat[1][1] = mat[1][0];
					mat[1][0] = 7 - mat[1][2];
					break;
				case 'n':
					mat[0][1] = mat[1][1];
					mat[1][1] = mat[2][1];
					mat[2][1] = 7 - mat[0][1];
					break;
				case 's':
					mat[2][1] = mat[1][1];
					mat[1][1] = mat[0][1];
					mat[0][1] = 7 - mat[2][1];
					break;
			}
		}
		cout<<mat[1][1]<<endl;
	}
	
	return 0;
}
